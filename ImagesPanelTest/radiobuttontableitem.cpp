#include "radiobuttontableitem.h"
#include <QMouseEvent>

#include <QDebug>

RadioButtonTableItem::RadioButtonTableItem()// : QPushButton("stuff")
{

}

void RadioButtonTableItem::mousePressEvent(QMouseEvent *event)
{
    QRadioButton::mousePressEvent(event);
    qDebug() << "bump\n";
//    QRadioButton *rb = qobject_cast<QRadioButton*>(m_imagesTable->cellWidget(row, col));
//                    if(rb)
//                    {
//                        qDebug() << " radiobutton clicked at cell = " << row << "," << col << endl;
//                        //rb->;
//                    }
    //event->accept();
}
