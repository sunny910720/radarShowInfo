#include "radardisplay.h"
#include <QPainter>
#include <QCoreApplication>
#include "viewarea.h"
#include "protocolop.h"
#include <QRectF>

RadarDisplay::RadarDisplay()
{
    QString fileName = QCoreApplication::applicationDirPath();
    m_pImage[1] = new QImage(fileName + "/Image/radar_green.png");
    m_pImage[2] = new QImage(fileName + "/Image/radar_yellow.png");
    m_pImage[0] = new QImage(fileName + "/Image/radar_red.png");

//    RadarDispData data(2, "first", QPointF(113, 29), 0, 1);
//    RadarDispData data2(1, "secound", QPointF(113.1, 29.1), 0, 1);

//    addRadarData(data);
//    addRadarData(data2);
}

RadarDisplay::~RadarDisplay()
{
    for (int i = 0; i < 3; i++)
    {
        delete m_pImage[i];
    }
}

void RadarDisplay::paint(ViewArea* lpViewArea, void * lpdc, quint32 param)
{
    Q_UNUSED(param);
    QPainter * painter = (QPainter*)(lpdc);
    QPainter * painter2 = (QPainter*)(lpdc);
    for (RADARDATA::iterator iter = m_mapRadarData.begin(); iter != m_mapRadarData.end(); iter++)
    {
        QPen pen;
        if(iter.value()._bChecked)
        {
            pen.setColor(QColor(0, 0, 255));
            pen.setStyle(Qt::DashLine);
            pen.setWidth(2);
        }

        painter->setPen(pen);
        QPoint pt = lpViewArea->latitude_to_screen(iter.value()._ptPoisiton);
        QRect rc = m_pImage[iter.value()._nAntanaStatus]->rect();
        rc.moveTopLeft(pt);
        iter.value()._rcImage = QRectF(rc);
        painter->drawImage(pt, *m_pImage[iter.value()._nAntanaStatus]);
        painter->drawRect(iter.value()._rcImage);

        painter->setPen(QColor(255, 255, 255));
        painter->drawText(QPointF(lpViewArea->latitude_to_screen(iter.value()._ptPoisiton).x(),
                                  lpViewArea->latitude_to_screen(iter.value()._ptPoisiton).y() + 60),
                          iter.value()._strName);
    }
}

void RadarDisplay::addRadarData(RadarDispData &data)
{
   RADARDATA::iterator iter = m_mapRadarData.find(data._nNum);
   if(iter != m_mapRadarData.end())
   {
       iter.value() = data;
   }
   else
   {
        m_mapRadarData.insert(data._nNum, data);
   }
}

bool RadarDisplay::mouseClick(QPointF pt)
{
    bool bFind = false;
    if(m_mapRadarData.size() > 0)
    {
        for (RADARDATA::iterator iter = m_mapRadarData.begin(); iter != m_mapRadarData.end(); iter++)
        {
            if(!bFind && iter.value()._rcImage.contains(pt))
            {
                iter.value()._bChecked = true;
                bFind = true;
                //iter.value()._nNum;
               ProtocolOP::instance()->tableShowRadar(iter.value()._nNum);
            }
            else
            {
                iter.value()._bChecked = false;
            }
        }
    }
    return bFind;
}



