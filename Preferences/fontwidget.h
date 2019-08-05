#ifndef FONTWIDGET_H
#define FONTWIDGET_H

#include <QWidget>
#include "ipreferencepage.h"

namespace Ui {
class FontWidget;
}

class FontWidget : public IPreferencePage
{
    Q_OBJECT

public:
    explicit FontWidget(QWidget *parent = nullptr);
    ~FontWidget();

    void OnOkay() override;
    void OnCancel() override;
private:
    Ui::FontWidget *ui;
};

#endif // FONTWIDGET_H
