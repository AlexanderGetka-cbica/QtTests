#include "mainwindow.h"
#include <QApplication>
//#include "ThreadedExtraction.h"
#include "ApplicationDownloadManager.h"
//#include "ThreadedDownload.h"
#include "progressupdater.h"
#include <QObject>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QString mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/SampleData_1.6.0/PseudoProgressionEstimator.zip";
    QString mDownloadLink = "ftp://www.nitrc.org/home/groups/captk/downloads/libra.zip";
    QString mDownloadFolder = "C:/workspace/QtTests/DownloadExtractCLITest/";

    ApplicationDownloadManager *adm = new ApplicationDownloadManager();
    adm->SetDownloadLink(mDownloadLink);
    adm->SetDownloadFolder(mDownloadFolder);
    adm->getApplication("libra", true);

//    ThreadedDownload *td = new ThreadedDownload();
//    td->SetDownloadLink(mDownloadLink);
//    td->SetDownloadFolder(mDownloadFolder);
//    QObject::connect(td, &ThreadedDownload::finished, td, &QObject::deleteLater);

//    QTimer::singleShot(0,td,SLOT(start()));
    return a.exec();
}

