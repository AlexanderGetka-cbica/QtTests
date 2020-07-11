#ifndef SYSTEMINFORMATIONDISPLAYWIDGET_H
#define SYSTEMINFORMATIONDISPLAYWIDGET_H

#include <QWidget>

namespace Ui {
class SystemInformationDisplayWidget;
}

class SystemInformationDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemInformationDisplayWidget(QWidget *parent = nullptr);
    ~SystemInformationDisplayWidget();

    void SetInformation(QStringList s);

    void ClearInformation();

public slots:
    void OnCopyToClipboardBtnClicked();

private:
    Ui::SystemInformationDisplayWidget *ui;
};

#endif // SYSTEMINFORMATIONDISPLAYWIDGET_H
