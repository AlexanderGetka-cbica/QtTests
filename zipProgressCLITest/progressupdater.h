#ifndef PROGRESSUPDATER_H
#define PROGRESSUPDATER_H

#include <QObject>
#include <QDebug>

class ProgressUpdater : public QObject
{
    Q_OBJECT
public:
    ProgressUpdater(){}
    ~ProgressUpdater(){}

    public slots:

    void UpdateProgress(int progress)
    {
        qDebug() << " progress = " << progress << endl;
    }
};


#endif // PROGRESSUPDATER_H
