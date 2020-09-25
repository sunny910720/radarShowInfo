#include "radarstatusmodel.h"
#include <QFont>
#include "sqlitedatabase.h"

RadarStatusModel::RadarStatusModel(QObject  *parent)
    : QAbstractTableModel(parent)
{

}

int RadarStatusModel::rowCount(const QModelIndex &) const
{
    return  m_vecRadarInfo.size();
}

int RadarStatusModel::columnCount(const QModelIndex &) const
{
    return 4;
}

QVariant RadarStatusModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row()>= m_vecRadarInfo.size() || index.row() < 0)
    {
        return QVariant();
    }
    RadarInfoPtr item = m_vecRadarInfo[index.row()];
    if(role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case 0:
            return QString::number(item->radarId);
        case 1:
            return QString(reinterpret_cast<char*>(item->radarName));
        case 2:
        {
            if(item->workStatus == 0)
            {
                return "工作";
            }
            else
            {
                return "待机";
            }
        }

        case 3:
        {
            if((item->antanaStatus == 1)&&(item->transStatus == 1)
                    &&(item->recivStatus == 1) &&(item->signalStatus == 1)
                    &&(item->terminalStatus == 1))
            {
                return "正常";
            }
            else
            {
                return "故障";
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

QVariant RadarStatusModel::headerData(int section, Qt::Orientation orientation, int role) const
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
            return "雷达站号";
        case 1:
            return "雷达名称";
        case 2:
            return "工作状态";
        case 3:
            return "故障状态";

        default:
            return QVariant();
        }
    }
    return QVariant();
}

int RadarStatusModel::getRadarId(int row)
{
    if(row < 0)
    {
        return  -1;
    }
    return m_vecRadarInfo[row]->radarId;
}

std::string RadarStatusModel::getRadarName(int row)
{
    if(row < 0)
    {
        return  "";
    }
    return  reinterpret_cast<char*>(m_vecRadarInfo[row]->radarName);
}

RadarInfoPtr RadarStatusModel::getRadarInfo(int row)
{
    if(row < 0)
    {
        return  nullptr;
    }
    return m_vecRadarInfo[row];
}

int RadarStatusModel::getTableRow(int radarId)
{
    for(int i=0;i<m_vecRadarInfo.size();i++)
    {
        if(m_vecRadarInfo[i]->radarId == radarId)
        {
            return i;
        }
    }
    return -1;
}

int RadarStatusModel::vecRadarInfoSize()
{
    return m_vecRadarInfo.size();
}

void RadarStatusModel::setRadarInfoVec(QVector<RadarInfoPtr> radarSt)
{
    m_vecRadarInfo = radarSt;
}

void RadarStatusModel::updateRadarInfo(RadarInfoPtr radarSt)
{
    if(nullptr == radarSt.get())
    {
        return ;
    }
    for(int i=0;i<m_vecRadarInfo.size();i++)
    {
        if(m_vecRadarInfo[i]->radarId == radarSt->radarId)
        {
            m_vecRadarInfo[i] = radarSt;
            emit dataChanged(index(i,0),index(i,3));
            SqliteDataBase::getInstance()->updateRadarInfoTable(radarSt);
            return;
        }
    }

    emit beginInsertRows(QModelIndex(), m_vecRadarInfo.size(), m_vecRadarInfo.size());
    m_vecRadarInfo.push_back(radarSt);
    emit endInsertRows();
    SqliteDataBase::getInstance()->insertRadarInfoTable(radarSt);
}

void RadarStatusModel::deleteRadarInfo(RadarInfoPtr radarSt)
{
    if(nullptr == radarSt.get())
    {
        return ;
    }

    int i= 0;
    for(auto it=m_vecRadarInfo.begin();it!= m_vecRadarInfo.end();)
    {

        if(m_vecRadarInfo.at(i)->radarId == radarSt->radarId)
        {
            emit beginRemoveRows(QModelIndex(), i, i);
            it = m_vecRadarInfo.erase(it);
            emit endRemoveRows();
            return;
        }
        else
        {
            ++it;
            ++i;
        }

    }
}

