#ifndef RADIOBUTTONTABLEITEM_H
#define RADIOBUTTONTABLEITEM_H

#include <QRadioButton>
#include <QTableWidgetItem>

class RadioButtonTableItem : public QRadioButton, public QTableWidgetItem
{
public:
    RadioButtonTableItem();
};

#endif // RADIOBUTTONTABLEITEM_H
