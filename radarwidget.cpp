#include "radarwidget.h"
#include <QDebug>
#include <QStringList>
#include <QDateTime>
#include "ui_radarwidget.h"
#include "radarstatusmodel.h"
#include "sqlitedatabase.h"
#include "historyradarwidget.h"
#include "radardisplay.h"
#include "protocolop.h"
#include "log.h"

RadarWidget::RadarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RadarWidget),
    m_radarModel(nullptr),
    m_historyRadarWidget(nullptr),
    m_isOpen(false),
    m_llStatus(0)
{
    ui->setupUi(this);
    init();
}

RadarWidget::~RadarWidget()
{
    delete ui;
    if(nullptr != m_historyRadarWidget)
    {
        delete  m_historyRadarWidget;
        m_historyRadarWidget = nullptr;
    }

    m_breakMap.clear();
    m_breakMsg.clear();
}

void RadarWidget::init()
{
    //设置菜单项,并连接槽函数
    m_menu =new QMenu(this);
    m_menu->addAction("查看历史雷达故障信息",this,SLOT(historyRadarSlot()));
    m_radarModel =new RadarStatusModel(this);

    //初始化雷达表格显示信息
    initRadarShowInfo();

    //初始化雷达状态显示信息
    if(m_radarModel->vecRadarInfoSize() > 0)
    {
        ui->tableView->selectRow(0);
        initGroupBox(0);
    }

    //初始化当前雷达故障显示信息
    initBreakRadarInfo();

    //初始化信号槽连接
    initConnect();
}

void RadarWidget::initConnect()
{

    qRegisterMetaType<RADAR_STATE_PARAM>("RADAR_STATE_PARAM");
    connect(ui->tableView,&QTableView::clicked,this,&RadarWidget::tableSingerSlot);
    connect(ui->tableView,&QTableView::doubleClicked,this,&RadarWidget::rowDoubleSlot);
    connect(ui->listWidget,&QListWidget::itemClicked,this,&RadarWidget::itemSelectSlot);
    connect(ProtocolOP::instance(),&ProtocolOP::sendData,this,&RadarWidget::radarDataHandle);
    connect(ProtocolOP::instance(),&ProtocolOP::sendRadarData,this,&RadarWidget::relativeTable);
}

void RadarWidget::initGroupBox(int row)
{
    RadarInfoPtr radarInfo = m_radarModel->getRadarInfo(row);
    if(nullptr == radarInfo)
    {
        LogError(QObject::tr("获取雷达信息为空"));
        return;
    }
    ui->groupBox->setTitle(QString("%1站号%2详细故障信息显示").arg(radarInfo->radarId).arg(reinterpret_cast<char*>(radarInfo->radarName)));
    if(radarInfo->antanaStatus == 0)
    {
        ui->pushButton_tx->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_tx->setStyleSheet(getBtnStyle(0));
    }

    if(radarInfo->transStatus == 0)
    {
        ui->pushButton_fsj->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_fsj->setStyleSheet(getBtnStyle(0));
    }

    if(radarInfo->recivStatus == 0)
    {
        ui->pushButton_js->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_js->setStyleSheet(getBtnStyle(0));
    }

    if(radarInfo->signalStatus == 0)
    {
        ui->pushButton_xhcl->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_xhcl->setStyleSheet(getBtnStyle(0));
    }
    if(radarInfo->terminalStatus == 0)
    {
        ui->pushButton_zd->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_zd->setStyleSheet(getBtnStyle(0));
    }
    //链路状态暂时未处理
    if(m_llStatus == 0)
    {
        ui->pushButton_ll->setStyleSheet(getBtnStyle(1));
    }
    else
    {
        ui->pushButton_ll->setStyleSheet(getBtnStyle(0));
    }

}

QString RadarWidget::getBtnStyle(int breakStatus)
{
    switch (breakStatus)
    {
    case ColorShow::GREEN:
        return QString("background:green;border:5px solid green;border-radius:15px");
    case ColorShow::RED:
        return QString("background:red;border:5px solid red;border-radius:15px");
    case ColorShow::YELLOW:
        return QString("background:yellow;border:5px solid yellow;border-radius:15px");
    default:
        return QString("");
    }
}

bool RadarWidget::eventFilter(QObject *obj, QEvent *evt)
{
    if(obj == ui->tableView && evt->type() == QEvent::ContextMenu)
    {
        if(ui->tableView->currentIndex().isValid()==true)
        {
            m_menu->exec(cursor().pos());           //在当前鼠标位置上运行菜单menu对象
        }
    }
    return QWidget::eventFilter(obj,evt);
}

void RadarWidget::closeEvent(QCloseEvent *event)
{
    if(m_isOpen)
    {
        m_historyRadarWidget->close();
    }
    return QWidget::closeEvent(event);
}

void RadarWidget::radarDataHandle(const QByteArray& data)
{
    RADAR_STATE_PARAM  msg;
    memcpy(&msg,data.data(),sizeof(RADAR_STATE_PARAM));

    RadarInfoPtr radarPtr(new RadarInfo);
    radarPtr->radarId=msg.Radar_StationNo;
    memcpy(radarPtr->radarName,msg.Radar_name,sizeof(msg.Radar_name));
    radarPtr->workStatus=msg.Launch_On;
    radarPtr->antanaStatus = msg.Antana_status;
    radarPtr->transStatus = msg.Trans_status;
    radarPtr->recivStatus = msg.Reciv_status;
    radarPtr->signalStatus = msg.Signal_status;
    radarPtr->terminalStatus =msg.Terminal_status;

    radarShowHandle(radarPtr);
    historyRadarShowHandle(radarPtr);
    breakRadarShowHandle(radarPtr);


    RadarDispData disData;
    disData._nNum=radarPtr->radarId;
    char radarName[50]={0};
    memcpy(radarName,radarPtr->radarName,sizeof(radarPtr->radarName));
    disData._strName = QString(radarName);
    disData._nWorkMode =radarPtr->workStatus;
    disData._nAntanaStatus =radarPtr->antanaStatus;
    RadarPositionInfoPtr postionPtr(new RadarPositionInfo);
    SqliteDataBase::getInstance()->queryRadarPosition(disData._nNum,postionPtr);

    if(postionPtr->radarId > 0)
    {
        postionPtr->lat=(double)(msg.Radar_StationNo/2)+26.5;
        postionPtr->lng=(double)(msg.Radar_StationNo/2)+110.5;
         SqliteDataBase::getInstance()->updateRadarPositionTable(postionPtr);
    }
    else
    {
        postionPtr->radarId = msg.Radar_StationNo;
        postionPtr->lat=(double)(msg.Radar_StationNo/2)+28.5;
        postionPtr->lng=(double)(msg.Radar_StationNo/2)+112.5;
        SqliteDataBase::getInstance()->insertRadarPositionTable(postionPtr);
    }

    disData._ptPoisiton=QPointF(postionPtr->lng,postionPtr->lat);

    RadarIntf::instance()->zoneDisplay()->addRadarData(disData);


}

void RadarWidget::radarShowHandle(RadarInfoPtr radarInfo)
{
    m_radarModel->updateRadarInfo(radarInfo);
    if(ui->tableView->currentIndex().row() >= 0)
    {

        initGroupBox(ui->tableView->currentIndex().row());
    }
    else
    {
        if(m_radarModel->vecRadarInfoSize() > 0)
        {
            ui->tableView->selectRow(0);
            initGroupBox(0);
        }
    }
}

void RadarWidget::historyRadarShowHandle(RadarInfoPtr radarInfo)
{
    HistroyRadarInfoPtr historyRadarSt(new HistroyRadarInfo);
    QDateTime current_date_time =QDateTime::currentDateTime();
    unsigned int timeT = current_date_time.toTime_t();
    historyRadarSt->breakTime=static_cast<int>(timeT);
    memcpy(historyRadarSt->radarName,radarInfo->radarName,sizeof(radarInfo->radarName));
    historyRadarSt->antanaStatus =radarInfo->antanaStatus;
    historyRadarSt->transStatus =radarInfo->transStatus;
    historyRadarSt->recivStatus =radarInfo->recivStatus;
    historyRadarSt->signalStatus =radarInfo->signalStatus;
    historyRadarSt->terminalStatus =radarInfo->terminalStatus;
    SqliteDataBase::getInstance()->insertHistoryRadarInfoTable(historyRadarSt);
}

void RadarWidget::breakRadarShowHandle(RadarInfoPtr radarInfo)
{
    jujgeBreakStaus(BreakType::ANTANA,radarInfo);
    jujgeBreakStaus(BreakType::TRANS,radarInfo);
    jujgeBreakStaus(BreakType::RECIV,radarInfo);
    jujgeBreakStaus(BreakType::SIGNALT,radarInfo);
    jujgeBreakStaus(BreakType::TERMINAL,radarInfo);
}

QString RadarWidget::getBreakMsg(unsigned char status)
{
    if(status == 1)
    {
        return "天线故障";
    }
    else if(status == 2)
    {
        return "发射机故障";
    }
    else if(status == 3)
    {
        return "接收故障";
    }
    else if(status == 4)
    {
        return "信号故障";
    }
    else if(status == 5)
    {
        return "终端故障";
    }
    else{
        return "未知故障";
    }
}

BreakType RadarWidget::getBreakType(unsigned char type)
{
    if(type==1)
    {
        return BreakType::ANTANA;
    }
    else if(type==2)
    {
        return BreakType::TRANS;
    }
    else if(type==3)
    {
        return BreakType::RECIV;
    }
    else if(type==4)
    {
        return BreakType::SIGNALT;
    }
    else
    {
        return BreakType::TERMINAL;
    }
}

unsigned char RadarWidget::getBreakStatus(BreakType breakType,RadarInfoPtr radarInfo)
{
    unsigned char breakStatus=0;
    switch (breakType)
    {
    case BreakType::ANTANA:
    {
        breakStatus= radarInfo->antanaStatus;
        break;
    }
    case BreakType::TRANS:
    {
        breakStatus= radarInfo->transStatus;
        break;
    }
    case BreakType::RECIV:
    {
        breakStatus= radarInfo->recivStatus;
        break;
    }
    case BreakType::SIGNALT:
    {
        breakStatus= radarInfo->signalStatus;
        break;
    }
    case BreakType::TERMINAL:
    {
        breakStatus= radarInfo->terminalStatus;
        break;
    }
    }
    return breakStatus;
}


void RadarWidget::addBreakRaderMsg(int breakType,RadarInfoPtr radarInfo)
{
    BreakRadarInfoPtr breakRadarPtr(new BreakRadarInfo);
    breakRadarPtr->id = SqliteDataBase::getInstance()->queryMaxBreakRadarId();

    QDateTime current_date_time =QDateTime::currentDateTime();
    unsigned int timeT = current_date_time.toTime_t();
    breakRadarPtr->breakStatus =0;
    breakRadarPtr->startTime =static_cast<int>(timeT);
    breakRadarPtr->radarId =radarInfo->radarId;
    memcpy(breakRadarPtr->radarName,radarInfo->radarName,sizeof(radarInfo->radarName)-1);

    switch (breakType)
    {
    case BreakType::ANTANA:
    {
        breakRadarPtr->breakType =1;
        m_breakMap[radarInfo->radarId][BreakType::ANTANA]=breakRadarPtr;
        break;
    }
    case BreakType::TRANS:
    {
        breakRadarPtr->breakType =2;
        m_breakMap[radarInfo->radarId][BreakType::TRANS]=breakRadarPtr;
        break;
    }
    case BreakType::RECIV:
    {
        breakRadarPtr->breakType =3;
        m_breakMap[radarInfo->radarId][BreakType::RECIV]=breakRadarPtr;
        break;
    }
    case BreakType::SIGNALT:
    {
        breakRadarPtr->breakType =4;
        m_breakMap[radarInfo->radarId][BreakType::SIGNALT]=breakRadarPtr;
        break;
    }
    case BreakType::TERMINAL:
    {
        breakRadarPtr->breakType =5;
        m_breakMap[radarInfo->radarId][BreakType::TERMINAL]=breakRadarPtr;
        break;
    }
    default:
        return ;
    }
    //添加新的故障信息
    SqliteDataBase::getInstance()->insertBreakRadarInfo(breakRadarPtr);
    QString newBreakMsg = getBreakListMsg(breakRadarPtr);
    ui->listWidget->addItem(newBreakMsg);
    m_breakMsg[breakRadarPtr->id]=newBreakMsg;
}

void RadarWidget::jujgeBreakStaus(BreakType breakType, RadarInfoPtr radarInfo)
{
    auto iterFind = m_breakMap.find(radarInfo->radarId);
    if(iterFind != m_breakMap.end())
    {
        auto iterTx = iterFind.value().find(breakType);
        //判断故障状态
        unsigned char breakStatus=getBreakStatus(breakType,radarInfo);
        if(iterTx != iterFind.value().end())
        {
            if(breakStatus != iterTx.value()->breakStatus)
            {
                iterTx.value()->breakStatus = breakStatus;
                QDateTime current_date_time =QDateTime::currentDateTime();
                unsigned int timeT = current_date_time.toTime_t();
                iterTx.value()->endTime = static_cast<int>(timeT);
                iterTx.value()->isdel=1;

                //更新数据库和缓存
                SqliteDataBase::getInstance()->updateBreakRadarInfo(iterTx.value());
                //m_breakMap[radarInfo->radarId][breakType]=iterTx.value();

                //重写加载listWiget内容
                updeListData(iterTx.value());

                //从数据库和缓存中删除
                //SqliteDataBase::getInstance()->delBreakRadarInfo(iterTx.value()->id);
                m_breakMap[radarInfo->radarId].erase(iterTx);
            }
        }
        else
        {   //如果是故障信息，插入数据库和缓存
            if(breakStatus == 0)
            {
                addBreakRaderMsg(breakType,radarInfo);
            }
        }
    }
    else
    {
        if(radarInfo->antanaStatus == 0)
        {
            addBreakRaderMsg(BreakType::ANTANA,radarInfo);
        }
        if(radarInfo->transStatus == 0)
        {
            addBreakRaderMsg(BreakType::TRANS,radarInfo);
        }
        if(radarInfo->recivStatus == 0)
        {
            addBreakRaderMsg(BreakType::RECIV,radarInfo);
        }
        if(radarInfo->signalStatus == 0)
        {
            addBreakRaderMsg(BreakType::SIGNALT,radarInfo);
        }
        if(radarInfo->terminalStatus == 0)
        {
            addBreakRaderMsg(BreakType::TERMINAL,radarInfo);
        }
    }
}

QString RadarWidget::getBreakListMsg(BreakRadarInfoPtr breakMsgInfo)
{
    //新增一条新数据
    QString radarInfo="开始时间：";
    QDateTime startTime = QDateTime::fromTime_t(static_cast<uint>(breakMsgInfo->startTime));
    radarInfo += startTime.toString("yyyy-MM-dd hh:mm:ss");
    radarInfo +="  [";
    radarInfo += QString::number(breakMsgInfo->radarId);
    radarInfo +="]  ";
    radarInfo += QString(reinterpret_cast<char*>(breakMsgInfo->radarName));
    radarInfo +="  ";
    radarInfo += getBreakMsg(breakMsgInfo->breakType);
    radarInfo +="  ";
    if(breakMsgInfo->isdel == 1)
    {
        QDateTime endTime = QDateTime::fromTime_t(static_cast<uint>(breakMsgInfo->endTime));
        radarInfo +=" 结束时间：";
        radarInfo +=endTime.toString("yyyy-MM-dd hh:mm:ss");
    }

    return  radarInfo;
}

void RadarWidget::updeListData(BreakRadarInfoPtr breakMsgInfo)
{
    auto iter = m_breakMsg.find(breakMsgInfo->id);
    if(iter != m_breakMsg.end())
    {
        //删除旧的故障内容
        QList<QListWidgetItem *> list = ui->listWidget->findItems(iter.value(),Qt::MatchStartsWith);
        QListWidgetItem* sel = list[0];
        int row = ui->listWidget->row(sel);
        QListWidgetItem* item = ui->listWidget->takeItem(row);
        ui->listWidget->removeItemWidget(item);
        delete item;
        m_breakMsg.erase(iter);

        //插入解除故障内容
        QString newBreakMsg = getBreakListMsg(breakMsgInfo);
        ui->listWidget->addItem(newBreakMsg);

        //更新故障信息
        //m_breakMsg[breakMsgInfo->id] = newBreakMsg;
    }
}

void RadarWidget::setLlStatus(char llStatus)
{
    m_llStatus =llStatus;
}

void RadarWidget::historyRadarSlot()
{
    int radarId = ui->tableView->currentIndex().row();
    std::string radarName = m_radarModel->getRadarName(radarId);
    m_historyRadarWidget =new HistoryRadarWidget(radarName);
    m_historyRadarWidget->showNormal();
    m_isOpen = true;
}

void RadarWidget::tableSingerSlot(const QModelIndex &index)
{
    if(index.row()>= 0)
    {
        initGroupBox(index.row());
    }
}

void RadarWidget::rowDoubleSlot(const QModelIndex &index)
{
    RadarInfoPtr radarPtr = m_radarModel->getRadarInfo(index.row());
    RadarDispData data;
    data._nNum=radarPtr->radarId;
    char radarName[50]={0};
    memcpy(radarName,radarPtr->radarName,sizeof(radarPtr->radarName));
    data._strName = QString(radarName);
    data._nWorkMode =radarPtr->workStatus;
    data._nAntanaStatus =radarPtr->antanaStatus;
    RadarPositionInfoPtr postionPtr(new RadarPositionInfo);
    SqliteDataBase::getInstance()->queryRadarPosition(data._nNum,postionPtr);
    data._ptPoisiton=QPointF(postionPtr->lng,postionPtr->lat);

    RadarIntf::instance()->zoneDisplay()->addRadarData(data);

}

void RadarWidget::initBreakRadarInfo()
{
    QVector<BreakRadarInfoPtr> radarVec;
    SqliteDataBase::getInstance()->queryAllBreakRadarInfo(radarVec);
    QStringList radarList;
    for(int i=0;i<radarVec.size();i++)
    {
        QString radarInfo = getBreakListMsg(radarVec[i]);
        radarList<< radarInfo;
        if(radarVec[i]->isdel == 0)
        {
            //初始化故障list信息缓存
            m_breakMsg[radarVec[i]->id]=radarInfo;
            //初始化故障信息缓存
            BreakType type =getBreakType(radarVec[i]->breakType);
            m_breakMap[radarVec[i]->radarId][type] = radarVec[i];
        }
    }
    ui->listWidget->addItems(radarList);
}

void RadarWidget::initRadarShowInfo()
{
    QVector<RadarInfoPtr> radarVec;
    SqliteDataBase::getInstance()->queryAllRadarInfo(radarVec);
    m_radarModel->setRadarInfoVec(radarVec);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setModel(m_radarModel);
    ui->tableView->installEventFilter(this);
    for(int i=0;i<radarVec.size();i++)
    {
        RadarInfoPtr radarPtr =radarVec[i];
        RadarDispData data;
        data._nNum=radarPtr->radarId;
        char radarName[50]={0};
        memcpy(radarName,radarPtr->radarName,sizeof(radarPtr->radarName));
        data._strName = QString(radarName);
        data._nWorkMode =radarPtr->workStatus;
        data._nAntanaStatus =radarPtr->antanaStatus;
        RadarPositionInfoPtr postionPtr(new RadarPositionInfo);
        SqliteDataBase::getInstance()->queryRadarPosition(data._nNum,postionPtr);
        data._ptPoisiton=QPointF(postionPtr->lng,postionPtr->lat);

        RadarIntf::instance()->zoneDisplay()->addRadarData(data);

    }
}

void RadarWidget::relativeTable(int radarId)
{
    int row = m_radarModel->getTableRow(radarId);
    if(row == -1)
    {
        qDebug()<<"找不到对应的雷达站号："<<radarId;
    }

    ui->tableView->selectRow(row);
    initGroupBox(row);
}

void RadarWidget::itemSelectSlot(QListWidgetItem *item)
{
    QString selectStr = item->text();
    int startIndex = selectStr.indexOf('[');
    int endIndex = selectStr.indexOf(']');
    QString radarId = selectStr.mid(startIndex+1,endIndex-startIndex-1);
    relativeTable(radarId.toInt());

}
