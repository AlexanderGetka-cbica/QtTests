#ifndef MYRADIOBUTTON_H
#define MYRADIOBUTTON_H

#include <QRadioButton>

class MyRadioButton : public QObject
{
    Q_OBJECT
public:
    MyRadioButton();

protected:
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // MYRADIOBUTTON_H
