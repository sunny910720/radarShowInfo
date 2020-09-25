#include "sqlitedatabase.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include "gconfig.h"
#include "log.h"

SqliteDataBase* SqliteDataBase::m_spliteDabate = new SqliteDataBase();

SqliteDataBase::SqliteDataBase()
{

}

SqliteDataBase* SqliteDataBase::getInstance()
{
    return m_spliteDabate;
}

SqliteDataBase::~SqliteDataBase()
{
    m_sqlDb.close();
    if(nullptr !=m_spliteDabate)
    {
        delete m_spliteDabate;
        m_spliteDabate = nullptr;
    }
}

bool SqliteDataBase::createConnection()
{
    //以后就可以用"sqlite"与数据库进行连接了
    m_sqlDb= QSqlDatabase::addDatabase(GConfig::getInstance()->dbtype.c_str());
    m_sqlDb.setHostName(GConfig::getInstance()->dbip.c_str());
    m_sqlDb.setPort(GConfig::getInstance()->dbport);
    m_sqlDb.setUserName(GConfig::getInstance()->dbusername.c_str());
    m_sqlDb.setPassword(GConfig::getInstance()->dbpassword.c_str());
    m_sqlDb.setDatabaseName(GConfig::getInstance()->dbname.c_str());


    if (!m_sqlDb.open())
    {
        LogError(QObject::tr("无法建立数据库连接"));
        return false;
    }

    return true;
}

void SqliteDataBase::initData()
{
    if(createConnection())
    {
        createRadarInfoTable();
        createHistoryRadarInfoTable();
        createRadarBreakTable();
        createRadarPositonTable();
    }
}

bool SqliteDataBase::createRadarInfoTable()
{
    QSqlQuery query(m_sqlDb);
    bool success = query.exec("create table if not exists radarInfo(id int primary key,radarName varchar(50),"
                              "workStatus int,breakStatus varchar(5))");

    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达信息表创建失败！")+lastError.driverText());
        return false;

    }
    return true;
}

bool SqliteDataBase::createHistoryRadarInfoTable()
{
    QSqlQuery query(m_sqlDb);
    bool success = query.exec("create table if not exists historyradarInfo(id int  primary key,breakTime int,"
                              "radarName varchar(50),breakMsg varchar(5))");

    if (!success)
    {
        LogError(QObject::tr("雷达历史信息表创建失败！"));
        return false;
    }

    return true;
}

bool SqliteDataBase::createRadarBreakTable()
{
    QSqlQuery query(m_sqlDb);
    bool success = query.exec("create table if not exists radarbreakInfo(id int primary key,radrId int ,radarName varchar(50),"
                              " breakType int,breakStatus int, startTime int,endTime int,isdel int )");

    if (!success)
    {
        LogError(QObject::tr("雷达故障信息表创建失败！"));
        return false;
    }
    return true;
}

bool SqliteDataBase::createRadarPositonTable()
{
    QSqlQuery query(m_sqlDb);
    bool success = query.exec("create table if not exists radarpositionInfo(id int primary key,lng double(15,6) ,lat double(15,6) )");

    if (!success)
    {
        LogError(QObject::tr("雷达位置信息表创建失败！"));
        return false;
    }

     return true;
}

bool SqliteDataBase::insertRadarInfoTable(RadarInfoPtr radarSt)
{
    QSqlQuery query(m_sqlDb);
    query.prepare("insert into radarInfo values(?, ?, ?, ?)");

    QString breakMsg ="";
    breakMsg[0]=radarSt->antanaStatus+'0';
    breakMsg[1]=radarSt->transStatus+'0';
    breakMsg[2]=radarSt->recivStatus+'0';
    breakMsg[3]=radarSt->signalStatus+'0';
    breakMsg[4]=radarSt->terminalStatus+'0';

    query.bindValue(0, radarSt->radarId);
    query.bindValue(1, QString(reinterpret_cast<char*>(radarSt->radarName)));
    query.bindValue(2, radarSt->workStatus);
    query.bindValue(3,breakMsg);


    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达信息表插入失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::updateRadarInfoTable(RadarInfoPtr radarSt)
{
    QSqlQuery query(m_sqlDb);
    QString breakMsg ="";
    breakMsg[0]=radarSt->antanaStatus +'0';
    breakMsg[1]=radarSt->transStatus+'0';
    breakMsg[2]=radarSt->recivStatus+'0';
    breakMsg[3]=radarSt->signalStatus+'0';
    breakMsg[4]=radarSt->terminalStatus+'0';

    query.prepare(QString("update radarInfo set workStatus =%1 ,breakStatus ='%2' where id = %3").arg(radarSt->workStatus)
                  .arg(breakMsg).arg(radarSt->radarId));

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达信息表更新失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::insertRadarPositionTable(RadarPositionInfoPtr radarPositionSt)
{
    QSqlQuery query(m_sqlDb);
    query.prepare("insert into radarpositionInfo values(?, ?, ?)");

    query.bindValue(0, radarPositionSt->radarId);
    query.bindValue(1, radarPositionSt->lng);
    query.bindValue(2, radarPositionSt->lat);

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达位置信息表插入失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::updateRadarPositionTable(RadarPositionInfoPtr radarPositionSt)
{
    QSqlQuery query(m_sqlDb);
    query.prepare(QString("update radarpositionInfo set lng =%1 ,lat =%2 where id = %3 ").arg(radarPositionSt->lng)
                  .arg(radarPositionSt->lat).arg(radarPositionSt->radarId));

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达位置信息表更新失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::insertHistoryRadarInfoTable(HistroyRadarInfoPtr radarSt)
{
    QSqlQuery query(m_sqlDb);

    QString breakMsg ="";
    breakMsg[0]=radarSt->antanaStatus+'0';
    breakMsg[1]=radarSt->transStatus+'0';
    breakMsg[2]=radarSt->recivStatus+'0';
    breakMsg[3]=radarSt->signalStatus+'0';
    breakMsg[4]=radarSt->terminalStatus+'0';

    query.prepare("insert into historyradarInfo values(?,?, ?, ?)");

    query.bindValue(0, queryMaxHistoryRadarId());
    query.bindValue(1, radarSt->breakTime);
    query.bindValue(2, QString(reinterpret_cast<char*>(radarSt->radarName)));
    query.bindValue(3, breakMsg);

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达历史信息表插入失败")+lastError.driverText());
        return false;
    }
    return true;
}


bool SqliteDataBase::queryAllRadarInfo(QVector<RadarInfoPtr>& radarVec)
{
    QSqlQuery query(m_sqlDb);
    QString querySql=QString("select * from radarInfo");
    query.exec(querySql);

    while (query.next())
    {
        RadarInfoPtr radarData(new RadarInfo);
        radarData->radarId = static_cast<unsigned short>(query.value(0).toInt());
        std::string name = query.value(1).toString().toStdString();
        memcpy(radarData->radarName,name.c_str(),sizeof(radarData->radarName));
        radarData->workStatus = static_cast<unsigned char>(query.value(2).toInt());
        std::string breakStatus= query.value(3).toString().toStdString();
        radarData->antanaStatus=static_cast<unsigned char>(breakStatus[0]-'0');
        radarData->transStatus=static_cast<unsigned char>(breakStatus[1]-'0');
        radarData->recivStatus=static_cast<unsigned char>(breakStatus[2]-'0');
        radarData->signalStatus=static_cast<unsigned char>(breakStatus[3]-'0');
        radarData->terminalStatus=static_cast<unsigned char>(breakStatus[4]-'0');

        radarVec.push_back(radarData);
    }

    return true;
}

bool SqliteDataBase::queryAllHistoryRadarInfo(QVector<HistroyRadarInfoPtr> &radarVec,std::string radarName,unsigned int startTime,unsigned int endTime,bool isBreak)
{
    QSqlQuery query(m_sqlDb);
    QString querySql="";
    if(isBreak)
    {
        querySql =QString("select * from historyradarInfo where radarName ='%1' and %2 < breakTime and %3 > breakTime and breakMsg like '%%4%'")
                .arg(radarName.c_str()).arg(startTime).arg(endTime).arg('0');
    }
    else
    {
        querySql =QString("select * from historyradarInfo where radarName ='%1' and %2 < breakTime and breakTime < %3  " ).arg(radarName.c_str()).arg(startTime).arg(endTime);
    }

    query.exec(querySql);

    while (query.next())
    {
        HistroyRadarInfoPtr radarData(new HistroyRadarInfo);
        radarData->breakTime = query.value(1).toInt();
        std::string name = query.value(2).toString().toStdString();
        memcpy(radarData->radarName,name.c_str(),sizeof (radarData->radarName));
        std::string breakStatus= query.value(3).toString().toStdString();
        radarData->antanaStatus=static_cast<unsigned char>(breakStatus[0]-'0');
        radarData->transStatus=static_cast<unsigned char>(breakStatus[1]-'0');
        radarData->recivStatus=static_cast<unsigned char>(breakStatus[2]-'0');
        radarData->signalStatus=static_cast<unsigned char>(breakStatus[3]-'0');
        radarData->terminalStatus=static_cast<unsigned char>(breakStatus[4]-'0');
        radarVec.push_back(radarData);
    }

    return true;
}

bool SqliteDataBase::insertBreakRadarInfo(BreakRadarInfoPtr breakRadarInSt)
{
    QSqlQuery query(m_sqlDb);
    query.prepare("insert into radarbreakInfo values(?,?, ?,?,?,?,?,?)");

    query.bindValue(0, breakRadarInSt->id);
    query.bindValue(1,breakRadarInSt->radarId);
    query.bindValue(2, QString(reinterpret_cast<char*>(breakRadarInSt->radarName)));
    query.bindValue(3, breakRadarInSt->breakType);
    query.bindValue(4,breakRadarInSt->breakStatus);
    query.bindValue(5, breakRadarInSt->startTime);
    query.bindValue(6, breakRadarInSt->endTime);
    query.bindValue(7, breakRadarInSt->isdel);

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达故障信息表插入失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::updateBreakRadarInfo(BreakRadarInfoPtr breakRadarInSt)
{
    QSqlQuery query(m_sqlDb);
    query.prepare(QString("update radarbreakInfo set breakType =%1,breakStatus=%2 ,endTime =%3,isdel=%4 where id = %5").arg(breakRadarInSt->breakType)
                  .arg(breakRadarInSt->breakStatus).arg(breakRadarInSt->endTime).arg(breakRadarInSt->isdel).arg(breakRadarInSt->id));

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达故障信息表更新失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::delBreakRadarInfo(int id)
{
    QSqlQuery query(m_sqlDb);
    query.prepare(QString("delete from radarbreakInfo where id =%1 ").arg(id));

    bool success = query.exec();
    if (!success)
    {
        QSqlError lastError = query.lastError();
        LogError(QObject::tr("雷达故障信息表删除失败")+lastError.driverText());
        return false;
    }
    return true;
}

bool SqliteDataBase::queryAllBreakRadarInfo(QVector<BreakRadarInfoPtr>& breakRadarInVec)
{
    QSqlQuery query(m_sqlDb);
    query.exec("select * from radarbreakInfo");

    while (query.next())
    {
        BreakRadarInfoPtr radarData(new BreakRadarInfo);
        radarData->id = query.value(0).toInt();
        radarData->radarId =static_cast<unsigned short>(query.value(1).toInt());
        std::string name = query.value(2).toString().toStdString();
        memcpy(radarData->radarName,name.c_str(),sizeof (radarData->radarName));
        radarData->breakType =static_cast<unsigned char>(query.value(3).toInt());
        radarData->breakStatus =static_cast<unsigned char>(query.value(4).toInt());
        radarData->startTime =query.value(5).toInt();
        radarData->endTime =query.value(6).toInt();
        radarData->isdel =static_cast<unsigned char>(query.value(7).toInt());

        breakRadarInVec.push_back(radarData);
    }

    return true;
}

bool SqliteDataBase::queryRadarPosition(int radarId, RadarPositionInfoPtr &radarPositionSt)
{
    QSqlQuery query(m_sqlDb);
    QString querySql=QString("select *  from radarpositionInfo where id =%1 ").arg(radarId);
    query.exec(querySql);

    while (query.next())
    {
        radarPositionSt->radarId = query.value(0).toInt();
        radarPositionSt->lng = query.value(1).toDouble();
        radarPositionSt->lat = query.value(2).toDouble();
    }

    return true;
}

int SqliteDataBase::queryMaxHistoryRadarId()
{
    QSqlQuery query(m_sqlDb);
    query.exec("select max(id) from historyradarInfo");

    while (query.next())
    {
        int  t_max =query.value(0).toInt();
        return t_max+1;
    }

    return 0;
}

int SqliteDataBase::queryMaxBreakRadarId()
{
    QSqlQuery query(m_sqlDb);
    query.exec("select max(id) from radarbreakInfo");

    while (query.next())
    {
        int  t_max =query.value(0).toInt();
        return t_max+1;
    }

    return 0;
}


