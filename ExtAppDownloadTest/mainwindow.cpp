#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    appDlg = new fAppDownloadDialog();

    mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/models/SBRT.zip";
    mDownloadFolder = "C:/workspace/QtTests/ExtAppDownloadTest";

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnAppDownloadButtonClicked()));
    connect( appDlg, SIGNAL(doneDownload(std::string)), this, SLOT(unzipArchive(std::string)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnAppDownloadButtonClicked()
{
    appDlg->SetDownloadPath(mDownloadFolder.toStdString());

    appDlg->SetDownloadLink(mDownloadLink.toStdString());
    appDlg->show();
}

void MainWindow::unzipArchive(std::string fullPath)
{

 qDebug() << " extracting zipball at: " << fullPath.c_str() << endl;

}
