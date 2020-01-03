#ifndef RADIOBUTTONTABLEITEM_H
#define RADIOBUTTONTABLEITEM_H

#include <QRadioButton>
#include<QLabel>
#include<QPushButton>
#include <QTableWidgetItem>

class RadioButtonTableItem : public QRadioButton//QPushButton// QLabel//QRadioButton//, public QTableWidgetItem
{
//    Q_OBJECT
public:
    RadioButtonTableItem();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
};

#endif // RADIOBUTTONTABLEITEM_H
