#ifndef STRUCTDEF_H
#define STRUCTDEF_H

#include<string>
#include<memory>

enum ColorShow : int
{
    GREEN,
    RED,
    YELLOW
};
enum BreakType:int
{
    ANTANA,
    TRANS,
    RECIV,
    SIGNALT,
    TERMINAL
};
struct RadarInfo
{
    RadarInfo()
    {
      memset(this,0,sizeof(*this));
    }

    unsigned short        radarId;         //雷达站号
    unsigned char         radarName[50];   //雷达名称
    unsigned char         workStatus;      //发射状态    0：发射关 1：发射开
    unsigned char         antanaStatus;    //天线状态    0:故障   1：正常
    unsigned char         transStatus;     //发射机状态  0:故障   1：正常
    unsigned char         recivStatus;     //接收状态    0:故障   1：正常
    unsigned char         signalStatus;    //信号状态    0:故障   1：正常
    unsigned char         terminalStatus;  //终端状态    0:故障   1：正常
};

typedef  std::shared_ptr<RadarInfo>   RadarInfoPtr;

struct HistroyRadarInfo
{
    HistroyRadarInfo()
    {
     memset(this,0,sizeof(*this));
    }

    int                    breakTime;
    unsigned char          radarName[50];
    unsigned char          antanaStatus;   //天线状态    0:故障   1：正常
    unsigned char          transStatus;    //发射机状态  0:故障   1：正常
    unsigned char          recivStatus;    //接收状态    0:故障   1：正常
    unsigned char          signalStatus;   //信号状态    0:故障   1：正常
    unsigned char          terminalStatus; //终端状态    0:故障   1：正常
};
typedef  std::shared_ptr<HistroyRadarInfo>   HistroyRadarInfoPtr;

struct BreakRadarInfo
{
    BreakRadarInfo()
    {
     memset(this,0,sizeof(*this));
    }

    int                      id;
    unsigned short           radarId;            //雷达站号
    unsigned char            radarName[50];      //雷达名称
    int                      startTime;          //故障开始时间
    int                      endTime;            //故障结束时间
    unsigned char            breakType;          //故障状态 0    1天线状态 2发射机状态 3接收状态 4信号状态 5终端状态
    unsigned char            breakStatus;        //故障值  0 表示故障 1表示正常
    unsigned char            isdel;              //0表示未处理  1 已处理

};

typedef  std::shared_ptr<BreakRadarInfo>   BreakRadarInfoPtr;

struct RadarPositionInfo
{
    RadarPositionInfo()
        :radarId(-1)
        ,lng(0.000)
        ,lat(0.000)
    {

    }
    int                      radarId;                //雷达站号
    double                   lng;                   //经度
    double                   lat;                   //纬度
};

typedef  std::shared_ptr<RadarPositionInfo>   RadarPositionInfoPtr;

#pragma pack (push,1)

//内部协议报文头
/*消息头结构---12个字节*/
typedef struct MESSAGE_HEADER
{
    unsigned short int	Message_Length_uh;				/* 消息长度 2个字节*/

    unsigned short int	Message_SourseID_uh;			/* 源设备标识 2个字节*/

    unsigned short int	Message_DestinationID_uh;		/* 目的设备标识 2个字节*/

    unsigned int		Time_Tag_ul;		            /* 时间标签，可表示信息发送的时间或信息产生的时间或情报录取的第一时间，4个字节*/

    unsigned short int	Message_Code_be;  // : 12;		/* 消息代码 12位，位定义加枚举*/

}MESSAGE_HEADER;


//雷达状态信息   天线  发射机  接收  信号处理  终端
typedef struct RADAR_STATE_PARAM   //消息代码：ENUM_RADAR_STATE_PARAM
{
    MESSAGE_HEADER  message_header;
    unsigned char   Radar_name[50];    //雷达名称
    unsigned short  Radar_StationNo;   //雷达站号
    unsigned char   Launch_On;         //1：发射开   0：发射关
    unsigned char   Work_Mode;         //工作模式  0：     1：     2：      3：、
    unsigned char   Antana_status;    // 天线 0:故障   1：正常
    unsigned char   Trans_status;     // 发射机 0:故障   1：正常
    unsigned char   Reciv_status;     // 接收 0:故障   1：正常
    unsigned char   Signal_status;     // 信号处理 0:故障   1：正常
    unsigned char   Terminal_status;    // 终端 0:故障   1：正常

    //天线  发射机  接收  信号处理  终端
    //软件链路状态

}RADAR_STATE_PARAM;

#pragma pack (pop)

#endif // STRUCTDEF_H
