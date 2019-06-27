#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QFontDialog>
#include <QDebug>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

    this->m_FontDialog = new QFontDialog(ui->stackedWidget);
    this->m_FontDialog->setWindowFlags(Qt::SubWindow);
    this->m_FontDialog->setOptions(
                /* do not use native dialog */
                QFontDialog::DontUseNativeDialog
                /* you don't need to set it, but if you don't set this
                                        the "OK" and "Cancel" buttons will show up, I don't
                                        think you'd want that. */
                | QFontDialog::NoButtons
                );
    ui->stackedWidget->insertWidget(0,this->m_FontDialog);
    ui->stackedWidget->insertWidget(1,new QWidget(ui->stackedWidget));

    connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(OnItemSelectionChanged()));
    //this->m_FontDialog->showMaximized();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

QFontDialog *PreferencesDialog::GetFontDialog()
{
    return this->m_FontDialog;
}

void PreferencesDialog::SetApplicationFont()
{
    qDebug() << " SetApplicationFont " << endl;
    qDebug() << ui->stackedWidget->currentIndex() << endl;
    if(ui->stackedWidget->currentIndex() == 0)
    {
        qDebug() << " inside if block " << endl;
        qApp->setFont(this->m_FontDialog->currentFont());
    }
}

void PreferencesDialog::OnItemSelectionChanged()
{
    int currentItemIndex = ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(currentItemIndex);
}
