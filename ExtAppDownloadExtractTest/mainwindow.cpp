#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "ApplicationPreferences.h"
#include "qzipreader.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! load preferences
    ApplicationPreferences::GetInstance()->DeSerializePreferences();
    ApplicationPreferences::GetInstance()->DisplayPreferences();

    appDlg = new fAppDownloadDialog();

    //mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/models/SBRT.zip";
    mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/SampleData_1.6.0/PseudoProgressionEstimator.zip";
    mDownloadFolder = "C:/workspace/QtTests/ExtAppDownloadExtractTest";

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnAppDownloadButtonClicked()));
    connect( appDlg, SIGNAL(doneDownload(std::string)), this, SLOT(unzipArchive(std::string)));

}

MainWindow::~MainWindow()
{
    delete ui;

    ApplicationPreferences::GetInstance()->SerializePreferences();
}

void MainWindow::OnAppDownloadButtonClicked()
{
    appDlg->SetDownloadPath(mDownloadFolder.toStdString());

    appDlg->SetDownloadLink(mDownloadLink.toStdString());
    appDlg->show();
}

void MainWindow::unzipArchive(std::string fullPath)
{

    ApplicationPreferences::GetInstance()->SetLibraExtractionStartedStatus(QVariant("true").toString());


    qDebug() << " extracting zipball at: " << fullPath.c_str() << endl;

    QFileInfo fi(fullPath.c_str());
    QString extractionpath = fi.absolutePath();

    qDebug() << "path = " << extractionpath << endl;

    if (QFile::exists(fullPath.c_str()))
    {
        QZipReader zr(fullPath.c_str());
        bool ret = zr.extractAll(extractionpath);
        if(ret)
        {
            ApplicationPreferences::GetInstance()->SetLibraExtractionFinishedStatus(QVariant("true").toString());

            //after extraction remove the zip
            bool successfullyremoved = QFile::remove(fullPath.c_str());
            if(successfullyremoved)
            {
                //log
            }
        }
        else
        {
            ApplicationPreferences::GetInstance()->SetLibraExtractionFinishedStatus(QVariant("false").toString());
        }
    }

    //serialize only once
    ApplicationPreferences::GetInstance()->SerializePreferences();
}
