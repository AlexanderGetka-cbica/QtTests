#include "dragndropdockwidget.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <iostream>
DragnDropDockWidget::DragnDropDockWidget(QWidget *parent) : QDockWidget(parent)
{
    this->setAcceptDrops(false);
}

void DragnDropDockWidget::dragEnterEvent(QDragEnterEvent* event) {
    emit dragEnterReceived(event);
}

void DragnDropDockWidget::dropEvent(QDropEvent *event) {
    std::cout<<"Drop event detected on DnD Dock Widget."<<std::endl;
    emit dragAndDropReceived(event);
}
