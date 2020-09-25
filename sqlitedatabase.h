#ifndef SQLITEDATABASE_H
#define SQLITEDATABASE_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include "structdef.h"

class SqliteDataBase
{
private:
    SqliteDataBase();

public:
    static SqliteDataBase* getInstance();
    ~SqliteDataBase();

public:
    void initData();                                                                     //初始化数据
    bool createConnection();                                                             //创建一个连接
    bool createRadarInfoTable();                                                         //创建雷达信息表
    bool createHistoryRadarInfoTable();                                                  //创建历史雷达信息表
    bool createRadarBreakTable();                                                        //创建雷达故障信息表
    bool createRadarPositonTable();                                                      //创建雷达位置信息表
    bool insertRadarInfoTable(RadarInfoPtr radarSt);                                     //插入雷达信息
    bool updateRadarInfoTable(RadarInfoPtr radarSt);                                     //更新雷达信息
    bool insertRadarPositionTable(RadarPositionInfoPtr radarPositionSt);                 //插入雷达位置信息
    bool updateRadarPositionTable(RadarPositionInfoPtr radarPositionSt);                 //更新雷达位置信息
    bool insertHistoryRadarInfoTable(HistroyRadarInfoPtr radarSt);                       //插入历史雷达信息
    bool queryAllRadarInfo(QVector<RadarInfoPtr>& radarVec);         //查询所有雷达信息
    bool queryAllHistoryRadarInfo(QVector<HistroyRadarInfoPtr>& radarVec,std::string radarName, unsigned int startTime,unsigned int endTime,bool isBreak =false);          //查询所有历史雷达信息
    bool insertBreakRadarInfo(BreakRadarInfoPtr breakRadarInSt);                         //插入雷达故障信息
    bool updateBreakRadarInfo(BreakRadarInfoPtr breakRadarInSt);                         //更新雷达故障信息
    bool delBreakRadarInfo(int id);                                                      //删除雷达故障信息
    bool queryAllBreakRadarInfo(QVector<BreakRadarInfoPtr>& breakRadarInVec);            //查询所有雷达故障信息
    bool queryRadarPosition(int radarId,RadarPositionInfoPtr& radarPositionSt);          //查询雷达位置信息
    int  queryMaxHistoryRadarId();
    int  queryMaxBreakRadarId();



private:
    static SqliteDataBase*  m_spliteDabate;
    QSqlDatabase            m_sqlDb;
};

#endif // SQLITEDATABASE_H
