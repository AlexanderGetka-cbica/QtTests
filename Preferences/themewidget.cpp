#include "themewidget.h"
#include "ui_themewidget.h"
#include <QDebug>

ThemeWidget::ThemeWidget(QWidget *parent) :
    IPreferencePage(parent),
    ui(new Ui::ThemeWidget)
{
    ui->setupUi(this);
}

ThemeWidget::~ThemeWidget()
{
    delete ui;
}

void ThemeWidget::OnOkay()
{
    qDebug() << "ThemeWidget::OnOKay()" << endl;
}

void ThemeWidget::OnCancel()
{
    qDebug() << "ThemeWidget::OnCancel()" << endl;
}
