#ifndef IPREFERENCEPAGE_H
#define IPREFERENCEPAGE_H

#include <QWidget>

class IPreferencePage : public QWidget
{
    Q_OBJECT
public:
    explicit IPreferencePage(QWidget *parent = nullptr);

    virtual void OnOkay(){}
    virtual void OnCancel(){}

signals:

public slots:
};

#endif // IPREFERENCEPAGE_H
