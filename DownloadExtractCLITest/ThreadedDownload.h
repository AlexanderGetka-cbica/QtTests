#ifndef THREADEDDOWNLOAD_H
#define THREADEDDOWNLOAD_H

#include <QThread>

class ThreadedDownload : public QThread
{
    Q_OBJECT
public:
    explicit ThreadedDownload(QObject *parent = 0);
    void run();

    void SetDownloadFolder(QString folder)
    {
        this->downloadFolder = folder;
    }

    void SetDownloadLink(QString link)
    {
        this->downloadLink = link;
    }

signals:
    
public slots:

private:
        QString downloadFolder, downloadLink;
    
};

#endif // THREADEDDOWNLOAD_H
