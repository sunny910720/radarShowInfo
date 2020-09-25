/*
 * Created mofi 2020-07-17
 */

#include "useroperate.h"

#include "kbdinput.h"
#include "boardrect.h"
#include "transform.h"
#include "trackdata.h"
#include "viewwnd.h"

#include "glb_auxfunc.h"

#include <QtDebug>
#include <QWidget>
#include <QLineEdit>
#include <QApplication>

static TrackData* s_lpTrackData = nullptr;

/*
 * class : UserOperate
 * author: mofi
 * date:2020-06-29
 * desc: 用户操作处理管理类
 */
IMPL_SINGLETON(UserOperate)

//! 操作处理初始化(这个在创建窗口之后，最后初始化)
bool UserOperate::initialize()
{
    //s_lpTrackData = RadarTrackMng::instance()->getData();

    findOperateWnd();
//    // 初始化命令执行函数对象
//    CommandExec::instance()->initialize();
    // 创建所有命令对象
    createAllCommands();

    // 创建航迹对象选择器
    auto trkSlt = std::bind(&UserOperate::trackSelect, this, PL3);
    m_trackSlt = new Selector(trkSlt);
    // 创建作图对象选择器
    auto mapSlt = std::bind(&UserOperate::userMapSelect, this, PL3);
    m_userMapSlt = new Selector(mapSlt);
    // 创建测量对象选择器
    auto measureSlt = std::bind(&UserOperate::measureSelect, this, PL3);
    m_measureSlt = new Selector(measureSlt);
    // 创建航迹选择器
    auto zoneSlt = std::bind(&UserOperate::zoneSelect, this, PL3);
    m_zoneSlt = new Selector(zoneSlt);

    // 创建键盘输入缓存对象
    m_lpKbdInput = new KbdBuffer;
    // 创建鼠标操作对象
    m_lpMouseOperate = new MouseOperate;
    // 创建键盘操作对象
    m_lpKbdOperate = new KeyboardOperate(m_lpKbdInput, m_lpMouseOperate);

    m_lpMouseOperate->setSelector(m_trackSlt);

//    // 连接 KbdBuffer::updateInputDisplay --> 界面显示更新键盘输入显示
//    QLineEdit * lpInputEdit = GetWidgetFromGui<QLineEdit>("inputEdit");
//    if(lpInputEdit)
//    connect(m_lpKbdInput, SIGNAL(updateInputDisplay(const QString&)),
//            lpInputEdit, SLOT(setText(const QString&)));

    m_lpMouseClick = nullptr;

    return true;
}


bool UserOperate::init1st()
{
    auto trkOver = std::bind(&UserOperate::trackOverChanged, this, PL2);
    auto trkSlct = std::bind(&UserOperate::trackSlctChanged, this, PL2);

    // 创建航迹对象选择器
    auto trkSlt = std::bind(&UserOperate::trackSelect, this,  PL3);
    m_trackSlt = new Selector(trkSlt);
    m_trackSlt->setObjChangedFunc(trkOver, trkSlct);
    // 创建作图对象选择器
    auto mapSlt = std::bind(&UserOperate::userMapSelect, this,  PL3);
    m_userMapSlt = new Selector(mapSlt);
    // 创建测量对象选择器
    auto measureSlt = std::bind(&UserOperate::measureSelect, this,  PL3);
    m_measureSlt = new Selector(measureSlt);
    // 创建航迹选择器
    auto zoneSlt = std::bind(&UserOperate::zoneSelect, this,  PL3);
    m_zoneSlt = new Selector(zoneSlt);

    // 创建键盘输入缓存对象
    m_lpKbdInput = new KbdBuffer;
    // 创建鼠标操作对象
    m_lpMouseOperate = new MouseOperate;
    // 创建键盘操作对象
    m_lpKbdOperate = new KeyboardOperate(m_lpKbdInput, m_lpMouseOperate);

    m_lpMouseOperate->setSelector(m_trackSlt);

    m_lpOperateWnd = nullptr;
    m_lpMouseClick = nullptr;

    return true;
}

bool UserOperate::init2ed()
{
    findOperateWnd();
//    // 初始化命令执行函数对象
//    CommandExec::instance()->initialize();
    // 创建所有命令对象
    createAllCommands();

    return true;
}

//! 创建所有命令对象
inline bool UserOperate::createAllCommands()
{
#define CharFlag QChar('\'')
#define CheckChar(str) ((str).size()==3 && (str)[0] == CharFlag && (str)[2] == CharFlag)

    CommandFactory* lpCmdLib = CommandFactory::instance();
    CommandExec * lpCmdExec = CommandExec::instance();

    const CmdCfgLib::ItemHash& hash = m_cmdCfgLib.items();
    CmdCfgLib::ItemHash::const_iterator it = hash.constBegin();
    for(; it != hash.constEnd(); ++it)
    {
        const QString & strinfo = it.value().data();
        const QStringList list = strinfo.split(",", QString::KeepEmptyParts);
        if(list.size() != 8)    //7)
            continue;

        quint8 asciicode = CheckChar(list[4]) ? list[4].at(1).toLatin1() : StringValue<quint8>(list[4]);
        quint8 scancode = StringValue<quint8>(list[5]);
        quint16 flag = StringValue<quint16>(list[6]);
        quint16 label = StringValue<quint16>(list[7]);
        QString btnNm = list[2];
        quint16 id = it.key();
        quint16 key = quint16(FormCmdKey(asciicode, scancode));
        QString name = it.value().name(), text = it.value().text(), desc = it.value().desc();
        CmdInfo info(id, key, flag, btnNm, name, text, desc);
        info._label = label;
        QAction* lpAction = createAction(list[1], list[3], info);
        QButton* lpButton = getOperateButton(btnNm);
        CmdFunc  lpFunc = lpCmdExec->getFunc(list[0]);
        Command* lpCommand = new Command(info, lpAction, lpButton);
        lpCommand->setExcutedFunc(lpFunc);
        lpCmdLib->registerCommand(lpCommand);
    }

    return true;
}

//! 航迹对象选择函数
Handler UserOperate::trackSelect(ViewArea* lpView, const QPoint& pos, quint8 behavior)
{
    BoardRect* lpBoardRect = BoardRectFactory::instance()->boardRect(lpView);
    if(lpBoardRect)
    {
        int trkindex = lpBoardRect->findTrack(pos);
        if(trkindex > 0)
        {
            PTrackItem trackItem = s_lpTrackData->getTrack(trkindex, 0);
            return Handler(trackItem);
        }
    }

    return nullptr;
}

//! 作图对象选择函数
Handler UserOperate::userMapSelect(ViewArea*, const QPoint&, quint8)
{
    return nullptr;
}

//! 测量对象选择函数
Handler UserOperate::measureSelect(ViewArea*, const QPoint&, quint8)
{
    return nullptr;
}

//! 区域对象选择函数
Handler UserOperate::zoneSelect(ViewArea*, const QPoint&, quint8)
{
    return nullptr;
}

//! 鼠标移动处理
void UserOperate::mouseMove(ViewWnd* lpWnd, QEvent* lpEvent, quint32)
{
    ViewArea * pview = (lpWnd->viewArea());
    QMouseEvent * lpMouseEvent = (QMouseEvent*)(lpEvent);

    const Qt::MouseButtons btns = lpMouseEvent->buttons();
    if(btns & Qt::LeftButton)
    {   // mouse move with left button down
        if(m_lpMouseClick)
        {   // 暂时不处理 mouseMove 事件
        }
        else
        {
            GetDragDrop()->dragMove(pview, lpMouseEvent->pos());
        }
    }
    else if(btns & Qt::RightButton)
    {   // mouse move with right button down

    }
    else if(btns == Qt::NoButton)
    {   // mouse move with no button down
        m_lpMouseOperate->mouseMoved(pview, lpMouseEvent->pos());
        if(m_lpMouseClick)
        {
            QPointF ptF = pview->screen_to_square(lpMouseEvent->pos());
            m_lpMouseClick->mouseOver(ptF);
        }
    }

    //qDebug() << __FUNCTION__ << lpMouseEvent->button() << lpMouseEvent->buttons();
}

//! 鼠标键按下处理
void UserOperate::mousePress(ViewWnd* lpWnd, QEvent* lpEvent, quint32)
{
    ViewArea * pview = (lpWnd->viewArea());
    QMouseEvent * lpMouseEvent = (QMouseEvent*)(lpEvent);
    if(lpMouseEvent->button() == Qt::LeftButton)
    {   // 左键按下
        m_lpMouseOperate->mouseClicked(lpWnd->viewArea(), lpMouseEvent->pos());
        if(m_lpMouseClick)
        {
        }
        else
        {
            PTrackItem trk = PTrackItem(m_trackSlt->getCrntObj());
            int trkidx = trk ? trk->_data._trkIndex : 0;
            GetDragDrop()->dragStart(pview, lpMouseEvent->pos(), trkidx);
        }
    }
    else if(lpMouseEvent->button() == Qt::RightButton)
    {   // 右键按下

    }
    qDebug() << __FUNCTION__ << lpMouseEvent->button() << lpMouseEvent->buttons();
}

//! 鼠标单击处理
#include "radardisplay.h"
void UserOperate::mouseClick(ViewWnd* lpWnd, QEvent* lpEvent, quint32)
{
    ViewArea * pview = (lpWnd->viewArea());
    QMouseEvent * lpMouseEvent = (QMouseEvent*)(lpEvent);

    if(lpMouseEvent->button() == Qt::LeftButton)
    {   // 左键释放
//        m_lpMouseOperate->mouseClicked(lpWnd->viewArea(), lpMouseEvent->pos());
        RadarIntf::instance()->zoneDisplay()->mouseClick(lpMouseEvent->pos());
        if(m_lpMouseClick)
        {
            QPointF ptF = pview->screen_to_square(lpMouseEvent->pos());
            m_lpMouseClick->setRate(pview->ratex());
            m_lpMouseClick->mouseClick(ptF);
        }
        else
        {
            GetDragDrop()->dragStop(pview, lpMouseEvent->pos());
        }
    }
    else if(lpMouseEvent->button() == Qt::RightButton)
    {   // 右键释放
        if(m_lpMouseClick)
            m_lpMouseClick = nullptr;
        else
        {
            Command* lpCmd = Command::getCrntCmd();
            if(lpCmd)
                lpCmd->stop();
        }
    }

    qDebug() << __FUNCTION__ << lpMouseEvent->button() << lpMouseEvent->buttons();
}

// 航迹鼠标覆盖或选择改变
void UserOperate::trackOverChanged(Handler _old, Handler _new)
{
    PTrackItem item1 = PTrackItem(_old);
    PTrackItem item2 = PTrackItem(_new);
//    if(item1)
//        item1->_data._info._attr.insert(Config::AttrBoardOver, 0);
//    if(item2)
//        item2->_data._info._attr.insert(Config::AttrBoardOver, 1);
}

void UserOperate::trackSlctChanged(Handler _old, Handler _new)
{
    PTrackItem item1 = PTrackItem(_old);
    PTrackItem item2 = PTrackItem(_new);
//    if(item1)
//        item1->_data._info._attr.insert(Config::AttrBoardSlted, 0);
//    if(item2)
//        item2->_data._info._attr.insert(Config::AttrBoardSlted, 1);
}

void UserOperate::deletePress()
{
    if(m_lpMouseClick)
        m_lpMouseClick->deletePress();
}

inline void UserOperate::findOperateWnd()
{
//    m_lpOperateWnd = GetWidgetFromGui<QWidget>("OperateWnd");
}

// 从操作窗口获取按钮对象
inline QButton* UserOperate::getOperateButton(const QString& name)
{
    return nullptr;
//    return m_lpOperateWnd ? m_lpOperateWnd->findChild<QButton*>(name) :
//                            GetWidgetFromGui<QButton>(name);
}

// 创建Action对象
inline QAction* UserOperate::createAction(const QString & action, const QString& icon, const CmdInfo& info)
{
    QAction * lpAction = new QAction;

    lpAction->setIcon(QIcon(icon));
    lpAction->setText(info._text);

    ActionItem item(lpAction, info._id, info._name, info._text, info._desc);
    m_actionLib.addDataItem(item);

    return lpAction;
}

void UserOperate::setMouseClick(MouseClick *pMouseClick)
{
    m_lpMouseClick = pMouseClick;
    //if(m_lpMouseClick->m_nCurType == eMeasureMouseClick)
    {
        m_lpMouseClick->setSlt(m_trackSlt);
    }
}

void DragDrop::dragStart(ViewArea* lpView, const QPoint& pos, int trkIndex)
{
    m_flag = DragStart;
    m_lpView = lpView;
    m_startPos = pos;
    m_trkIndex = trkIndex;
}

void DragDrop::dragMove(ViewArea* lpView, const QPoint& pos)
{
    if(lpView != m_lpView || DragStart != m_flag)
        return;

    const QPoint dp = pos - m_startPos;
    if(dp.manhattanLength() > 5)
    {
        qDebug() << __FUNCTION__ << dp << m_trkIndex;
        if(m_trkIndex)
        {
            ViewWnd * lpWnd = (ViewWnd*)(lpView->parent());
            lpWnd->startTrackDrag(m_trkIndex);
        }
        else
        {
            lpView->dragMove(dp.x(), dp.y());
            m_startPos = pos;
        }
    }
}

void DragDrop::dragStop(ViewArea* lpView, const QPoint& pos)
{
    if(lpView != m_lpView || DragStart != m_flag)
        return;

    _stop();
}
