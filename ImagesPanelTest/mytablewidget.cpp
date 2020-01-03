#include "mytablewidget.h"
#include <QDebug>

myTableWidget::myTableWidget()
{

}

void myTableWidget::mousePressEvent(QMouseEvent *event)
{
    const int SELECTABLE_COLUMN = 1;

    QModelIndex i = indexAt(event->pos());
    int row = i.row();
    int col = i.column();
    qDebug() << " clicked at cell = " << row << "," << col << endl;
    if(i.column() == SELECTABLE_COLUMN)
    {
        QTableView::mousePressEvent(event);
    }

}
