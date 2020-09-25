#ifndef GCONFIG_H
#define GCONFIG_H
#include <string>

class GConfig
{

private:
    GConfig();

public:
    static GConfig* getInstance();
    void initConfig();

public:

    std::string            netip;
    int                    netport;
    std::string            dbip;
    int                    dbport;
    std::string            dbusername;
    std::string            dbpassword;
    std::string            dbname;
    std::string            dbtype;
};

#endif // GCONFIG_H
