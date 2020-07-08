#include <QCoreApplication>
#include "ApplicationPreferences.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    ApplicationPreferences::GetInstance()->AddApplication("libra");
//    ApplicationPreferences::GetInstance()->AddApplication("deepmedic");
//    ApplicationPreferences::GetInstance()->AddApplication("libra");

//    ApplicationPreferences::GetInstance()->SerializePreferences();
    ApplicationPreferences::GetInstance()->DeSerializePreferences();

    qDebug() << " Display preferences " << endl;
    ApplicationPreferences::GetInstance()->DisplayPreferences();

    ApplicationPreferences::UserInstalledAppsSettings usrsettings = ApplicationPreferences::GetInstance()->GetUserInstalledAppsSettingsForApp("libra");
    qDebug() << " Libra download started: " << usrsettings.DownloadStarted << endl;
    qDebug() << " Libra download finished: " << usrsettings.DownloadFinished << endl;
    qDebug() << " Libra extraction started: " << usrsettings.ExtractionStarted << endl;
    qDebug() << " Libra extraction finished: " << usrsettings.ExtractionFinished << endl;
    //return a.exec();
}
