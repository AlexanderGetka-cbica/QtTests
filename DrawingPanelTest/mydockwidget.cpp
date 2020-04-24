#include "mydockwidget.h"
#include <QMimeData>
#include <QDebug>

MyDockWidget::MyDockWidget()
{
    qDebug() << "using MyDockWidget " << endl;
    this->setAcceptDrops(true);
}


void MyDockWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void MyDockWidget::dropEvent(QDropEvent *event)
{
    foreach (const QUrl &url, event->mimeData()->urls())
    {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file in MyDockWidget:" << fileName;
    }
}

void MyDockWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "MyDockWidget::mouseMoveEvent" << endl;
}

void MyDockWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MyDockWidget::mousePressEvent" << endl;
}
