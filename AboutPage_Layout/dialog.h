#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QWebEngineView;
class QWidget;
class QCheckBox;
class QSlider;
class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QSpacerItem;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLabel *zoomValueLabel;
    QLabel *percentLabel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    // QWebView* m_webView;
    // NEW CHANGES
    QWidget * widget;
};

#endif // DIALOG_H
