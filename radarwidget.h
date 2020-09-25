#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QMap>
#include <QVector>
#include "structdef.h"

class RadarStatusModel;
class HistoryRadarWidget;
class QListWidgetItem;

namespace Ui {
class RadarWidget;
}

class RadarWidget : public QWidget
{
    Q_OBJECT

public:
     RadarWidget(QWidget *parent = nullptr);
    ~RadarWidget();

    void init();
    //初始化信号槽
    void initConnect();
    //初始化雷达故障信息详细状态
    void initGroupBox(int row);
    //初始化雷达故障显示信息
    void initBreakRadarInfo();
    //初始化雷达实时显示信息
    void initRadarShowInfo();

    //雷达历史表右击事件
    bool eventFilter(QObject* obj, QEvent* evt);
    void closeEvent(QCloseEvent *event);

    //雷达实时信息处理
    void radarShowHandle(RadarInfoPtr radarInfo);
    //历史雷达信息处理
    void historyRadarShowHandle(RadarInfoPtr radarInfo);
    //雷达故障窗口信息处理
    void breakRadarShowHandle(RadarInfoPtr radarInfo);

    //获得雷达状态按钮样式表
    QString getBtnStyle(int breakStatus);
    //获取对应的故障
    QString getBreakMsg(unsigned char status);
    //获取故障类型
    BreakType getBreakType(unsigned char type);
    //获得故障值
   unsigned  char  getBreakStatus(BreakType breakType,RadarInfoPtr radarInfo);

    //创建不同类型的故障信息
    void addBreakRaderMsg(int breakType,RadarInfoPtr radarInfo);
    //判断故障状态
    void jujgeBreakStaus(BreakType breakType,RadarInfoPtr radarInfo);
    QString  getBreakListMsg(BreakRadarInfoPtr breakMsgInfo);
    //重新加载listWidget
    void updeListData(BreakRadarInfoPtr breakMsgInfo);
    //设置链路状态
    void setLlStatus(char llStatus);

signals:
    void rowDoubleSigle(int radarId);

public slots:

    void historyRadarSlot();
    void tableSingerSlot(const QModelIndex &index);
    void rowDoubleSlot(const QModelIndex &index);
    void itemSelectSlot(QListWidgetItem *item);
    //接收数据处理
    void radarDataHandle(const QByteArray& data);
    void relativeTable(int radarId);

private:

    Ui::RadarWidget*          ui;
    QMenu*                    m_menu;
    RadarStatusModel*         m_radarModel;
    HistoryRadarWidget*       m_historyRadarWidget;
    bool                      m_isOpen;
    char                      m_llStatus;
    //故障id,故障信息
    QMap<int,QString>         m_breakMsg;
    QMap<int, QMap<BreakType,BreakRadarInfoPtr>> m_breakMap;
};

#endif // RADARWIDGET_H
