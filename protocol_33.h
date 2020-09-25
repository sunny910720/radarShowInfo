#ifndef PROTOCOL_H
#define PROTOCOL_H

/*******************************************************************************
数据接入接出软件  COMM
一体化显示软件    OWS  （二维/三维态势显示  情报显示  状态监视  评估显示）
剧情制作软件      
算法库管理软件
雷达调度软件    Radar Dispatching
融合处理软件
融合评估软件
运行管理软件
***********************************************************************************/

#pragma pack (push,1)

typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned int   UINT;
typedef unsigned long  ULONG;
typedef short  SHORT;
//typedef bool   BOOL;
typedef double DOUBLE;
typedef long LONG;


//源id
enum CSCI_NAME_ID
{
	ENUM_PPN_ID = 1,  //剧情制作
	ENUM_DBM_ID,  //数据库管理
	ENUM_SDN_ID,  //仿真推演
	ENUM_OWS_ID,  //态势显示
	ENUM_DET_ID,  //雷达模拟器中的detect
	ENUM_TRK_ID,  //雷达模拟器中的trk
	ENUM_RFP_ID,  //融合处理    FEP
	ENUM_FEP_ID,  //融合评估
	ENUM_EDN_ID,  //评估显示
	ENUM_RSN_ID,   //雷达模拟器

	ENUM_ADBM_ID, //算法库管理软件
	ENUM_RDM_ID,  //雷达调度软件
	ENUM_MAX
};

/*OWS提供的工作模式*/ 
typedef enum ENUM_OWS_WORK_MODE_E
{
	OWS_WORKMODE_NULL 			     = 0x00,			// 无效
	OWS_WORKMODE_FAR				 = 0x01,			//多任务模式
	OWS_WORKMODE_NORMAL   	         = 0x02,			//低慢小模式
	OWS_WORKMODE_EMPTY_BURST         = 0x03,           //空波束
	OWS_WORKMODE_TRACK               = 0x04,           //跟踪模式
	OWS_WORKMODE_SILENT              = 0x05,           //静默扇区
	OWS_WORKMODE_FAR_COVER			 = 0x06,			//多任务掩护模式
	OWS_WORKMODE_NORMAL_COVER   	 = 0x07,			//低慢小掩护模式
	OWS_WORKMODE_FAR_LOW			 = 0x08,			//多任务中低空模式
	OWS_WORKMODE_FAR_HIGH			 = 0x09,			//多任务高空模式
	OWS_WORKMODE_NORMAL_LOW   	     = 0x0a,			//低慢小中低空模式
	OWS_WORKMODE_NORMAL_HIGH   	     = 0x0b,			//低慢小高空模式
	OWS_WORKMODE_STOP   	         = 0x0f,			//停止模式
}ENUM_OWS_WORK_MODE_E;

//内部协议报文头
/*消息头结构---12个字节*/
typedef struct MESSAGE_HEADER
{
	unsigned short int	Message_Length_uh;				/* 消息长度 2个字节*/

	unsigned short int	Message_SourseID_uh;			/* 源设备标识 2个字节*/

	unsigned short int	Message_DestinationID_uh;		/* 目的设备标识 2个字节*/

	unsigned int		Time_Tag_ul;		        /* 时间标签，可表示信息发送的时间或信息产生的时间或情报录取的第一时间，4个字节*/

	unsigned short int	Message_Code_be;  // : 12;			/* 消息代码 12位，位定义加枚举*/

//	unsigned short int	Message_Inquire_b : 1;			/* 查询位 1位*/

//	unsigned short int	Message_Command_b : 1;			/* 消息类型 1位*/

//	unsigned short int	Message_Feedback_b : 1;			/* 消息反馈标志 1位*/

//	unsigned short int	Message_Answer_b : 1;			/* 消息应答标志 1位*/

}MESSAGE_HEADER;



/****************************************************外接雷达协议***********************************************************************************/

/******************************************************************************************************************************************/
/* QDB82协议  1)雷达站址报文  2）目标航迹报文  */
/******************************************************************************************************************************************/
//空情信息     
//坐标
typedef struct COORDINATE_STRUCT
{
	union
	{
		//地理坐标
		struct
		{
			//经度低	单位秒
			UCHAR		LongitudeL		:	8;
			//经度中
			UCHAR		LongitudeM		:	8;
			//经度高
			UCHAR		LongitudeH				:	7;
			//标志 0东经1西经
			UCHAR		LongFlag			:	1;

			//纬度低	单位秒
			UCHAR		LatitudeL		:	8;
			//纬度中
			UCHAR		LatitudeM		:	8;
			//纬度高
			UCHAR		LatitudeH				:	7;
			//标志 0北纬1南纬
			UCHAR		LatFlag			:	1;
		}LongLat;

		//极坐标
		struct
		{
			//方位低	单位6000密位/1周 与正北顺时针夹角
			UCHAR		AzimuthL		:	8;
			//方位中
			UCHAR		AzimuthM		:	8;
			//方位高
			UCHAR		AzimuthH		:	8;

			//距离低	单位米
			UCHAR		RangeL		:	8;
			//距离中
			UCHAR		RangeM		:	8;
			//距离高
			UCHAR		RangeH		:	8;
		}PolorRadar;

		//直角坐标
		struct
		{
			//X坐标低	单位米
			UCHAR		XL		:	8;
			//X坐标中
			UCHAR		XM		:	8;
			//X坐标高
			UCHAR		XH				:	7;
			//X坐标标志 0正东1正西
			UCHAR		XFlag			:	1;

			//Y坐标低	单位秒
			UCHAR		YL		:	8;
			//Y坐标中
			UCHAR		YM		:	8;
			//Y坐标高
			UCHAR		YH				:	7;
			//Y坐标标志 0正南1正北
			UCHAR		YFlag			:	1;
		}Inertial;
	}coordinate;
}COORDINATE_STRUCT;

//录取时间和敌我属性
typedef struct TGT_TIMEATTR_STRUCT
{
	//录取时间 100ms单位
	unsigned short TargetTime	:	13;
	//敌我属性 000:不明	001:敌机	010:我机	011:友机
	unsigned short Attribute	:	3;
}TGT_TIMEATTR_STRUCT;

//高度
typedef struct TGT_HEIGHT_STRUCT
{
	//高度数值 单位米
	unsigned short Height	:	15;
	//高度符号位	0正值1负值	绝对高度以海平面为准	相对高度以侦察器材为准
	unsigned short HeightFlag	:	1;
}TGT_HEIGHT_STRUCT;

//机型与航迹质量
typedef struct TGT_TYPEQUALITY_STRUCT
{
	//机型 000000:不明 000001:小型机 000010:中型机 000011:大型机 000100:气球 000101:干扰 000110:积极干扰 000111:消极干扰 001000:干扰机 001001:快速目标
	//100000:轰炸机 100001:歼击机 100010:直升机 100011:侦察机 100100:巡航导弹 100101:运输机 1000110:民航机
	UCHAR TgtType	:	6;
	//航迹质量 0-3 3最高
	UCHAR TgtQuality	:	2;
}TGT_TYPEQUALITY_STRUCT;


//报类名称
typedef struct INFO_TYPE_STRUCT
{
	//信息交换方向 0指挥->侦察 1侦察->指挥
	UCHAR InfoDire	:	1;
	//报文类型 00空情01状态/控制命令10自由报文11气象报文
	UCHAR InfoType	:	2;
	//坐标类型	00地理01极坐标10直角坐标
	UCHAR CoorType	:	2;
	//高度类型 0绝对高度1相对高度
	UCHAR HeightType	:	1;
	//战术操作 1 消失 2 暂消 3 重现
	UCHAR Status		:	2;

}INFO_TYPE_STRUCT;

//侦察装备类型
typedef struct RADAR_TYPE_STRUCT
{
	//侦察装备类型 001目标指示010炮瞄011光电跟踪
	UCHAR RadarType	:	3;
	//侦察装备型号 目标指示00001:LLQ03	00010:LLQ04	00011:LLQ07	00100:LLQ08	00101:LLQ09	炮瞄00001:LLP10	00010:LLP12
	UCHAR RadarName	:	5;
}RADAR_TYPE_STRUCT;


// 一批的信息
typedef struct QDB82_BATCH_INFO
{
	//批号
	unsigned short TgtNumber;    //2个字节
	//录取时间和敌我属性
	TGT_TIMEATTR_STRUCT TgtTimeAttr;
	//坐标
	COORDINATE_STRUCT Coord;
	//高度 单位米
	TGT_HEIGHT_STRUCT Height;
	//机型与航迹质量
	TGT_TYPEQUALITY_STRUCT TypeQuality;
	//架数
	UCHAR	QuantityNum;
}QDB82_BATCH_INFO;

//qdb82空情  qdb82协议
typedef struct QDB82_AIRINFOMATION
{
	//报头两个0x7e 0x7e
	UCHAR QDB_HEAD1;
	UCHAR QDB_HEAD2;
	//协议版本0x01
	UCHAR VersionSet;
	//协议长度
	UCHAR Length;

	//标志单元
	UCHAR			HeadFlag;	  //  1111 1111
	//标志单元2
	UCHAR			HeadFlag2;	  //0111 0000
	//报类名称
	INFO_TYPE_STRUCT	INFO_TYPE;
	//侦察装备类型
	RADAR_TYPE_STRUCT	Radar_TYPE;
	//站号
	UCHAR			Station_No;
	//批数
	UCHAR	TgtQuant;
	//可能不止一批
	QDB82_BATCH_INFO tgtBatch;
}QDB82_AIRINFOMATION;

//qdb82侦察装备位置命令
typedef struct QDB82_POSITION
{
	//报头两个0x7e 0x7e
	UCHAR QDB_HEAD1;
	UCHAR QDB_HEAD2;
	//协议版本0x01
	UCHAR VersionSet;
	//协议长度
	UCHAR Length;

	//标志单元
	UCHAR			HeadFlag;		//1111 1110
	//报类名称
	INFO_TYPE_STRUCT			INFO_TYPE;
	//控制命令编码
	UCHAR			CONTROL_CODE;
	//侦察装备类型
	RADAR_TYPE_STRUCT			Radar_TYPE;
	//站号
	UCHAR			Station_No;
	//坐标
	COORDINATE_STRUCT coord;
	//高度
	TGT_HEIGHT_STRUCT Height;
	//发报时间低
	UCHAR			TimeL;
	//发报时间中
	UCHAR			TimeM;
	//发报时间高
	UCHAR			TimeH;
}QDB82_POSITION;
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
//雷达点迹信息   雷达（外部接口）--〉数据接入接出软件--〉系统内部
typedef struct TRK_OWS_PLOT_REPORTSMZ
{
	MESSAGE_HEADER messagehead;
	//距离，0.1m
	unsigned int Range;
	//方位0.001度
	int Azi;
	//俯仰0.001度
	int Ele;
	//高度，0.1m
	int Height;
	//EP数
	unsigned short EpCount;
	//X
	int X;
	//Y
	int Y;
	//波序号
	unsigned int Burstserial;
	//波位号
	unsigned short BurstPos;
	//阵面号
	unsigned char ID;
	//AD幅度
	unsigned short Ad;
	//噪声幅度
	unsigned short NoiseAd;
	//径向速度0.1m/s
	short Dopper;

	//距离宽度0.1m
	unsigned short RangeWidth;
	//方位宽度0.001度
	unsigned int AzimuthWidth;
	//标志，0-原始点 1-滤波点,2-SSR点迹,3-跟踪点迹，9-ADSB点迹
	unsigned char Flag;

}TRK_OWS_PLOT_REPORTSMZ;

/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
//雷达航迹信息(上报空情暂时也用这个)  雷达（外部接口）--〉数据接入接出软件--〉系统内部
/*三坐标雷达点迹*/
/* 3 Bytes typedef struct */
typedef struct	TRIBYTE
{
	unsigned char		Low_uc;              /* low 8 bits */
	unsigned char		Middle_uc;           /* middle 8 bits */
	unsigned char		High_uc;             /* high 8 bits */
}TRIBYTE;

typedef struct RADAR_3_PLOT
{
	TRIBYTE				Range;							/* 距离 */
	unsigned short int	Azimuth_uh;						/* 方位 */
	unsigned short int	Height_uh;						/* 高度 */

}RADAR_3_PLOT;

/*两坐标雷达点迹*/
typedef struct RADAR_2_PLOT
{
	TRIBYTE				Range;							/* 距离 */
	unsigned short int	Azimuth_uh;						/* 方位 */
}RADAR_2_PLOT;

/*航迹状态*/
typedef struct TRACK_STATUS_S
{
#ifdef HPUX11IV2
	unsigned char	Track_Style_b	: 1;					/* 跟踪方式 */
	unsigned char	ARM_b			: 1;					/* ARM */
	unsigned char	Hijack_b		: 1;					/* 劫持 */
	unsigned char	Comm_Fault_b	: 1;					/* 通信故障 */
	unsigned char	Danger_b		: 1;					/* 遇险 */
	unsigned char	Simulate_b		: 1;					/* 模拟 */
	unsigned char	Position_b		: 1;					/* 位置 */
	unsigned char	Antenna_b		: 1;					/* 天线 */
#else
	unsigned char	Antenna_b		: 1;					/* 天线 */
	unsigned char	Position_b		: 1;					/* 位置 */
	unsigned char	Simulate_b		: 1;					/* 模拟 */
	unsigned char	Danger_b		: 1;					/* 遇险 */
	unsigned char	Comm_Fault_b	: 1;					/* 通信故障 */
	unsigned char	Hijack_b		: 1;					/* 劫持 */
	unsigned char	ARM_b			: 1;					/* ARM */
	unsigned char	Track_Style_b	: 1;					/* 跟踪方式 */
#endif

#ifdef HPUX11IV2
	unsigned char	Temp_Lost_b		: 1;					/* 暂消 */
	unsigned char	Recur_b	        : 1;					/* 重现/速度告警 */
	unsigned char	Temp_Stop_b		: 1;					/* 暂停 */
	unsigned char	Revise_b		: 1;					/* 修正 */
	unsigned char	Fade_b			: 1;					/* 衰落 */
	unsigned char	Lost_b			: 1;					/* 丢失 */
	unsigned char	Manual_Init_b	: 1;					/* 人工起始 */
	unsigned char	Auto_Init_b		: 1;					/* 自动起始 */
#else
	unsigned char	Auto_Init_b		: 1;					/* 自动起始 */
	unsigned char	Manual_Init_b	: 1;					/* 人工起始 */
	unsigned char	Lost_b			: 1;					/* 丢失 */
	unsigned char	Fade_b			: 1;					/* 衰落 */
	unsigned char	Revise_b		: 1;					/* 修正 */
	unsigned char	Temp_Stop_b		: 1;					/* 暂停 */
	unsigned char	Recur_b      	: 1;					/* 重现Recur_b/速度告警 */
	unsigned char	Temp_Lost_b		: 1;					/* 暂消 */
#endif

#ifdef HPUX11IV2
	unsigned char	Clear_b			: 1;					/* 清批 */
	unsigned char	Cancel_b		: 1;					/* 删除 */
	unsigned char	Report_b		: 1;					/* 上报 */
	unsigned char	HFU_b			: 1;					/* 测高 */
	unsigned char	Important_b		: 1;					/* 重要 */
	unsigned char	Guard_b			: 1;					/* 警戒区 */
	unsigned char	Sound_b			: 1;					/* 码声 */
	unsigned char	Print_b			: 1;					/* 打印 */
#else
	unsigned char	Print_b			: 1;					/* 打印 */
	unsigned char	Sound_b			: 1;					/* 码声 */
	unsigned char	Guard_b			: 1;					/* 警戒区 */
	unsigned char	Important_b		: 1;					/* 重要 */
	unsigned char	HFU_b			: 1;					/* 测高 */
	unsigned char	Report_b		: 1;					/* 上报 */
	unsigned char	Cancel_b		: 1;					/* 删除 */
	unsigned char	Clear_b			: 1;					/* 清批 */
#endif

}TRACK_STATUS_S;

/*特征代码*/
typedef struct CHARACTER_CODE
{
#ifdef HPUX11IV2
	unsigned char	Flag_b  : 1;						/* 有效标志 */
	unsigned char	Code_b	: 7;						/* 代码 */
#else
	unsigned char	Code_b	: 7;						/* 代码 */
	unsigned char	Flag_b	: 1;						/* 有效标志 */
#endif

}CHARACTER_CODE;


/*IFF代码*/
typedef struct IFF_CODE
{
#ifdef HPUX11IV2
	unsigned short int	Code_uh;						/* 代码 */
#else
	unsigned short int	Code_b	: 15;					/* 代码 */
	unsigned short int	Flag_b	: 1;					/* 有效标志 */
#endif

}IFF_CODE;

/*SSR代码*/
typedef struct SSR_CODE
{
#ifdef HPUX11IV2
	unsigned short int	Code_uh;						/* 代码 */
#else
	unsigned short int	Code_b	: 12;					/* 代码 */
	unsigned short int	Flag_b	: 4;					/* 有效标志 */
#endif

}SSR_CODE;

/*目标航迹*/
typedef struct RI_TARGET_TRACK
{
	MESSAGE_HEADER		Message_Header;					/* 消息头 */

	unsigned char		ChannelID_uc;					/* 通道号 */

	unsigned short int  Batch_uh;						/* 目标批号 */

	RADAR_3_PLOT		Position;						/* 航迹位置 */

	unsigned short int  Speed_uh;						/* 0.1米/秒 */
	unsigned short int  Course_uh;						/* 0.01度 */
	RADAR_2_PLOT		Predict_Position;				/* 下帧预测航迹位置 */

#ifdef HPUX11IV2
	unsigned char		Reserve1		: 1;
	unsigned char		Height_Sourse_b	: 3;			/* 高度来源 */
	unsigned char		Plot_Sourse_b	: 4;			/* 点迹来源 */
#else
	unsigned char		Plot_Sourse_b	: 4;			/* 点迹来源 */
	unsigned char		Height_Sourse_b	: 3;			/* 高度来源 */
	unsigned char		Reserve1		: 1;
#endif

#ifdef HPUX11IV2
	unsigned char		Reserve2		: 1;
	unsigned char		Track_Quality_b	: 3;			/* 跟踪质量 */
	unsigned char		Centre_Beam_b	: 4;			/* 中心波束号 */
#else
	unsigned char		Centre_Beam_b	: 4;			/* 中心波束号 */
	unsigned char		Track_Quality_b	: 3;			/* 跟踪质量 */
	unsigned char		Reserve2		: 1;
#endif

	TRACK_STATUS_S		Track_Status;					/* 航迹状态 */
	unsigned char		ConsoleID_uc;					/* 席位号 */

	CHARACTER_CODE		Attribute;						/* 目标属性 */
	CHARACTER_CODE		Type;							/* 目标类型 */
	CHARACTER_CODE		Quantity;						/* 目标数量 */

#ifdef HPUX11IV2
	unsigned char		FilterGene_b : 2;				/* 拟合因子*/
	unsigned char		FilterModel_b: 2;				/* 滤波模型*/
	unsigned char		IFF_MODE_b	: 4;				/* 询问模式 */
#else
	unsigned char		IFF_MODE_b	: 4;				/* 询问模式 */
	unsigned char		FilterModel_b: 2;				/* 滤波模型*/
	unsigned char		FilterGene_b : 2;				/* 拟合因子*/
#endif

	IFF_CODE			IFF_Code;						/* 询问模式应答信息[军机代码] */
	SSR_CODE			SSR_Code;						/* SSR模式应答码信息+类型[民航代码] */

}RI_TARGET_TRACK;


typedef struct RADAR_STATION_CONFIGURE
{
	unsigned char		Name_us[15];					/* 通道名称15个字节*/
	unsigned char		Radar_StationNo;//  雷达站号   ChannelID_uc;					/* 通道ID */

	int					ChannelLongitude_l;				/* 通道对应雷达经度 4个字节  单位为十万分之一度*/
	int					ChannelLatitude_l;				/* 通道对应雷达纬度 4个字节*/
	unsigned int ChannelAltitude_h;				/* 通道对应雷达高度 2个字节   单位 0.1m */
}RADAR_STATION_CONFIGURE;


/*组网雷达配置*/    // ENUM_SYSTEM_RADAR_CONFIGURE     //系统中雷达站址坐标
typedef struct SYSTEM_RADAR_CONFIGURE
{
	MESSAGE_HEADER		Message_Header;					/* 消息头 */
	unsigned short      count;                          //位置个数
	RADAR_STATION_CONFIGURE   ChannelConfigure[0];	    /* 通道雷达配置，可以同时发送多个通道的雷达配置  配置个数由count确定*/
} SYSTEM_RADAR_CONFIGURE;


/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/*雷达控制参数：发射机开关、工作频率（）、工作模式、波形参数、天线扫描范围、天线扫描速率、检测门限、抗干扰措施*/

//雷达调度界面雷达读取  数据库中增加雷达库  雷达调度界面雷达名显示表下方应该有刷新、增加、删除、选择按键
enum DB_RADAR_COMMAND_ID
{
	ENUM_RADAR_LIST_UPDATE = 1,  //数据库中雷达链表界面刷新
	ENUM_RADAR_DELET      = 2,   //删除雷达库中某一雷达 
	ENUM_RADAR_SELECT     = 3,   //选择雷达库中某一雷达
    ENUM_RADAR_COMMAND_ID_MAX
};

//雷达调度-->数据库   刷新,删除，选择   消息代码为：ENUM_RADAR_COMMAND
typedef struct RADAR_COMMAND
{
	MESSAGE_HEADER  message_header;
	unsigned char   radar_Id;  //雷达id号
	unsigned char   command_Id;  //参见DB_RADAR_COMMAND_ID中定义  刷新、删除、选择
}RADAR_COMMAND;

//数据库-->雷达调度  雷达链表刷新反馈  消息代码为:ENUM_DB_RADAR_LIST_ANSWER
typedef struct DB_RADAR_LIST_ANSWER
{
	MESSAGE_HEADER  message_header;
	unsigned char   radar_number;       //雷达库中雷达个数
	  char          radar_names[0];    //所有雷达名相加组合成一个不定长的字符串  雷达名之间通过“:”进行间隔
}DB_RADAR_LIST_ANSWER;

//抗干扰措施选择
typedef struct ANTI_JAM_PARAMS_DB
{
	unsigned char	  side_hide_flag_uc;     	         //副瓣匿隐开关  0：无该项   1：有该项  
	unsigned char	  side_cancel_flag_uc;     	         //副瓣对消开关  0：无该项   1：有该项   
	unsigned char     side_cancel_Thrsold_flag_uc;       //干扰检测门限  0：无该项   1：有该项 
	unsigned char     JamDisThreshold_flag_uc;           //干扰判别门限  0：无该项   1：有该项
	unsigned char     diver_freq_flag_us;                //频率分集开关  0：无该项    1：有该项        
	unsigned char	  pluse_cover_flag_us;	             //掩护脉冲开关  0：无该项   1：有该项        
}ANTI_JAM_PARAMS_DB;

//雷达参数结构体  雷达写入雷达库时的参数  不同的雷达参数不一致
typedef struct RADAR_PARAM    
{
	unsigned char   Radar_Name[50];      //雷达名称
	unsigned int    Work_Frequency[50];     //工作频率  多个工作频点  单位：MHZ  雷达工作的多个频点
	unsigned char   Work_Mode[5];         //工作模式  参见ENUM_OWS_WORK_MODE_E   
	unsigned int    Beam_Param[10];        //波形参数 
	unsigned short  Scan_Rang[5];         //天线扫描范围  
	unsigned char   Scan_speed[2];        //天线扇扫速度  0：慢  1：快
	unsigned short  Detect_Threshold[5];  //检测门限  
	ANTI_JAM_PARAMS_DB  Anti_JAM;             //抗干扰措施
}RADAR_PARAM;

//雷达调度-->数据库  增加  在雷达调度界面增加雷达参数设置界面，将设置后的雷达参数写入雷达库中
//数据库-->雷达调度  对应界面选择某一雷达
typedef struct RADAR_PARAM_LIB_ADD    //消息代码为：ENUM_RADAR_PARAM_LIB_ADD
{
	MESSAGE_HEADER  message_header;
	RADAR_PARAM     radar_param;    //雷达参数
}RADAR_PARAM_LIB_ADD;

//抗干扰措施控制
typedef struct ANTI_JAM_PARAMS_CTR
{
	unsigned char	  side_hide_flag_uc;     	         //副瓣匿隐有效标志  0：无该项   1：有该项         
	unsigned char     side_hide_open_flg;                //副瓣匿隐开关  0：关   1：开
	unsigned short	  side_hide_Thrsold_uc;              //副瓣匿隐门限，0.1db 

	unsigned char	  side_cancel_flag_uc;     	         //副瓣对消有效标志  0: 无该项   1：有该项       
	unsigned char     side_cancel_open_flg;              //副瓣对消开关      0：关       1：开

	unsigned char     side_cancel_Thrsold_flag_uc;       //干扰检测门限  0：无该项   1：有该项 
	unsigned short	  side_cancel_Thrsold_us;            //干扰检测门限，0.1db 

	unsigned char     JamDisThreshold_flag_uc;           //干扰判别门限  0：无该项   1：有该项
	unsigned short    JamDisThreshold_us;                /*干扰判别门限,     0.1dB         */

	unsigned char     diver_freq_flag_uc;                //频率分集开关  0:无该项    1：有该项        
	unsigned char     diver_freq_open_flg;               //频率分集开关  0：不捷变 1：捷变 

	unsigned char	  pluse_cover_flag_uc;	             //掩护脉冲开关  0：无该项   1：有该项        
	unsigned char	  pluse_cover_open_flg_uc;	         //掩护脉冲开关  0：不启用   1：不启用
}ANTI_JAM_PARAMS_CTR;


//雷达控制参数  雷达调度界面选择的雷达控制参数用于控制雷达   雷达调度-->数据接入接出软件-->雷达控制
typedef struct RADAR_CTROL_PARAM   //消息代码：ENUM_RADAR_CTROL_PARAM
{
	MESSAGE_HEADER  message_header;
	unsigned char  Radar_name[50];    //雷达名称
	unsigned short  Radar_StationNo;  //雷达站号

	unsigned char  Launch_On;         //1：发射开   0：发射关
	unsigned int   Work_Frequency;    //工作频率  单位：HZ
	unsigned char  Work_Mode;         //工作模式  0：     1：     2：      3：
	unsigned int   Beam_Param;         //波形参数 
	unsigned short  Scan_Rang;         //天线扫描范围  
	unsigned char   Scan_speed;        //天线扇扫速度  0：慢  1：快
	unsigned short  Detect_Threshold;  //检测门限  
	ANTI_JAM_PARAMS_CTR   AntiJam_Param; //抗干扰措施   
}RADAR_CTROL_PARAM;
/************************************************************************************************************************/
/****************************************************系统运行状态**************************************************************/
//雷达状态信息   天线  发射机  接收  信号处理  终端  
typedef struct RADAR_STATE_PARAM   //消息代码：ENUM_RADAR_STATE_PARAM
{
	MESSAGE_HEADER  message_header;
	unsigned char   Radar_name[50];    //雷达名称
	unsigned short  Radar_StationNo;  //雷达站号
	unsigned char   Launch_On;        //1：发射开   0：发射关
	unsigned char   Work_Mode;         //工作模式  0：     1：     2：      3：、
	unsigned char   Antana_status;     //0:故障   1：正常
	//unsigned char   Tran
	//天线  发射机  接收  信号处理  终端
	//软件链路状态

//	DAM_BIT_MSG      dam_bit_msg[8];   //DAM 状态信息
//	DBF_BIT_MSG      dbf_bit_msg;      //dbf状态信息
//	COOLING_BIT_MSG  cooling_bit_msg;  //液冷状态信息
//	CUN_BIT_MSG      cun_bit_msg;      //时序控制板状态信息    
}RADAR_STATE_PARAM;











/************************************************************************************************************************/
/****************************************************算法库管理**************************************************************/
//算法模块包括：名字、版本、时间、单位等信息




#pragma pack (pop)

#endif // PROTOCOL_H
