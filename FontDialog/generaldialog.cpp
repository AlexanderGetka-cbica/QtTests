#include "generaldialog.h"
#include "ui_generaldialog.h"

GeneralDialog::GeneralDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralDialog)
{
    ui->setupUi(this);
}

GeneralDialog::~GeneralDialog()
{
    delete ui;
}
