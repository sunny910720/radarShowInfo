#ifndef DATADEF_H
#define DATADEF_H

#include <QObject>
#include <QPolygonF>

/*
雷达站信息
雷达型号、信号类型、波段、信号带宽、功率、经纬高

目标信息
目标类型、Swelliing、RCS、速度、<起始方位距离、结束方位距离>

干扰信息：
干扰模式、发射功率、干扰频带、速度、<起始方位距离、结束方位距离>
 */

#pragma pack(push, 1)

typedef struct WayPoint
{
    quint16 _azi;   // 单位360/65536
    quint32 _rng;   // 单位米
}WayPoint;

typedef struct DataHead
{
    quint16  _FFFF;
    quint16  _length;
    quint16  _label;
}DataHead;

typedef struct SiteInfo
{
    DataHead _head;
    quint8  _radarType;
    quint8  _signalType;
    quint16 _freqBand1;
    quint16 _freqBand2;
    quint16 _freqBandW;
    quint16 _power;
    quint32 _lon;
    quint32 _lat;
    quint16 _hgt;
}SiteInfo;

typedef struct TargetInfo
{
    DataHead _head;
    quint8  _targetType;
    quint8  _swelling;
    quint16 _rcs;
    quint16  _speed;
    WayPoint _wp[1];
}TargetInfo;

typedef struct JamInfo
{
    DataHead _head;
    quint8  _jamMode;
    quint8  _trPower;
    quint16 _jamBand1;
    quint16 _jamBand2;
    quint16  _speed;
    WayPoint _wp[1];
}JamInfo;

#pragma pack(pop)

#endif // DATADEF_H
