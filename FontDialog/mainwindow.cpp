#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFontDialog>
#include "preferencesdialog.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->m_PreferencesDialog = new PreferencesDialog(nullptr);
    QObject::connect(ui->actionPreferences,SIGNAL(triggered()),this,SLOT(OnPreferencesClicked()));
}

MainWindow::~MainWindow()
{
    this->SaveSettings();
    delete ui;
}

void MainWindow::OnPreferencesClicked()
{
    qDebug() << " OnPreferencesClicked " << endl;
    int r = this->m_PreferencesDialog->exec();
    if(r == PreferencesDialog::Accepted)
    {
        //this->m_PreferencesDialog->accept();
        this->m_PreferencesDialog->SetApplicationFont();
        QFontDialog *fd = this->m_PreferencesDialog->GetFontDialog();
        QFont font = fd->currentFont();
        qDebug() << "font           : " << font;
        qDebug() << "font weight    : " << font.weight();
        qDebug() << "font family    : " << font.family();
        qDebug() << "font style     : " << font.style();  //  StyleNormal = 0, StyleItalic = 1, StyleOblique = 2
        qDebug() << "font pointSize : " << font.pointSize();
        //qApp->setFont(font);
    }

//    bool ok;
//    QFont font = QFontDialog::getFont(
//                &ok,
//                qApp->font(),
//                //QFont( "Arial", 18 ),
//                this,
//                tr("Pick a font") );
//    if( ok )
//    {
//        qDebug() << "font           : " << font;
//        qDebug() << "font weight    : " << font.weight();
//        qDebug() << "font family    : " << font.family();
//        qDebug() << "font style     : " << font.style();  //  StyleNormal = 0, StyleItalic = 1, StyleOblique = 2
//        qDebug() << "font pointSize : " << font.pointSize();
//        qApp->setFont(font);
    //    }
}

void MainWindow::LoadSettings()
{

}

void MainWindow::SaveSettings()
{
    QFontDialog *fd = this->m_PreferencesDialog->GetFontDialog();
    QSettings appSettings("appSettings.ini",QSettings::IniFormat);
    appSettings.setValue("font",fd->currentFont());
    //appSettings.setValue("fontSize",fd->fonts)
}
