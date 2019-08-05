#include "preferencedialog.h"
#include "ui_preferencedialog.h"
#include "fontdialog.h"
#include "themedialog.h"

#include "fontwidget.h"
#include "themewidget.h"
#include "ipreferencepage.h"

#include <QDebug>

PreferenceDialog::PreferenceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenceDialog)
{
    ui->setupUi(this);

//    this->m_FontDialog = new FontDialog(ui->stackedWidget);
//    this->m_ThemeDialog = new ThemeDialog(ui->stackedWidget);

//    ui->stackedWidget->insertWidget(0,this->m_FontDialog);
//    ui->stackedWidget->insertWidget(1,this->m_ThemeDialog);

    this->m_FontWidget = new FontWidget(ui->stackedWidget);
    this->m_ThemeWidget = new ThemeWidget(ui->stackedWidget);

    ui->stackedWidget->insertWidget(0,this->m_FontWidget);
    ui->stackedWidget->insertWidget(1,this->m_ThemeWidget);

    connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(OnItemSelectionChanged()));
    connect(this,SIGNAL(accepted()),this,SLOT(OnAccepted()));
    connect(this,SIGNAL(rejected()),this,SLOT(OnRejected()));
}

PreferenceDialog::~PreferenceDialog()
{
    delete ui;
}

void PreferenceDialog::OnItemSelectionChanged()
{
    qDebug() << " OnPreferencesClicked " << endl;
    int currentItemIndex = ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(currentItemIndex);
    this->m_PreferencePage = qobject_cast<IPreferencePage*>(ui->stackedWidget->currentWidget());
	if (this->m_PreferencePage = nullptr)
		qDebug() << "cast failed" << endl;
}

void PreferenceDialog::OnAccepted()
{
    qDebug() << " OnAccepted " << endl;
    this->m_PreferencePage->OnOkay();
}

void PreferenceDialog::OnRejected()
{
    qDebug() << " OnRejected " << endl;
    this->m_PreferencePage->OnCancel();
}
