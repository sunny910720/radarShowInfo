#ifndef RADARSTATUSMODEL_H
#define RADARSTATUSMODEL_H

#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "structdef.h"

class RadarStatusModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    explicit RadarStatusModel(QObject  *parent);

protected:

    int rowCount(const QModelIndex& /* = QModelIndex() */) const override;
    int columnCount(const QModelIndex& /* = QModelIndex() */) const override;
    QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */) const override;

signals:

public slots:

public:

    int  getRadarId(int row);
    std::string getRadarName(int row);
    RadarInfoPtr getRadarInfo(int row);
    int getTableRow(int radarId);
    int  vecRadarInfoSize();
    void setRadarInfoVec(QVector<RadarInfoPtr> radarSt);
    void updateRadarInfo(RadarInfoPtr radarSt);
    void deleteRadarInfo(RadarInfoPtr radarSt);

private:
    QVector<RadarInfoPtr>   m_vecRadarInfo;


};

#endif // RADARSTATUSMODEL_H
