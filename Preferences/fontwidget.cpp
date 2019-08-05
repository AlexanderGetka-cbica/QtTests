#include "fontwidget.h"
#include "ui_fontwidget.h"
#include <QDebug>

FontWidget::FontWidget(QWidget *parent) :
    IPreferencePage(parent),
    ui(new Ui::FontWidget)
{
    ui->setupUi(this);
}

FontWidget::~FontWidget()
{
    delete ui;
}

void FontWidget::OnOkay()
{
    qDebug() << "FontWidget::OnOKay()" << endl;
}

void FontWidget::OnCancel()
{
    qDebug() << "FontWidget::OnCancel()" << endl;
}
