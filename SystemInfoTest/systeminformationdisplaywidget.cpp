#include "systeminformationdisplaywidget.h"
#include "ui_systeminformationdisplaywidget.h"

SystemInformationDisplayWidget::SystemInformationDisplayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemInformationDisplayWidget)
{
    ui->setupUi(this);
    ui->textEdit->setMinimumHeight(500);

    connect(ui->CopyToClipboardPushButton,SIGNAL(clicked()),this,SLOT(OnCopyToClipboardBtnClicked()));
}

SystemInformationDisplayWidget::~SystemInformationDisplayWidget()
{
    if (ui->label)
        delete ui->label;
    if (ui->textEdit)
        delete ui->textEdit;
    if (ui->CopyToClipboardPushButton)
        delete ui->CopyToClipboardPushButton;
    if (ui->horizontalLayout)
        delete ui->horizontalLayout;
    if (ui->verticalLayout)
        delete ui->verticalLayout;
    delete ui;
}

void SystemInformationDisplayWidget::SetInformation(QStringList sl)
{
    foreach(QString str, sl)
    {
        ui->textEdit->append(str);
    }
}

void SystemInformationDisplayWidget::ClearInformation()
{
    ui->textEdit->clear();
}

void SystemInformationDisplayWidget::OnCopyToClipboardBtnClicked()
{
    ui->textEdit->selectAll();
    ui->textEdit->copy();

}
