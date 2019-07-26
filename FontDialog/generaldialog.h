#ifndef GENERALDIALOG_H
#define GENERALDIALOG_H

#include <QWidget>

namespace Ui {
class GeneralDialog;
}

class GeneralDialog : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralDialog(QWidget *parent = nullptr);
    ~GeneralDialog();

private:
    Ui::GeneralDialog *ui;
};

#endif // GENERALDIALOG_H
