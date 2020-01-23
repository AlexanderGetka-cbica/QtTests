#ifndef DRAGNDROPDOCKWIDGET_H
#define DRAGNDROPDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QEvent>

class DragnDropDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit DragnDropDockWidget(QWidget *parent = nullptr);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

signals:
    void dragEnterReceived(QDragEnterEvent*);
    void dragAndDropReceived(QDropEvent*);

};

#endif // CAPTKDRAGNDROPDOCKWIDGET_H
