/********************************************************************************
** Form generated from reading UI file 'radarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARWIDGET_H
#define UI_RADARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RadarWidget
{
public:
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_zd;
    QPushButton *pushButton_ll;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_zd;
    QLabel *label_xhcl;
    QPushButton *pushButton_fsj;
    QLabel *label_ll;
    QLabel *label_fsj;
    QLabel *label_tx;
    QPushButton *pushButton_xhcl;
    QLabel *label_js;
    QPushButton *pushButton_js;
    QPushButton *pushButton_tx;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *RadarWidget)
    {
        if (RadarWidget->objectName().isEmpty())
            RadarWidget->setObjectName(QString::fromUtf8("RadarWidget"));
        RadarWidget->resize(541, 707);
        RadarWidget->setMaximumSize(QSize(16777215, 16777215));
        RadarWidget->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout_2 = new QGridLayout(RadarWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(5, 0, 0, 0);
        listWidget = new QListWidget(RadarWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_2->addWidget(listWidget, 3, 0, 1, 1);

        groupBox = new QGroupBox(RadarWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 0);
        pushButton_zd = new QPushButton(groupBox);
        pushButton_zd->setObjectName(QString::fromUtf8("pushButton_zd"));
        pushButton_zd->setEnabled(false);
        pushButton_zd->setMinimumSize(QSize(30, 30));
        pushButton_zd->setCheckable(false);

        gridLayout->addWidget(pushButton_zd, 1, 4, 1, 1);

        pushButton_ll = new QPushButton(groupBox);
        pushButton_ll->setObjectName(QString::fromUtf8("pushButton_ll"));
        pushButton_ll->setEnabled(false);
        pushButton_ll->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_ll, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(520, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 6);

        label_zd = new QLabel(groupBox);
        label_zd->setObjectName(QString::fromUtf8("label_zd"));

        gridLayout->addWidget(label_zd, 1, 3, 1, 1);

        label_xhcl = new QLabel(groupBox);
        label_xhcl->setObjectName(QString::fromUtf8("label_xhcl"));

        gridLayout->addWidget(label_xhcl, 3, 3, 1, 1);

        pushButton_fsj = new QPushButton(groupBox);
        pushButton_fsj->setObjectName(QString::fromUtf8("pushButton_fsj"));
        pushButton_fsj->setEnabled(false);
        pushButton_fsj->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_fsj, 3, 1, 1, 1);

        label_ll = new QLabel(groupBox);
        label_ll->setObjectName(QString::fromUtf8("label_ll"));

        gridLayout->addWidget(label_ll, 1, 0, 1, 1);

        label_fsj = new QLabel(groupBox);
        label_fsj->setObjectName(QString::fromUtf8("label_fsj"));

        gridLayout->addWidget(label_fsj, 3, 0, 1, 1);

        label_tx = new QLabel(groupBox);
        label_tx->setObjectName(QString::fromUtf8("label_tx"));

        gridLayout->addWidget(label_tx, 2, 0, 1, 1);

        pushButton_xhcl = new QPushButton(groupBox);
        pushButton_xhcl->setObjectName(QString::fromUtf8("pushButton_xhcl"));
        pushButton_xhcl->setEnabled(false);
        pushButton_xhcl->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_xhcl, 3, 4, 1, 1);

        label_js = new QLabel(groupBox);
        label_js->setObjectName(QString::fromUtf8("label_js"));

        gridLayout->addWidget(label_js, 2, 3, 1, 1);

        pushButton_js = new QPushButton(groupBox);
        pushButton_js->setObjectName(QString::fromUtf8("pushButton_js"));
        pushButton_js->setEnabled(false);
        pushButton_js->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_js, 2, 4, 1, 1);

        pushButton_tx = new QPushButton(groupBox);
        pushButton_tx->setObjectName(QString::fromUtf8("pushButton_tx"));
        pushButton_tx->setEnabled(false);
        pushButton_tx->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_tx, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(100, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(100, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 5, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        tableView = new QTableView(RadarWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("QTableView::item:selected { background-color: rgb(135,206,250) }"));

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(520, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 0, 1, 1);


        retranslateUi(RadarWidget);

        QMetaObject::connectSlotsByName(RadarWidget);
    } // setupUi

    void retranslateUi(QWidget *RadarWidget)
    {
        RadarWidget->setWindowTitle(QApplication::translate("RadarWidget", "\351\233\267\350\276\276\344\277\241\346\201\257\350\241\250", nullptr));
        groupBox->setTitle(QApplication::translate("RadarWidget", "\351\233\267\350\276\276\350\257\246\347\273\206\346\225\205\351\232\234\344\277\241\346\201\257\346\230\276\347\244\272", nullptr));
        pushButton_zd->setText(QString());
        pushButton_ll->setText(QString());
        label_zd->setText(QApplication::translate("RadarWidget", "\347\273\210\347\253\257\347\212\266\346\200\201\357\274\232", nullptr));
        label_xhcl->setText(QApplication::translate("RadarWidget", "\344\277\241\345\217\267\345\244\204\347\220\206\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_fsj->setText(QString());
        label_ll->setText(QApplication::translate("RadarWidget", "\351\223\276\350\267\257\347\212\266\346\200\201\357\274\232", nullptr));
        label_fsj->setText(QApplication::translate("RadarWidget", "\345\217\221\345\260\204\346\234\272\347\212\266\346\200\201\357\274\232", nullptr));
        label_tx->setText(QApplication::translate("RadarWidget", "\345\244\251\347\272\277\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_xhcl->setText(QString());
        label_js->setText(QApplication::translate("RadarWidget", "\346\216\245\346\224\266\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_js->setText(QString());
        pushButton_tx->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RadarWidget: public Ui_RadarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARWIDGET_H
