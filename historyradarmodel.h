#ifndef HISTORYRADARMODEL_H
#define HISTORYRADARMODEL_H

#include <QObject>
#include<QVector>
#include<QAbstractTableModel>
#include<QSortFilterProxyModel>
#include"structdef.h"

class HistoryRadarModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit HistoryRadarModel(QObject *parent = nullptr);

protected:

    int rowCount(const QModelIndex& /* = QModelIndex() */) const override;
    int columnCount(const QModelIndex& /* = QModelIndex() */) const override;
    QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */) const override;

signals:

public slots:

public:

    int  vecHistoryRadarInfoSize();
    void setHistoryRadarInfoVec(QVector<HistroyRadarInfoPtr> radarStVec);
    void insertHistoryRadarInfo(HistroyRadarInfoPtr radarSt);

private:
    QVector<HistroyRadarInfoPtr>   m_vecHitroyRadarInfo;
};

class SortModel : public QSortFilterProxyModel
{
public:

    explicit SortModel(QObject *parent = nullptr);

protected:

     bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const ;
};

#endif // HISTORYRADARMODEL_H
