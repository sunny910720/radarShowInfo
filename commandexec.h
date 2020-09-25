/*
 * Created mofi 2020-06-29
 */

#ifndef COMMANDEXEC_H
#define COMMANDEXEC_H

#include "command.h"
#include "dataitem.h"
#include <QString>

class QAction;

typedef DataItem<QString> CmdCfgItem;
typedef DataItemLib<CmdCfgItem::Type> CmdCfgLib;

typedef DataItem<QAction*> ActionItem;
typedef DataItemLib<ActionItem::Type> ActionLib;

// 获取操作命令功能标签
inline quint8 GetCmdLabel(Command* cmd){
    return quint8(cmd->getCmdInfo()._label);
}

/*
 * class : CommandExec
 * author: mofi
 * date:2020-06-27
 * desc: 用户命令执行类
 */
class CommandExec
{
    DECL_SINGLETON(CommandExec)
public:

    //! 获取命令处理函数
    CmdFunc getFunc(const QString& name)
    {
        return m_cmdFuncHash.value(name, nullptr);
    }

    //! 注册命令处理函数
    bool registerCmd(const QString& name, CmdFunc func)
    {
        if(!m_cmdFuncHash.contains(name))
        {
            m_cmdFuncHash.insert(name, func);
            return true;
        }
        return false;
    }

protected:
    /// 将命令回调函数放入Hash表中，以便通过函数名称来获取回调函数对象
    QHash<QString, CmdFunc> m_cmdFuncHash;
};


#endif // COMMANDEXEC_H
