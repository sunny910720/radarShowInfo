#include "protocolop.h"

void ProtocolOP::dataHandle(const QByteArray& data)
{
    emit sendData(data);
}

void ProtocolOP::tableShowRadar(int radarId)
{
    emit sendRadarData(radarId);
}
