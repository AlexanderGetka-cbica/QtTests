#ifndef GENERALDIALOG_H
#define GENERALDIALOG_H

#include <QWidget>
#include <QObject>

namespace Ui {
class GeneralDialog;
}

class GeneralDialog : public QWidget
{
    Q_OBJECT

public:
    enum ThemeType{Light,Dark};

    explicit GeneralDialog(QWidget *parent = nullptr);
    ~GeneralDialog();

    Q_ENUM(ThemeType)

public slots:
    void OnChangeTheme(int);

private:
    Ui::GeneralDialog *ui;
};

#endif // GENERALDIALOG_H
