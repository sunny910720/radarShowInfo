#include "historyradarwidget.h"
#include "ui_historyradarwidget.h"
#include<QDebug>
#include<QDateTime>
#include<QMessageBox>
#include<QSortFilterProxyModel>
#include "historyradarmodel.h"
#include "sqlitedatabase.h"

HistoryRadarWidget::HistoryRadarWidget(std::string radarName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryRadarWidget),
    m_rardarName(radarName)

{
    ui->setupUi(this);
    init();
}

HistoryRadarWidget::~HistoryRadarWidget()
{
    delete ui;
}

void HistoryRadarWidget::init()
{
    ui->dateTimeEdit_start->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_end->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_start->setDisplayFormat("yyyy/MM/dd HH:mm:ss");
    ui->dateTimeEdit_end->setDisplayFormat("yyyy/MM/dd HH:mm:ss");

    //m_historyRadarModel = new HistoryRadarModel(this);
    //ui->tableView->setModel(m_historyRadarModel);

    m_historyRadarModel = new HistoryRadarModel(ui->tableView);
    SortModel *proxy_model = new SortModel(this);
    //默认排序role应该是dispalyRole，我们可以修改
    proxy_model->setSortRole(Qt::InitialSortOrderRole);
    proxy_model->setSourceModel(m_historyRadarModel);
    ui->tableView->setModel(proxy_model);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setColumnWidth (0, 150);
    connect(ui->pushButton_qry,&QPushButton::clicked,this,&HistoryRadarWidget::qryBreakSlot);
}

void HistoryRadarWidget::qryBreakSlot()
{
    unsigned int startTime = ui->dateTimeEdit_start->dateTime().toTime_t();
    unsigned int endTime = ui->dateTimeEdit_end->dateTime().toTime_t();

    unsigned int currentTime = QDateTime::currentDateTime().toTime_t();
    if(startTime > currentTime || endTime > currentTime)
    {
        QMessageBox::warning(this,"温馨提示","查询的开始日期或结束日期大于当前时间");
        return;
    }
    if(endTime < startTime)
    {
        QMessageBox::critical(this,"错误提示","开始日期不能大于结束日期");
        return;
    }
//    int day = ui->dateTimeEdit_start->dateTime().daysTo(ui->dateTimeEdit_end->dateTime());
//    if(day > 31)
//    {
//        QMessageBox::warning(this,"温馨提示","查询的日期间隔不能大于一个月");
//        return;
//    }

    bool breakFlag=true;
    if(ui->checkBox->isChecked())
    {
        breakFlag = false;
    }
    //获取雷达历史信息
    QVector<HistroyRadarInfoPtr> radarVec;
    SqliteDataBase::getInstance()->queryAllHistoryRadarInfo(radarVec,m_rardarName,startTime,endTime,breakFlag);
    m_historyRadarModel->setHistoryRadarInfoVec(radarVec);
}

