#include <QCoreApplication>
#include <QOperatingSystemVersion>
#include <QApplication>
#include <QStorageInfo>
#include <QNetworkInterface>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOffscreenSurface>
#include <QDebug>
#include <QTextEdit>
#include "systeminformation.h"
#include "systeminformationdisplaywidget.h"
#include "SystemInformationDisplayWidget2.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc,argv);

    SystemInformationDisplayWidget w;
    SystemInformation s;

    QStringList sl = s.GetSystemInformation();
    //QStringList sl = SystemInformation::GetSystemInformation();
    w.SetInformation(sl);
    w.show();

    SystemInformationDisplayWidget2 w2;
    w2.SetInformation(sl);
    w2.show();

    return a.exec();
}
