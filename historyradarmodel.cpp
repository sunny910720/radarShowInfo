#include "historyradarmodel.h"
#include <QFont>
#include<QDateTime>
#include "sqlitedatabase.h"

HistoryRadarModel::HistoryRadarModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int HistoryRadarModel::rowCount(const QModelIndex &) const
{
    return  m_vecHitroyRadarInfo.size();
}

int HistoryRadarModel::columnCount(const QModelIndex &) const
{
    return  3;
}

QVariant HistoryRadarModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        {
            return QVariant();
        }
        if(index.row()>= m_vecHitroyRadarInfo.size() || index.row() < 0)
        {
            return QVariant();
        }
        HistroyRadarInfoPtr item = m_vecHitroyRadarInfo[index.row()];
        if(role == Qt::DisplayRole)
        {
            switch(index.column())
            {
            case 0:
            {
                QDateTime time = QDateTime::fromTime_t(static_cast<uint>(item->breakTime));
                QString current_date =time.toString("yyyy-MM-dd hh:mm:ss");
                return current_date;
             }

            case 1:
                    return QString(reinterpret_cast<char*>(item->radarName));
            case 2:
            {
                if((item->antanaStatus == 1)&&(item->transStatus == 1)
                        &&(item->recivStatus == 1) &&(item->signalStatus == 1)
                        &&(item->terminalStatus == 1))
                {
                     return "正常";
                }
                else
                {
                    QString breakMsg = "";
                    if(item->antanaStatus == 0)
                    {
                        breakMsg += "[天线故障] ";
                    }
                    if(item->transStatus == 0)
                    {
                        breakMsg += "[发射机故障] ";
                    }
                    if(item->recivStatus == 0)
                    {
                       breakMsg += "[接收故障] ";
                    }
                    if(item->signalStatus == 0)
                    {
                        breakMsg += "[信号故障] ";
                    }
                    if(item->terminalStatus == 0)
                    {
                        breakMsg += "[终端故障] ";
                    }

                    return  breakMsg;
                }
            }

            default:
                return QVariant();
            }
        }
        if (role == Qt::TextAlignmentRole)
        {
            switch (index.column())
            {
            case 0:
            case 1:
            case 2:
                return (Qt::AlignVCenter + Qt::AlignLeft);
            default:
                return Qt::AlignLeft + Qt::AlignVCenter;
            }
        }
        return QVariant();
}

QVariant HistoryRadarModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::TextAlignmentRole)
       {
           switch (section)
           {
           case 0:
           case 1:
           case 2:
               return (Qt::AlignVCenter + Qt::AlignLeft);
           default:
               return (Qt::AlignVCenter + Qt::AlignLeft);
           }
       }

       if (role != Qt::DisplayRole)
       {
           return QVariant();
       }
       if (orientation == Qt::Horizontal)
       {
           switch (section)
           {
           case 0:
               return "时间";
           case 1:
               return "雷达名称";
           case 2:
               return "故障";
           default:
               return QVariant();
           }
       }
       return QVariant();
}


int HistoryRadarModel::vecHistoryRadarInfoSize()
{
    return  m_vecHitroyRadarInfo.size();
}

void HistoryRadarModel::setHistoryRadarInfoVec(QVector<HistroyRadarInfoPtr> radarStVec)
{
    while(m_vecHitroyRadarInfo.size())
    {
        emit beginRemoveRows(QModelIndex(), 0, 0);
        m_vecHitroyRadarInfo.pop_front();
        emit endRemoveRows();
    }

    for(int j =0;j<radarStVec.size();j++)
    {
       insertHistoryRadarInfo(radarStVec[j]);
    }
}

void HistoryRadarModel::insertHistoryRadarInfo(HistroyRadarInfoPtr radarSt)
{
  emit beginInsertRows(QModelIndex(), m_vecHitroyRadarInfo.size(), m_vecHitroyRadarInfo.size());
  m_vecHitroyRadarInfo.push_back(radarSt);
  emit endInsertRows();
}



SortModel::SortModel(QObject *parent)
    :QSortFilterProxyModel (parent)
{

}

bool SortModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    if (!source_left.isValid() || !source_right.isValid())
            return false;

     if ((source_left.column() == 0) && (source_right.column() == 0))
     {
         QVariant leftData = sourceModel()->data(source_left);
         QVariant rightData = sourceModel()->data(source_right);
        if(QString::compare(leftData.toString(),rightData.toString()) < 0)
         {
            return true;
         }
        if(QString::compare(leftData.toString(),rightData.toString()) > 0)
         {
            return false;
         }
     }

     return QSortFilterProxyModel::lessThan(source_left, source_right);
}

