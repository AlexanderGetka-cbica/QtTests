#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "preferencedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->m_PreferenceDialog = new PreferenceDialog(this);
    QObject::connect(ui->actionPreferences,SIGNAL(triggered()),this,SLOT(OnPreferencesClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnPreferencesClicked()
{
    qDebug() << " OnPreferencesClicked " << endl;
    int r = this->m_PreferenceDialog->exec();
    //this->m_PreferenceDialog->done(r);
//    if(r == PreferenceDialog::Accepted)
//    {
//        qDebug() << " Accepted" << endl;
//    }
//    else
//        qDebug() << " Rejected" << endl;

}
