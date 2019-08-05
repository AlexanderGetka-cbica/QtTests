#include "themedialog.h"
#include "ui_themedialog.h"

ThemeDialog::ThemeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemeDialog)
{
    ui->setupUi(this);
}

ThemeDialog::~ThemeDialog()
{
    delete ui;
}
