#ifndef RADARDISPLAY_H
#define RADARDISPLAY_H
#include "viewarea.h"
#include <QMap>

//#include <protocol_33.h>
struct RadarDispData
{
    int     _nNum;
    QString _strName;
    QPointF  _ptPoisiton;
    int     _nWorkMode;
    int     _nAntanaStatus;
    QRectF  _rcImage;
    bool    _bChecked;

    RadarDispData(int nNum = 0,
                  QString strName = "defalut",
                  QPointF ptPoisiton = QPointF(100, 100),
                  int nWorkMode = 0,
                  int nAntanaStatus = 0)
    {
        _nNum = nNum;
        _strName = strName;
        _ptPoisiton = ptPoisiton;
        _nWorkMode = nWorkMode;
        _nAntanaStatus = nAntanaStatus;
        _rcImage = QRectF(0, 0, 10, 10);
        _bChecked = false;
    }
};

#define RADARDATA QMap<int,RadarDispData>


class RadarDisplay
{
public:
    RadarDisplay();
    ~RadarDisplay();
public:
    void paint(ViewArea* lpViewArea, void * lpdc, quint32 param=0);
    void addRadarData(RadarDispData &data);
    bool mouseClick(QPointF pt);
private:
    RADARDATA m_mapRadarData;
    QImage *m_pImage[3];
};

#include "painter.h"
class RadarPainter : public BasePainter
{
public:
    RadarPainter(RadarDisplay * lpRadarDisplay):m_lpRadarDisplay(lpRadarDisplay){}
    virtual ~RadarPainter(){}

    void paint(ViewArea* lpViewArea, void * lpdc, quint32 param=0)
    {
        m_lpRadarDisplay->paint(lpViewArea, lpdc, param);
    }

protected:
    RadarDisplay * m_lpRadarDisplay;
};

#include <memory>
class  RadarIntf
{
    DECL_SINGLETON_V2(RadarIntf)
public:
    //! 初始化
    bool initialize()
    {
        m_pRadarDisplay = std::make_shared<RadarDisplay>();
        return true;
    }

    //! 获取ZoneDisplay对象
    RadarDisplay* zoneDisplay() {    return m_pRadarDisplay.get(); }

    //! 创建ZonePainter对象
    RadarPainter* createPainter() {  return new RadarPainter(m_pRadarDisplay.get()); }

private:
    std::shared_ptr<RadarDisplay> m_pRadarDisplay;
};

#endif // RADARDISPLAY_H
