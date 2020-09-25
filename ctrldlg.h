#ifndef CTRLDLG_H
#define CTRLDLG_H

#include <QWidget>

namespace Ui {
class CtrlDlg;
}

class CtrlDlg : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlDlg(QWidget *parent = nullptr);
    ~CtrlDlg();

private slots:
    void on_SiteBtn_clicked();

    void on_TgtBtn_clicked();

    void on_JamBtn_clicked();

protected:
    inline void sendCmdData(const QByteArray& data);

private:
    Ui::CtrlDlg *ui;
};

#endif // CTRLDLG_H
