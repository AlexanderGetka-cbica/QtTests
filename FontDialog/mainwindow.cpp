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
    this->LoadSettings();

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
        qDebug() << " Accepted" << endl;
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
        this->setStyleSheet(this->m_PreferencesDialog->GetColorStyleSheet());
    }
    else
        qDebug() << " Rejected " << endl;

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
    QSettings appSettings("appSettings.ini",QSettings::IniFormat);
    QString fontFamily = appSettings.value("app.font.family",QString()).toString();
    int fontSize = appSettings.value("app.font.size", 12).toInt();
    bool IsFontBold = appSettings.value("app.font.bold", false).toBool();
    bool IsFontItalic = appSettings.value("app.font.italic", false).toBool();
    QFont f = appSettings.value("app.font",QFont()).value<QFont>();

    qDebug() << "font           : " << f.toString();
    qDebug() << "font family    : " << fontFamily;
    qDebug() << "font size    : " << fontSize;
    qDebug() << "font Bold    : " << IsFontBold;
    qDebug() << "font Italic    : " << IsFontItalic;

    qApp->setFont(f);
}

void MainWindow::SaveSettings()
{
    QFontDialog *fd = this->m_PreferencesDialog->GetFontDialog();
    QFont f = fd->currentFont();
    QSettings appSettings("appSettings.ini",QSettings::IniFormat);
    appSettings.setValue("app.font.family",f.family());
    appSettings.setValue("app.font.size",f.pointSize());
    appSettings.setValue("app.font.bold",f.bold());
    appSettings.setValue("app.font.italic",f.italic());
    appSettings.setValue("app.font",f.toString());

    //appSettings.setValue("fontSize",fd->fonts)
}
