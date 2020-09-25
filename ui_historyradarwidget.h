/********************************************************************************
** Form generated from reading UI file 'historyradarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYRADARWIDGET_H
#define UI_HISTORYRADARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryRadarWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_startTime;
    QDateTimeEdit *dateTimeEdit_start;
    QLabel *label_endTime;
    QDateTimeEdit *dateTimeEdit_end;
    QCheckBox *checkBox;
    QPushButton *pushButton_qry;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *HistoryRadarWidget)
    {
        if (HistoryRadarWidget->objectName().isEmpty())
            HistoryRadarWidget->setObjectName(QString::fromUtf8("HistoryRadarWidget"));
        HistoryRadarWidget->resize(873, 480);
        HistoryRadarWidget->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout = new QGridLayout(HistoryRadarWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_startTime = new QLabel(HistoryRadarWidget);
        label_startTime->setObjectName(QString::fromUtf8("label_startTime"));

        horizontalLayout->addWidget(label_startTime);

        dateTimeEdit_start = new QDateTimeEdit(HistoryRadarWidget);
        dateTimeEdit_start->setObjectName(QString::fromUtf8("dateTimeEdit_start"));
        dateTimeEdit_start->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit_start);

        label_endTime = new QLabel(HistoryRadarWidget);
        label_endTime->setObjectName(QString::fromUtf8("label_endTime"));

        horizontalLayout->addWidget(label_endTime);

        dateTimeEdit_end = new QDateTimeEdit(HistoryRadarWidget);
        dateTimeEdit_end->setObjectName(QString::fromUtf8("dateTimeEdit_end"));
        dateTimeEdit_end->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit_end);

        checkBox = new QCheckBox(HistoryRadarWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        pushButton_qry = new QPushButton(HistoryRadarWidget);
        pushButton_qry->setObjectName(QString::fromUtf8("pushButton_qry"));

        horizontalLayout->addWidget(pushButton_qry);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(HistoryRadarWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("QTableView::item:selected { background-color: rgb(135,206,250) }"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        retranslateUi(HistoryRadarWidget);

        QMetaObject::connectSlotsByName(HistoryRadarWidget);
    } // setupUi

    void retranslateUi(QWidget *HistoryRadarWidget)
    {
        HistoryRadarWidget->setWindowTitle(QApplication::translate("HistoryRadarWidget", "\345\216\206\345\217\262\351\233\267\350\276\276\346\225\205\351\232\234\344\277\241\346\201\257\350\241\250", nullptr));
        label_startTime->setText(QApplication::translate("HistoryRadarWidget", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        label_endTime->setText(QApplication::translate("HistoryRadarWidget", "\347\273\223\346\235\237\346\227\266\351\227\264:", nullptr));
        checkBox->setText(QApplication::translate("HistoryRadarWidget", "\346\211\200\346\234\211", nullptr));
        pushButton_qry->setText(QApplication::translate("HistoryRadarWidget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryRadarWidget: public Ui_HistoryRadarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYRADARWIDGET_H
