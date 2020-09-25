#include "ctrldlg.h"
#include "ui_ctrldlg.h"
#include "datadef.h"
#include "network.h"

#include "glb_auxfunc.h"
#include "glb_format.h"

#include <QtDebug>
#include <QByteArray>

inline void InitDataHead(DataHead& head, quint8 length, quint8 label)
{
    head._FFFF = 0xffff;
    head._length = length;
    head._label = label;
}

CtrlDlg::CtrlDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlDlg)
{
    ui->setupUi(this);
}

CtrlDlg::~CtrlDlg()
{
    delete ui;
}

void CtrlDlg::on_SiteBtn_clicked()
{
    qDebug() << __FUNCTION__;
    const int size = sizeof(SiteInfo) - 2;
    QByteArray data(size+1, 0);
    SiteInfo *info = (SiteInfo*)(data.data());
    InitDataHead(info->_head, size+1, 1);
    info->_radarType = ui->RadarType->currentIndex();
    info->_signalType = ui->SignalType->currentIndex();
    info->_freqBand1 = ui->Boduan1->text().toInt();
    info->_freqBand2 = ui->Boduan2->text().toInt();
    info->_freqBandW = ui->SignalBandW->text().toInt();
    info->_power = ui->RadarPower->text().toInt();
    info->_lon = ui->SiteLon->text().toDouble() * 10000;
    info->_lat = ui->SiteLat->text().toDouble() * 10000;
    info->_hgt = ui->SiteHgt->text().toInt();

    data[size] = GetCheckSum(data.data()+2, size-2);
    sendCmdData(data);
}

void CtrlDlg::on_TgtBtn_clicked()
{
    qDebug() << __FUNCTION__;
    const int size = sizeof(TargetInfo) + sizeof(WayPoint) - 2;
    QByteArray data(size+1, 0);
    TargetInfo *info = (TargetInfo*)(data.data());
    InitDataHead(info->_head, size+1, 2);
    info->_targetType = ui->TgtType->currentIndex();
    info->_swelling = ui->TgtSwelling->currentIndex();
    info->_rcs = ui->TgtRCS->text().toInt();
    info->_speed = ui->TgtSpeed->text().toInt();

    WayPoint * lpWp = info->_wp;
    lpWp[0]._azi = ui->TgtAzi1->text().toDouble() / 360.0 * 65536.0;
    lpWp[0]._rng = ui->TgtRng1->text().toInt();
    lpWp[1]._azi = ui->TgtAzi2->text().toDouble() / 360.0 * 65536.0;
    lpWp[1]._rng = ui->TgtRng2->text().toInt();

    data[size] = GetCheckSum(data.data()+2, size-2);
    sendCmdData(data);
}

void CtrlDlg::on_JamBtn_clicked()
{
    qDebug() << __FUNCTION__;
    const int size = sizeof(JamInfo) + sizeof(WayPoint) - 2;
    QByteArray data(size+1, 0);
    JamInfo *info = (JamInfo*)(data.data());
    InitDataHead(info->_head, size+1, 3);
    info->_jamMode = ui->JamType->currentIndex();
    info->_trPower = ui->JamPower->text().toInt();
    info->_jamBand1 = ui->JamFreqW1->text().toInt();
    info->_jamBand2 = ui->JamFreqW2->text().toInt();
    info->_speed = ui->JamSpeed->text().toInt();

    WayPoint * lpWp = info->_wp;
    lpWp[0]._azi = ui->JamAzi1->text().toDouble() / 360.0 * 65536.0;
    lpWp[0]._rng = ui->JamRng1->text().toInt();
    lpWp[1]._azi = ui->JamAzi2->text().toDouble() / 360.0 * 65536.0;
    lpWp[1]._rng = ui->JamRng2->text().toInt();

    data[size] = GetCheckSum(data.data()+2, size-2);
    sendCmdData(data);
}

inline void CtrlDlg::sendCmdData(const QByteArray& data)
{
    qDebug() << __FUNCTION__;
    qDebug() << Data2String(data);
    Network::instance()->sendData(data, 1);
}
