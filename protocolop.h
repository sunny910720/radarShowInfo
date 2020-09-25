#ifndef PROTOCOLOP_H
#define PROTOCOLOP_H

#include <QObject>
#include "structdef.h"
#include "glb_singleton.h"

class ProtocolOP : public QObject
{
    Q_OBJECT
   DECL_SINGLETON_V2(ProtocolOP)

public:
     void dataHandle(const QByteArray& data);
     void tableShowRadar(int radarId);

signals:
     void sendData(const QByteArray& data);
     void sendRadarData(int radarId);

public slots:
};

#endif // PROTOCOLOP_H
