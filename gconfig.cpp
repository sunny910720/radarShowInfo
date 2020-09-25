#include "gconfig.h"
#include <QSettings>
#include <QDebug>
#include "log.h"

GConfig::GConfig()
    :netip("")
    ,netport(0)
    ,dbip("")
    ,dbport(0)
    ,dbusername("")
    ,dbpassword("")
    ,dbname("")
    ,dbtype("")
{
 initConfig();
}

GConfig *GConfig::getInstance()
{
    static GConfig gfig;
    return &gfig;
}

void GConfig::initConfig()
{
   QSettings *configIni = new QSettings("./config/config.ini", QSettings::IniFormat);
   QStringList all = configIni->childGroups();
   if(all.size() > 0)
   {
       LogError(QObject::tr("读取配置文件成功"));
   }
   else
   {
      LogError(QObject::tr("读取配置文件失败"));
      return;
   }
   netip = configIni->value("network/netip").toString().toStdString();
   netport = configIni->value("network/netport").toInt();
   dbip = configIni->value("database/dbip").toString().toStdString();
   dbport = configIni->value("database/dbport").toInt();
   dbusername = configIni->value("database/dbusername").toString().toStdString();
   dbpassword = configIni->value("database/dbpassword").toString().toStdString();
   dbname = configIni->value("database/dbname").toString().toStdString();
   dbtype = configIni->value("database/dbtype").toString().toStdString();
}
