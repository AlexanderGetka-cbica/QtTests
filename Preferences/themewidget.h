#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>
#include "ipreferencepage.h"

namespace Ui {
class ThemeWidget;
}

class ThemeWidget : public IPreferencePage
{
    Q_OBJECT

public:
    explicit ThemeWidget(QWidget *parent = nullptr);
    ~ThemeWidget();


    void OnOkay() override;
    void OnCancel() override;

private:
    Ui::ThemeWidget *ui;
};

#endif // THEMEWIDGET_H
