#include "mainwindow.h"
#include <QApplication>
#include "ThreadedExtraction.h"
#include "qzipreader.h"
#include "progressupdater.h"
#include <QObject>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QString mInputZipFile = "C:\\Users\\singhas\\Downloads\\itksnap-master.zip";
    QString mOutputDirecty = "C:\\workspace\\QtTests\\zipProgressCLITest";

    //working - start
//    QZipReader *zr = new QZipReader(mInputZipFile);
//    QObject::connect(zr,&QZipReader::progress,UpdateProgress);
//    bool ret = zr->extractAll(mOutputDirecty);
    //working - start

    ProgressUpdater *pu = new ProgressUpdater();
    ThreadedExtraction* asyncExtract = new ThreadedExtraction();
    asyncExtract->setFullPath(mInputZipFile);
    asyncExtract->setExtractPath(mOutputDirecty);
    QObject::connect(asyncExtract, &ThreadedExtraction::finished, asyncExtract, &QObject::deleteLater);
    //QObject::connect(asyncExtract,&ThreadedExtraction::updateProgressSignal,UpdateProgress);
    QObject::connect(asyncExtract,SIGNAL(updateProgressSignal(int, std::string, int)),
                     pu,SLOT(UpdateProgress(int)));
    //asyncExtract->start();

    //while(!asyncExtract->isFinished())
    //    QApplication::processEvents();

    QTimer::singleShot(0,asyncExtract,SLOT(start()));

    //bool ret = asyncExtract->wait();
    qDebug() << "thread returned = "/*<< ret */<< endl;

    return a.exec();
}

