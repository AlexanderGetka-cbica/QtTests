#ifndef SYSTEMINFORMATIONDISPLAYWIDGET2_H
#define SYSTEMINFORMATIONDISPLAYWIDGET2_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QTextEdit;
class QLabel;

class SystemInformationDisplayWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit SystemInformationDisplayWidget2(QWidget *parent = nullptr);

    void SetInformation(QStringList s);

signals:

public slots:

private:
    void SetupUi();

    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *CopyToClipboardPushButton;
    QTextEdit *textEdit;
    QLabel *label;
};

#endif // SYSTEMINFORMATIONDISPLAYWIDGET2_H
