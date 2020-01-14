#ifndef MYDOCKWIDGET_H
#define MYDOCKWIDGET_H

#include <QDockWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>

class MyDockWidget : public QDockWidget
{
public:
    MyDockWidget();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    virtual void 	mouseMoveEvent(QMouseEvent *event);
    virtual void 	mousePressEvent(QMouseEvent *event);
};

#endif // MYDOCKWIDGET_H
