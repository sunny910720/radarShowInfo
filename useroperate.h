/*
 * Created mofi 2020-07-17
 */
#ifndef USEROPERATE_20200717_H
#define USEROPERATE_20200717_H

#include "commandexec.h"
#include "glb_singleton.h"
#include "viewarea.h"
#include "viewwnd.h"

#include <QObject>
#include <QList>
#include <QPointF>

//using namespace std::placeholders;
#define PL(i) std::placeholders::##i
#define PL1 std::placeholders::_1
#define PL2 std::placeholders::_1, std::placeholders::_2
#define PL3 std::placeholders::_1, std::placeholders::_2, std::placeholders::_3

class MouseClick;

/*
 * class : UserOperate
 * author: mofi
 * date:2020-06-29
 * desc: 用户操作处理管理类
 *  在创建窗口对象之后，最后初始化
 */
class UserOperate : public QObject
{
    DECL_SINGLETON2(UserOperate, QObject)
public:
    //! 操作处理初始化
    bool initialize();
    bool init1st();
    bool init2ed();
    //! 获取操作命令配置对象
    CmdCfgLib* getCmdCfgLib() {   return &m_cmdCfgLib;  }
    //! 获取Action库
    ActionLib* getActionLib() {   return &m_actionLib;  }

    MouseOperate* getMouseOperate() {   return m_lpMouseOperate;    }
    KeyboardOperate* getKbdOperate(){   return m_lpKbdOperate;      }
    KbdBuffer *   getKbdBuffer()    {   return m_lpKbdInput;    }
    Selector  *   getTrkSelect()    {   return m_trackSlt;  }

public:
    //! 创建所有命令对象
    inline bool createAllCommands();

    //! 航迹对象选择函数
    Handler trackSelect(ViewArea*, const QPoint&, quint8);
    //! 作图对象选择函数
    Handler userMapSelect(ViewArea*, const QPoint&, quint8);
    //! 测量对象选择函数
    Handler measureSelect(ViewArea*, const QPoint&, quint8);
    //! 区域对象选择函数
    Handler zoneSelect(ViewArea*, const QPoint&, quint8);

    // 说明：这里不能将该函数定义为const，否则编译不通过
    auto getMouseMoveFunc()  {
        return std::bind(&UserOperate::mouseMove, this, PL3);
    }

    auto getMouseClickFunc()  {
        return std::bind(&UserOperate::mouseClick, this, PL3);
    }

    auto getMousePressFunc() {
        return std::bind(&UserOperate::mousePress, this, PL3);
    }

    // 航迹鼠标覆盖或选择改变
    void trackOverChanged(Handler _old, Handler _new);
    void trackSlctChanged(Handler _old, Handler _new);

    //! 鼠标移动处理
    void mouseMove(ViewWnd*, QEvent*, quint32);
    //! 鼠标单击处理
    void mouseClick(ViewWnd*, QEvent*, quint32);
    //! 鼠标键按下处理
    void mousePress(ViewWnd*, QEvent*, quint32);

    void setMouseClick(MouseClick *pMouseClick);

    void deletePress();
protected:
    // 查的操作窗口
    inline void findOperateWnd();
//    // 从GUI获取子控件对象
//    template<typename T>
//    inline T* getWidgetFromGui(const QString& name);
    inline QButton* getOperateButton(const QString& name);
    // 创建Action对象
    inline QAction* createAction(const QString & action, const QString& icon, const CmdInfo& info);

protected:
    Selector * m_trackSlt;
    Selector * m_userMapSlt;
    Selector * m_measureSlt;
    Selector * m_zoneSlt;
    KbdBuffer * m_lpKbdInput;
    MouseOperate* m_lpMouseOperate;
    KeyboardOperate* m_lpKbdOperate;

    CmdCfgLib   m_cmdCfgLib;
    ActionLib   m_actionLib;

    QWidget * m_lpOperateWnd;

    MouseClick * m_lpMouseClick;
};

enum MouseOperateType
{
    eMeasureMouseClick,
    eZoneMouseClick,
    eZoneMouseDeleteClick,
    eMouseOperateTypeCount
};



class MouseClick
{
public:
    virtual ~MouseClick() = default;
    virtual void mouseClick(const QPointF &pt) = 0;
    virtual void mouseOver(const QPointF &pt) = 0;
    virtual void setSlt(Selector *) = 0;
    virtual void deletePress() {};
    virtual void setRate(double dRate) {};

    const int m_nCurType = eMouseOperateTypeCount;
};

class MeasureMouseClick : public MouseClick
{
    DECL_SINGLETON2(MeasureMouseClick, MouseClick)
public:
    virtual void mouseClick(const QPointF &pt) override;
    virtual void mouseOver(const QPointF &pt) override;

    virtual void setSlt(Selector *) override;

    virtual void setRate(double dRate) override;
    virtual void deletePress() override;

    const int m_nCurType = eMeasureMouseClick;
protected:
    Selector * m_trackSlt;
    QPointF m_ptPre;
    double m_dRate;

    void deleteItem(const QPointF &pt, float ration2pixel);
    //Measure*
};

class ZoneMouseClick : public MouseClick
{
      DECL_SINGLETON2(ZoneMouseClick, MouseClick)
public:
      virtual void mouseClick(const QPointF &pt) override;
      virtual void mouseOver(const QPointF &pt) override;
      virtual void setSlt(Selector *) override;

      const int m_nCurType = eZoneMouseClick;
protected:

     Selector * m_trackSlt1;
     QList<QPointF> m_points;

};

class ZoneMouseDeleteClick : public MouseClick
{
      DECL_SINGLETON2(ZoneMouseDeleteClick, MouseClick)
public:
      virtual void mouseClick(const QPointF &pt) override;
      virtual void mouseOver(const QPointF &pt) override;
      virtual void setSlt(Selector *) override;

      const int m_nCurType = eZoneMouseDeleteClick;
protected:
      Selector * m_trackSlt1;

};

class DragDrop
{
    DECL_SINGLETON_V2(DragDrop)
public:
    enum {DragNone = 0, DragStart, DragStop};
    void dragStart(ViewArea* lpView, const QPoint& pos, int trkIndex=0);
    void dragMove(ViewArea* lpView, const QPoint& pos);
    void dragStop(ViewArea* lpView, const QPoint& pos);
protected:
    inline void _stop()
    {
        m_flag = DragNone;
        m_trkIndex = 0;
    }
private:
    quint8 m_flag;
    ViewArea* m_lpView;
    QPoint m_startPos;
    int m_trkIndex;
};

inline DragDrop* GetDragDrop(){
    return DragDrop::instance();
}


#endif // USEROPERATE_20200717_H
