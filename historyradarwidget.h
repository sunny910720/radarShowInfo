#ifndef HISTORYRADARWIDGET_H
#define HISTORYRADARWIDGET_H

#include <QWidget>
#include <string>
class HistoryRadarModel;

namespace Ui {
class HistoryRadarWidget;
}

class HistoryRadarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryRadarWidget(std::string radarName,QWidget *parent = nullptr);
    ~HistoryRadarWidget();

    void init();

signals:

public slots:
    void qryBreakSlot();
private:
    Ui::HistoryRadarWidget *ui;
    std::string             m_rardarName;
    HistoryRadarModel*      m_historyRadarModel;

};

#endif // HISTORYRADARWIDGET_H
