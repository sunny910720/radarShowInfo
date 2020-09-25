#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ctrldlg.h"
#include "glb_dataitem.h"

#include "viewarea.h"
#include "viewlayer.h"
#include "viewwndqt.h"
#include "transform.h"

#include "useroperate.h"

#include "network.h"

#include "mapdisplay.h"
#include "i_radarmap.h"

#include <QDockWidget>
#include <QPluginLoader>
#include <QDebug>

#include "radardisplay.h"
#include "radarwidget.h"
#include "sqlitedatabase.h"
#include "log.h"

using namespace QtWnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("雷达射频回波模块训练控制软件"));
    LogInit(Log_Error,LogFlagAll);
    SqliteDataBase::getInstance()->initData();
    RadarIntf::instance()->initialize();
    QDockWidget * dock = new QDockWidget("雷达实时信息显示", this);
    dock->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
    //dock->setWidget(new CtrlDlg);
    dock->setWidget(new RadarWidget);

    //dock->setFloating(true);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    const QPointF center(113,29);
    //const QPointF center(117,32);
    Transform::instance()->initialize(center);

    UserOperate::instance()->initialize();

    const QString filename = "./plugins/RadarMap.dll";
    QPluginLoader loader(filename);
    //qDebug() << loader.errorString();
    m_lpRadarMap = qobject_cast<IRadarMap*>(loader.instance());

    //RadarIntf::instance()->initialize();


    // 注册图层信息
    ItemInfo backg(1, "scale", "scale line");
    ItemInfo target(2, "track", "track");
    ItemInfo map(3, "map", "map");
    ViewLayerLib::instance()->addLayerInfo(LayerInfo(1, backg));
    ViewLayerLib::instance()->addLayerInfo(LayerInfo(2, target));
    ViewLayerLib::instance()->addLayerInfo(LayerInfo(3, map));

    _initViewparam();

    ViewArea * lpViewArea = ViewAreaFactory::instance()->createViewArea(VMI_PScanView);
    ViewWnd * lpViewWnd = new ViewWnd(lpViewArea);
    lpViewArea->setParent(lpViewWnd);

    // 注册窗口鼠标事件
    lpViewWnd->registerEventFunc(eu_MouseMoveEvent, UserOperate::instance()->getMouseMoveFunc());
    lpViewWnd->registerEventFunc(eu_MousePressEvent, UserOperate::instance()->getMousePressFunc());
    lpViewWnd->registerEventFunc(eu_MouseReleaseEvent, UserOperate::instance()->getMouseClickFunc());

    ViewLayerLib::instance()->addViewLayer(lpViewArea, new PViewPainter(), 1, 1);
    ViewLayerLib::instance()->addViewLayer(lpViewArea, RadarIntf::instance()->createPainter(), 2, 2);


    if(m_lpRadarMap)
    {
        const QString mapConfigFile = "./config/mapconfig.json.txt";
        m_lpRadarMap->createMapDisplay(mapConfigFile);
        m_lpRadarMap->registerView((PViewArea *)lpViewArea);
        BasePainter *pPainter = m_lpRadarMap->createMapPainter(lpViewArea);
        ViewLayerLib::instance()->addViewLayer(lpViewArea, pPainter, 3, 3);
    }


    QPointF proj_center = Transform::instance()->geo2proj(center);
    PViewArea* pview = (PViewArea*)(lpViewArea);
    pview->setRangeScope(1000, 300000);
    pview->setProjRect(proj_center, 400000);

    setCentralWidget(lpViewWnd);

    _initNetwork();
}

MainWindow::~MainWindow()
{
    delete ui;
}

inline void MainWindow::_initNetwork()
{
   bool isFlag = Network::instance()->initialize();
   if(!isFlag)
   {
       LogError(QObject::tr("网络配置文件读取失败"));
   }
}

//! 初始化视图显示参数
inline bool MainWindow::_initViewparam()
{
    ViewDispParam* vdp = ViewDispParam::instance();
    vdp->setForeColor(QColor(168,168,168));
    vdp->setBackColor(Qt::black, 1);
    vdp->setMaxRng(500000);
    vdp->setScale(50000, 15);
    vdp->setClipping(false);
    vdp->showOutCircle(false);
    return true;
}
