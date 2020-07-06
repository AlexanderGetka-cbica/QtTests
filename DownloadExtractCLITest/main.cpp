#include "mainwindow.h"
#include <QApplication>
//#include "ThreadedExtraction.h"
#include "ApplicationDownloadManager.h"
//#include "ThreadedDownload.h"
#include "progressupdater.h"
#include <QObject>
#include <QTimer>
#include <iostream>

void UpdateProgress(int progress)
{
    std::cout << " progress = " << progress << "\t\r" << std::flush;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    std::cout << " progress = " << 0 << std::endl;/*<< "\t\r" << std::flush;*/

//    std::cout << " hello world " << std::endl;

    QString mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/SampleData_1.6.0/PseudoProgressionEstimator.zip";
    //QString mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/libra.zip";
    QString mDownloadFolder = "C:/workspace/Qt/downloadextractCLItestOut/";

    ApplicationDownloadManager *adm = new ApplicationDownloadManager();
    QObject::connect(adm,&ApplicationDownloadManager::updateProgressSignal,UpdateProgress);
    adm->SetDownloadLink(mDownloadLink);
    adm->SetDownloadFolder(mDownloadFolder);
    adm->getApplication("libra", true);
    //QTimer::singleShot(0,adm,SLOT(getApplication("libra", true)));

//    ThreadedDownload *td = new ThreadedDownload();
//    td->SetDownloadLink(mDownloadLink);
//    td->SetDownloadFolder(mDownloadFolder);
//    QObject::connect(td, &ThreadedDownload::finished, td, &QObject::deleteLater);

//    QTimer::singleShot(0,td,SLOT(start()));
    return a.exec();
    //return 0;
}

