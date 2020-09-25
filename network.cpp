#include "network.h"

#include "asiolib.h"
#include "protocol.h"
#include "netdef.h"
#include "gconfig.h"

#include <QNetworkInterface>


bool Network::initialize()
{
    QString remoteAddress = QString("%1:%2").arg(GConfig::getInstance()->netip.c_str()).arg(GConfig::getInstance()->netport);
    if(remoteAddress.size()< 7)
    {
        return false;
    }
    const char * localEndPnt = "0.0.0.0:6000";
    qDebug() << QNetworkInterface::allAddresses();
    qDebug() << QNetworkInterface::allInterfaces();

    {
        SocketInfo info;
        info._index = quint8(1);
        info._flag = quint8(1);
        info._type = SocketInfo::_TcpClient;
        info._local  = EndPoint::fromString(localEndPnt);
        info._remote = EndPoint::fromString(remoteAddress.toStdString().c_str());
        AsioLib::instance()->addInfo(info, ItemInfo(1,"", "udp"));
    }

    {
        ProtoInfo info;
        info._index = quint8(1);
        info._deftf = true;
        AsioLib::instance()->addInfo(info, ItemInfo(1,"default", "default protocol"));
    }

    {
        EndPntInfo info;
        info._index = 1;
        info._socket = 1;
        info._endp = EndPoint::fromString("192.168.1.8:6001");
        info._proto = "default";
        AsioLib::instance()->addInfo(info, ItemInfo(1,"EndPnt", "EndPnt1"));
    }

    // 根据协议名称创建协议对象
    extern ProtocolPtr CreateProtocol(const QString& name);
    ProtocolCreator::instance()->setCreateFunc(&CreateProtocol);

    // 创建所有网络对象
    AsioLib::instance()->createAllObject();
    AsioLib::instance()->start(1);

    return true;
}

void Network::sendData(const QByteArray& data, int channel)
{
    AsioLib::instance()->dataSend(data, channel);
}
