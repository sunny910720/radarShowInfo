/********************************************************************************
** Form generated from reading UI file 'ctrldlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLDLG_H
#define UI_CTRLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CtrlDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *SiteBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *RadarType;
    QLabel *label_15;
    QLabel *label_2;
    QComboBox *SignalType;
    QLabel *label_18;
    QLabel *label_3;
    QLineEdit *Boduan1;
    QLabel *label_12;
    QLabel *label_4;
    QLineEdit *Boduan2;
    QLabel *label_14;
    QLabel *label_5;
    QLineEdit *SignalBandW;
    QLabel *label_13;
    QLabel *label_6;
    QLineEdit *RadarPower;
    QLabel *label_19;
    QLabel *label_7;
    QLineEdit *SiteLon;
    QLabel *label_16;
    QLabel *label_8;
    QLineEdit *SiteLat;
    QLabel *label_20;
    QLabel *label_9;
    QLineEdit *SiteHgt;
    QLabel *label_17;
    QLabel *label_10;
    QPushButton *SiteBtn;
    QLabel *label_21;
    QGroupBox *TgtBox;
    QGridLayout *gridLayout_2;
    QLabel *label_25;
    QComboBox *TgtType;
    QLabel *label_24;
    QLabel *label_30;
    QComboBox *TgtSwelling;
    QLabel *label_28;
    QLabel *label_11;
    QLineEdit *TgtRCS;
    QLabel *label_29;
    QLabel *label_32;
    QLineEdit *TgtSpeed;
    QLabel *label_23;
    QLabel *label_26;
    QLineEdit *TgtAzi1;
    QLabel *label_22;
    QLabel *label_31;
    QLineEdit *TgtRng1;
    QLabel *label_27;
    QLabel *label_34;
    QLineEdit *TgtAzi2;
    QLabel *label_36;
    QLabel *label_35;
    QLineEdit *TgtRng2;
    QLabel *label_33;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_37;
    QPushButton *TgtBtn;
    QLabel *label_38;
    QGroupBox *JamBox;
    QGridLayout *gridLayout_3;
    QLabel *label_43;
    QComboBox *JamType;
    QLabel *label_39;
    QLabel *label_44;
    QLineEdit *JamPower;
    QLabel *label_45;
    QLabel *label_46;
    QLineEdit *JamFreqW1;
    QLabel *label_49;
    QLabel *label_47;
    QLineEdit *JamFreqW2;
    QLabel *label_48;
    QLabel *label_55;
    QLineEdit *JamAzi1;
    QLabel *label_60;
    QLabel *label_54;
    QLineEdit *JamRng1;
    QLabel *label_57;
    QLabel *label_58;
    QLineEdit *JamAzi2;
    QLabel *label_56;
    QLabel *label_61;
    QLineEdit *JamRng2;
    QLabel *label_59;
    QLabel *label_51;
    QLineEdit *JamSpeed;
    QLabel *label_50;
    QLabel *label_53;
    QPushButton *JamBtn;
    QLabel *label_52;

    void setupUi(QWidget *CtrlDlg)
    {
        if (CtrlDlg->objectName().isEmpty())
            CtrlDlg->setObjectName(QString::fromUtf8("CtrlDlg"));
        CtrlDlg->resize(310, 459);
        verticalLayout = new QVBoxLayout(CtrlDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SiteBox = new QGroupBox(CtrlDlg);
        SiteBox->setObjectName(QString::fromUtf8("SiteBox"));
        SiteBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(SiteBox);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(SiteBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        RadarType = new QComboBox(SiteBox);
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->addItem(QString());
        RadarType->setObjectName(QString::fromUtf8("RadarType"));

        gridLayout->addWidget(RadarType, 0, 1, 1, 1);

        label_15 = new QLabel(SiteBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 0, 2, 1, 1);

        label_2 = new QLabel(SiteBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        SignalType = new QComboBox(SiteBox);
        SignalType->addItem(QString());
        SignalType->addItem(QString());
        SignalType->addItem(QString());
        SignalType->addItem(QString());
        SignalType->setObjectName(QString::fromUtf8("SignalType"));

        gridLayout->addWidget(SignalType, 0, 4, 1, 1);

        label_18 = new QLabel(SiteBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 0, 5, 1, 1);

        label_3 = new QLabel(SiteBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        Boduan1 = new QLineEdit(SiteBox);
        Boduan1->setObjectName(QString::fromUtf8("Boduan1"));

        gridLayout->addWidget(Boduan1, 1, 1, 1, 1);

        label_12 = new QLabel(SiteBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        label_4 = new QLabel(SiteBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        Boduan2 = new QLineEdit(SiteBox);
        Boduan2->setObjectName(QString::fromUtf8("Boduan2"));

        gridLayout->addWidget(Boduan2, 1, 4, 1, 1);

        label_14 = new QLabel(SiteBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 1, 5, 1, 1);

        label_5 = new QLabel(SiteBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        SignalBandW = new QLineEdit(SiteBox);
        SignalBandW->setObjectName(QString::fromUtf8("SignalBandW"));

        gridLayout->addWidget(SignalBandW, 2, 1, 1, 1);

        label_13 = new QLabel(SiteBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 2, 2, 1, 1);

        label_6 = new QLabel(SiteBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 3, 1, 1);

        RadarPower = new QLineEdit(SiteBox);
        RadarPower->setObjectName(QString::fromUtf8("RadarPower"));

        gridLayout->addWidget(RadarPower, 2, 4, 1, 1);

        label_19 = new QLabel(SiteBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 2, 5, 1, 1);

        label_7 = new QLabel(SiteBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        SiteLon = new QLineEdit(SiteBox);
        SiteLon->setObjectName(QString::fromUtf8("SiteLon"));

        gridLayout->addWidget(SiteLon, 3, 1, 1, 1);

        label_16 = new QLabel(SiteBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 3, 2, 1, 1);

        label_8 = new QLabel(SiteBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 3, 3, 1, 1);

        SiteLat = new QLineEdit(SiteBox);
        SiteLat->setObjectName(QString::fromUtf8("SiteLat"));

        gridLayout->addWidget(SiteLat, 3, 4, 1, 1);

        label_20 = new QLabel(SiteBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 3, 5, 1, 1);

        label_9 = new QLabel(SiteBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        SiteHgt = new QLineEdit(SiteBox);
        SiteHgt->setObjectName(QString::fromUtf8("SiteHgt"));

        gridLayout->addWidget(SiteHgt, 4, 1, 1, 1);

        label_17 = new QLabel(SiteBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 4, 2, 1, 1);

        label_10 = new QLabel(SiteBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 3, 1, 1);

        SiteBtn = new QPushButton(SiteBox);
        SiteBtn->setObjectName(QString::fromUtf8("SiteBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SiteBtn->sizePolicy().hasHeightForWidth());
        SiteBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(SiteBtn, 4, 4, 1, 1);

        label_21 = new QLabel(SiteBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 4, 5, 1, 1);


        verticalLayout->addWidget(SiteBox);

        TgtBox = new QGroupBox(CtrlDlg);
        TgtBox->setObjectName(QString::fromUtf8("TgtBox"));
        TgtBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(TgtBox);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        label_25 = new QLabel(TgtBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_25, 0, 0, 1, 1);

        TgtType = new QComboBox(TgtBox);
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->addItem(QString());
        TgtType->setObjectName(QString::fromUtf8("TgtType"));

        gridLayout_2->addWidget(TgtType, 0, 1, 1, 1);

        label_24 = new QLabel(TgtBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 0, 2, 1, 1);

        label_30 = new QLabel(TgtBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_30, 0, 4, 1, 1);

        TgtSwelling = new QComboBox(TgtBox);
        TgtSwelling->addItem(QString());
        TgtSwelling->addItem(QString());
        TgtSwelling->addItem(QString());
        TgtSwelling->addItem(QString());
        TgtSwelling->addItem(QString());
        TgtSwelling->setObjectName(QString::fromUtf8("TgtSwelling"));

        gridLayout_2->addWidget(TgtSwelling, 0, 5, 1, 1);

        label_28 = new QLabel(TgtBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_2->addWidget(label_28, 0, 6, 1, 1);

        label_11 = new QLabel(TgtBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        TgtRCS = new QLineEdit(TgtBox);
        TgtRCS->setObjectName(QString::fromUtf8("TgtRCS"));

        gridLayout_2->addWidget(TgtRCS, 1, 1, 1, 1);

        label_29 = new QLabel(TgtBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_2->addWidget(label_29, 1, 2, 1, 2);

        label_32 = new QLabel(TgtBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_32, 1, 4, 1, 1);

        TgtSpeed = new QLineEdit(TgtBox);
        TgtSpeed->setObjectName(QString::fromUtf8("TgtSpeed"));

        gridLayout_2->addWidget(TgtSpeed, 1, 5, 1, 1);

        label_23 = new QLabel(TgtBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 1, 6, 1, 1);

        label_26 = new QLabel(TgtBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_26, 2, 0, 1, 1);

        TgtAzi1 = new QLineEdit(TgtBox);
        TgtAzi1->setObjectName(QString::fromUtf8("TgtAzi1"));

        gridLayout_2->addWidget(TgtAzi1, 2, 1, 1, 1);

        label_22 = new QLabel(TgtBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_2->addWidget(label_22, 2, 2, 1, 1);

        label_31 = new QLabel(TgtBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 2, 4, 1, 1);

        TgtRng1 = new QLineEdit(TgtBox);
        TgtRng1->setObjectName(QString::fromUtf8("TgtRng1"));

        gridLayout_2->addWidget(TgtRng1, 2, 5, 1, 1);

        label_27 = new QLabel(TgtBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_2->addWidget(label_27, 2, 6, 1, 1);

        label_34 = new QLabel(TgtBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 3, 0, 1, 1);

        TgtAzi2 = new QLineEdit(TgtBox);
        TgtAzi2->setObjectName(QString::fromUtf8("TgtAzi2"));

        gridLayout_2->addWidget(TgtAzi2, 3, 1, 1, 1);

        label_36 = new QLabel(TgtBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_2->addWidget(label_36, 3, 2, 1, 1);

        label_35 = new QLabel(TgtBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_35, 3, 3, 1, 2);

        TgtRng2 = new QLineEdit(TgtBox);
        TgtRng2->setObjectName(QString::fromUtf8("TgtRng2"));

        gridLayout_2->addWidget(TgtRng2, 3, 5, 1, 1);

        label_33 = new QLabel(TgtBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_2->addWidget(label_33, 3, 6, 1, 1);

        label_40 = new QLabel(TgtBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_40, 4, 0, 1, 1);

        label_41 = new QLabel(TgtBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_41, 4, 1, 1, 1);

        label_42 = new QLabel(TgtBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_42, 4, 2, 1, 1);

        label_37 = new QLabel(TgtBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_37, 4, 4, 1, 1);

        TgtBtn = new QPushButton(TgtBox);
        TgtBtn->setObjectName(QString::fromUtf8("TgtBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TgtBtn->sizePolicy().hasHeightForWidth());
        TgtBtn->setSizePolicy(sizePolicy1);
        TgtBtn->setMinimumSize(QSize(0, 22));

        gridLayout_2->addWidget(TgtBtn, 4, 5, 1, 1);

        label_38 = new QLabel(TgtBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_38, 4, 6, 1, 1);


        verticalLayout->addWidget(TgtBox);

        JamBox = new QGroupBox(CtrlDlg);
        JamBox->setObjectName(QString::fromUtf8("JamBox"));
        JamBox->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(JamBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_43 = new QLabel(JamBox);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_43, 0, 0, 1, 1);

        JamType = new QComboBox(JamBox);
        JamType->addItem(QString());
        JamType->addItem(QString());
        JamType->addItem(QString());
        JamType->addItem(QString());
        JamType->setObjectName(QString::fromUtf8("JamType"));

        gridLayout_3->addWidget(JamType, 0, 1, 1, 1);

        label_39 = new QLabel(JamBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_3->addWidget(label_39, 0, 2, 1, 2);

        label_44 = new QLabel(JamBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_44, 0, 4, 1, 1);

        JamPower = new QLineEdit(JamBox);
        JamPower->setObjectName(QString::fromUtf8("JamPower"));

        gridLayout_3->addWidget(JamPower, 0, 5, 1, 1);

        label_45 = new QLabel(JamBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_3->addWidget(label_45, 0, 6, 1, 1);

        label_46 = new QLabel(JamBox);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_46, 1, 0, 1, 1);

        JamFreqW1 = new QLineEdit(JamBox);
        JamFreqW1->setObjectName(QString::fromUtf8("JamFreqW1"));

        gridLayout_3->addWidget(JamFreqW1, 1, 1, 1, 1);

        label_49 = new QLabel(JamBox);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_3->addWidget(label_49, 1, 2, 1, 2);

        label_47 = new QLabel(JamBox);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_47, 1, 4, 1, 1);

        JamFreqW2 = new QLineEdit(JamBox);
        JamFreqW2->setObjectName(QString::fromUtf8("JamFreqW2"));

        gridLayout_3->addWidget(JamFreqW2, 1, 5, 1, 1);

        label_48 = new QLabel(JamBox);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_3->addWidget(label_48, 1, 6, 1, 1);

        label_55 = new QLabel(JamBox);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_55, 2, 0, 1, 1);

        JamAzi1 = new QLineEdit(JamBox);
        JamAzi1->setObjectName(QString::fromUtf8("JamAzi1"));

        gridLayout_3->addWidget(JamAzi1, 2, 1, 1, 1);

        label_60 = new QLabel(JamBox);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_3->addWidget(label_60, 2, 2, 1, 2);

        label_54 = new QLabel(JamBox);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_54, 2, 4, 1, 1);

        JamRng1 = new QLineEdit(JamBox);
        JamRng1->setObjectName(QString::fromUtf8("JamRng1"));

        gridLayout_3->addWidget(JamRng1, 2, 5, 1, 1);

        label_57 = new QLabel(JamBox);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        gridLayout_3->addWidget(label_57, 2, 6, 1, 1);

        label_58 = new QLabel(JamBox);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_58, 3, 0, 1, 1);

        JamAzi2 = new QLineEdit(JamBox);
        JamAzi2->setObjectName(QString::fromUtf8("JamAzi2"));

        gridLayout_3->addWidget(JamAzi2, 3, 1, 1, 1);

        label_56 = new QLabel(JamBox);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_3->addWidget(label_56, 3, 2, 1, 1);

        label_61 = new QLabel(JamBox);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_61, 3, 3, 1, 2);

        JamRng2 = new QLineEdit(JamBox);
        JamRng2->setObjectName(QString::fromUtf8("JamRng2"));

        gridLayout_3->addWidget(JamRng2, 3, 5, 1, 1);

        label_59 = new QLabel(JamBox);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_3->addWidget(label_59, 3, 6, 1, 1);

        label_51 = new QLabel(JamBox);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_51, 4, 0, 1, 1);

        JamSpeed = new QLineEdit(JamBox);
        JamSpeed->setObjectName(QString::fromUtf8("JamSpeed"));

        gridLayout_3->addWidget(JamSpeed, 4, 1, 1, 1);

        label_50 = new QLabel(JamBox);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_3->addWidget(label_50, 4, 2, 1, 2);

        label_53 = new QLabel(JamBox);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_53, 4, 4, 1, 1);

        JamBtn = new QPushButton(JamBox);
        JamBtn->setObjectName(QString::fromUtf8("JamBtn"));
        sizePolicy.setHeightForWidth(JamBtn->sizePolicy().hasHeightForWidth());
        JamBtn->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(JamBtn, 4, 5, 1, 1);

        label_52 = new QLabel(JamBox);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_52, 4, 6, 1, 1);


        verticalLayout->addWidget(JamBox);


        retranslateUi(CtrlDlg);

        QMetaObject::connectSlotsByName(CtrlDlg);
    } // setupUi

    void retranslateUi(QWidget *CtrlDlg)
    {
        CtrlDlg->setWindowTitle(QApplication::translate("CtrlDlg", "Form", nullptr));
        SiteBox->setTitle(QApplication::translate("CtrlDlg", "\351\233\267\350\276\276\347\253\231\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("CtrlDlg", "\351\233\267\350\276\276\345\236\213\345\217\267", nullptr));
        RadarType->setItemText(0, QApplication::translate("CtrlDlg", "LLQ03C", nullptr));
        RadarType->setItemText(1, QApplication::translate("CtrlDlg", "LLQ04E", nullptr));
        RadarType->setItemText(2, QApplication::translate("CtrlDlg", "LLQ07A", nullptr));
        RadarType->setItemText(3, QApplication::translate("CtrlDlg", "LLQ08", nullptr));
        RadarType->setItemText(4, QApplication::translate("CtrlDlg", "LLQ08A", nullptr));
        RadarType->setItemText(5, QApplication::translate("CtrlDlg", "LLQ10", nullptr));
        RadarType->setItemText(6, QApplication::translate("CtrlDlg", "LLQ11", nullptr));
        RadarType->setItemText(7, QApplication::translate("CtrlDlg", "LLP10B", nullptr));
        RadarType->setItemText(8, QApplication::translate("CtrlDlg", "LLP10C", nullptr));
        RadarType->setItemText(9, QApplication::translate("CtrlDlg", "LLP12", nullptr));
        RadarType->setItemText(10, QApplication::translate("CtrlDlg", "LLP12A", nullptr));
        RadarType->setItemText(11, QApplication::translate("CtrlDlg", "HQ-16B", nullptr));
        RadarType->setItemText(12, QApplication::translate("CtrlDlg", "HQ-7B", nullptr));
        RadarType->setItemText(13, QApplication::translate("CtrlDlg", "HQ-17", nullptr));

        label_15->setText(QString());
        label_2->setText(QApplication::translate("CtrlDlg", "\344\277\241\345\217\267\347\261\273\345\236\213", nullptr));
        SignalType->setItemText(0, QApplication::translate("CtrlDlg", "\345\270\270\350\247\204\350\204\211\345\206\262", nullptr));
        SignalType->setItemText(1, QApplication::translate("CtrlDlg", "\347\272\277\346\200\247\350\260\203\351\242\221", nullptr));
        SignalType->setItemText(2, QApplication::translate("CtrlDlg", "\344\272\214\347\233\270\347\274\226\347\240\201", nullptr));
        SignalType->setItemText(3, QApplication::translate("CtrlDlg", "\351\235\236\347\272\277\346\200\247\350\260\203\351\242\221", nullptr));

        label_18->setText(QString());
        label_3->setText(QApplication::translate("CtrlDlg", "\345\274\200\345\247\213\346\263\242\346\256\265", nullptr));
        label_12->setText(QApplication::translate("CtrlDlg", "MHz", nullptr));
        label_4->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\346\263\242\346\256\265", nullptr));
        label_14->setText(QApplication::translate("CtrlDlg", "MHz", nullptr));
        label_5->setText(QApplication::translate("CtrlDlg", "\344\277\241\345\217\267\345\270\246\345\256\275", nullptr));
        label_13->setText(QApplication::translate("CtrlDlg", "MHz", nullptr));
        label_6->setText(QApplication::translate("CtrlDlg", "\345\212\237\347\216\207", nullptr));
        label_19->setText(QApplication::translate("CtrlDlg", "kw", nullptr));
        label_7->setText(QApplication::translate("CtrlDlg", "\347\273\217\345\272\246", nullptr));
        label_16->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_8->setText(QApplication::translate("CtrlDlg", "\347\272\254\345\272\246", nullptr));
        label_20->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_9->setText(QApplication::translate("CtrlDlg", "\351\253\230\345\272\246", nullptr));
        label_17->setText(QApplication::translate("CtrlDlg", "\347\261\263", nullptr));
        label_10->setText(QString());
        SiteBtn->setText(QApplication::translate("CtrlDlg", "\350\256\276\347\275\256", nullptr));
        label_21->setText(QString());
        TgtBox->setTitle(QApplication::translate("CtrlDlg", "\347\233\256\346\240\207\350\256\276\347\275\256", nullptr));
        label_25->setText(QApplication::translate("CtrlDlg", "\347\233\256\346\240\207\347\261\273\345\236\213", nullptr));
        TgtType->setItemText(0, QApplication::translate("CtrlDlg", "\346\234\272\345\236\213\344\270\215\346\230\216", nullptr));
        TgtType->setItemText(1, QApplication::translate("CtrlDlg", "\350\275\260\347\202\270\346\234\272", nullptr));
        TgtType->setItemText(2, QApplication::translate("CtrlDlg", "\346\210\230\346\226\227\346\234\272", nullptr));
        TgtType->setItemText(3, QApplication::translate("CtrlDlg", "\347\233\264\345\215\207\346\234\272", nullptr));
        TgtType->setItemText(4, QApplication::translate("CtrlDlg", "\345\267\241\350\210\252\345\257\274\345\274\271", nullptr));
        TgtType->setItemText(5, QApplication::translate("CtrlDlg", "\346\227\240\344\272\272\346\234\272", nullptr));
        TgtType->setItemText(6, QApplication::translate("CtrlDlg", "\346\234\252\345\256\232\344\271\211", nullptr));

        label_24->setText(QString());
        label_30->setText(QApplication::translate("CtrlDlg", "SWelling", nullptr));
        TgtSwelling->setItemText(0, QApplication::translate("CtrlDlg", "Swelling0", nullptr));
        TgtSwelling->setItemText(1, QApplication::translate("CtrlDlg", "Swelling1", nullptr));
        TgtSwelling->setItemText(2, QApplication::translate("CtrlDlg", "Swelling2", nullptr));
        TgtSwelling->setItemText(3, QApplication::translate("CtrlDlg", "Swelling3", nullptr));
        TgtSwelling->setItemText(4, QApplication::translate("CtrlDlg", "Swelling4", nullptr));

        label_28->setText(QString());
        label_11->setText(QApplication::translate("CtrlDlg", "RCS", nullptr));
        label_29->setText(QApplication::translate("CtrlDlg", "0.0 m2", nullptr));
        label_32->setText(QApplication::translate("CtrlDlg", "\351\200\237\345\272\246", nullptr));
        label_23->setText(QApplication::translate("CtrlDlg", "km/h", nullptr));
        label_26->setText(QApplication::translate("CtrlDlg", "\350\265\267\345\247\213\346\226\271\344\275\215", nullptr));
        label_22->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_31->setText(QApplication::translate("CtrlDlg", "\350\265\267\345\247\213\350\267\235\347\246\273", nullptr));
        label_27->setText(QApplication::translate("CtrlDlg", "\345\205\254\351\207\214", nullptr));
        label_34->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\346\226\271\344\275\215", nullptr));
        label_36->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_35->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\350\267\235\347\246\273", nullptr));
        label_33->setText(QApplication::translate("CtrlDlg", "\345\205\254\351\207\214", nullptr));
        label_40->setText(QString());
        label_41->setText(QString());
        label_42->setText(QString());
        label_37->setText(QString());
        TgtBtn->setText(QApplication::translate("CtrlDlg", "\346\267\273\345\212\240\347\233\256\346\240\207", nullptr));
        label_38->setText(QString());
        JamBox->setTitle(QApplication::translate("CtrlDlg", "\345\271\262\346\211\260\350\256\276\347\275\256", nullptr));
        label_43->setText(QApplication::translate("CtrlDlg", "\345\271\262\346\211\260\346\250\241\345\274\217", nullptr));
        JamType->setItemText(0, QApplication::translate("CtrlDlg", "\347\252\204\345\270\246\345\216\213\345\210\266", nullptr));
        JamType->setItemText(1, QApplication::translate("CtrlDlg", "\345\256\275\345\270\246\345\216\213\345\210\266", nullptr));
        JamType->setItemText(2, QApplication::translate("CtrlDlg", "\350\210\252\350\277\271\346\254\272\351\252\227", nullptr));
        JamType->setItemText(3, QApplication::translate("CtrlDlg", "\345\257\206\347\247\257\345\260\217\347\233\256\346\240\207", nullptr));

        label_39->setText(QString());
        label_44->setText(QApplication::translate("CtrlDlg", "\345\217\221\345\260\204\345\212\237\347\216\207", nullptr));
        label_45->setText(QApplication::translate("CtrlDlg", "kw", nullptr));
        label_46->setText(QApplication::translate("CtrlDlg", "\350\265\267\345\247\213\351\242\221\345\256\275", nullptr));
        label_49->setText(QApplication::translate("CtrlDlg", "MHz", nullptr));
        label_47->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\351\242\221\345\256\275", nullptr));
        label_48->setText(QApplication::translate("CtrlDlg", "MHz", nullptr));
        label_55->setText(QApplication::translate("CtrlDlg", "\350\265\267\345\247\213\346\226\271\344\275\215", nullptr));
        label_60->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_54->setText(QApplication::translate("CtrlDlg", "\350\265\267\345\247\213\350\267\235\347\246\273", nullptr));
        label_57->setText(QApplication::translate("CtrlDlg", "\345\205\254\351\207\214", nullptr));
        label_58->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\346\226\271\344\275\215", nullptr));
        label_56->setText(QApplication::translate("CtrlDlg", "\345\272\246", nullptr));
        label_61->setText(QApplication::translate("CtrlDlg", "\347\273\223\346\235\237\350\267\235\347\246\273", nullptr));
        label_59->setText(QApplication::translate("CtrlDlg", "\345\205\254\351\207\214", nullptr));
        label_51->setText(QApplication::translate("CtrlDlg", "\351\200\237\345\272\246", nullptr));
        label_50->setText(QApplication::translate("CtrlDlg", "km/h", nullptr));
        label_53->setText(QString());
        JamBtn->setText(QApplication::translate("CtrlDlg", "\346\267\273\345\212\240\345\271\262\346\211\260", nullptr));
        label_52->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CtrlDlg: public Ui_CtrlDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLDLG_H
