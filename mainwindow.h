#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class IRadarMap;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    inline void _initNetwork();

    //! 初始化视图显示参数
    inline bool _initViewparam();

private:
    Ui::MainWindow *ui;
    IRadarMap* m_lpRadarMap;
};

#endif // MAINWINDOW_H
