#ifndef NETWORK_H
#define NETWORK_H

#include "glb_singleton.h"

class Network
{
    DECL_SINGLETON_V2(Network)
public:
    //Network();

    bool initialize();
    void sendData(const QByteArray& data, int channel = 1);
};

#endif // NETWORK_H
