#include "protocol.h"
#include "datadef.h"
#include "glb_format.h"
#include "glb_auxfunc.h"
#include "structdef.h"
#include "protocolop.h"
#include <QString>
#include <QtDebug>
#include <QTextCodec>

class ProtocolSC : public DataProtocol
{
public:
    ProtocolSC() = default;

    virtual bool process(const QByteArray& data, quint16 channel=0) override
    {

        if(!checkPacket(data))
        {
            return  false;
        }

        ProtocolOP::instance()->dataHandle(data);
        return true;
    }
    bool checkPacket(const QByteArray& data)
    {
        if(data.isEmpty())
        {
            return  false;
        }

        // 判断报文长度
        RADAR_STATE_PARAM  radarData;
        memcpy(&radarData,data.data(),sizeof(RADAR_STATE_PARAM));
        const int length = radarData.message_header.Message_Length_uh +1;
        if(length != data.size())
        {
            return  false;
        }

//         // 判断检查和
        if(GetCheckSum(data.constData(), length-1) != data.at(length-1))
        {
            return false;
        }

        return true;
    }
};

ProtocolPtr CreateProtocol(const QString& name)
{
    Q_UNUSED(name);
    return std::make_shared<ProtocolSC>();
}
