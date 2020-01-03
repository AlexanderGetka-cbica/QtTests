#include "myradiobutton.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

MyRadioButton::MyRadioButton()
{
    //this->installEventFilter(this);
}

bool MyRadioButton::eventFilter(QObject *object, QEvent *event)
{
    //qDebug() << "MyRadioButton::eventFilter" << endl;
    if (event->type() == QEvent::MouseButtonPress)
    {
        //QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //qDebug("Ate key press %d", keyEvent->key());
        QMouseEvent *me = static_cast<QMouseEvent *>(event);
        if(me->button() == Qt::LeftButton)
        {
            qDebug() << " left mouse button pressed" << endl;
             QRadioButton *rb = qobject_cast<QRadioButton*>(object);
            if(rb)
            {
                //rb->setAttribute(Qt::WA_NoMousePropagation);
                qDebug() << " radiobutton clicked " << endl;
                //rb->click();
            }
        }
        //return true;
    }
    else
    {
        // standard event processing
        return QObject::eventFilter(object, event);
    }

}
