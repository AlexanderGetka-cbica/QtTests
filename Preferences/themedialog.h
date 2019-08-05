#ifndef THEMEDIALOG_H
#define THEMEDIALOG_H

#include <QDialog>

namespace Ui {
class ThemeDialog;
}

class ThemeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemeDialog(QWidget *parent = nullptr);
    ~ThemeDialog();

private:
    Ui::ThemeDialog *ui;
};

#endif // THEMEDIALOG_H
