#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QScreen*> scr = qApp->screens();
    qDebug() << "# screens = " <<  scr.size() << endl;
    qDebug() << " width, height = " << scr[0]->size() << endl;
    qDebug() << " depth = " << scr[0]->depth() << endl;
    qDebug() << " device pixel ratio = " << scr[0]->devicePixelRatio() << endl;
    qDebug() << " available geometru = " << scr[0]->availableGeometry() << endl;
    qDebug() << " available virtual geometru = " << scr[0]->availableVirtualGeometry() << endl;
    qDebug() << "available virtual size = " << scr[0]->availableVirtualSize() << endl;
    //QRect 	geometry() const
    //QPixmap 	grabWindow(WId window, int x = 0, int y = 0, int width = -1, int height = -1)
    //QPlatformScreen *	handle() const
    qDebug() << "logical dots per inch = " << scr[0]->logicalDotsPerInch() << endl;
    qDebug() << "logical dots per inch X = " << scr[0]->logicalDotsPerInchX() << endl;
    qDebug() << "logical dots per inch Y = " << scr[0]->logicalDotsPerInchY() << endl;
    qDebug() << "manufacturer = " << scr[0]->manufacturer() << endl;
    qDebug() << " model = " << scr[0]->model() << endl;
    qDebug() << "name = " << scr[0]->name() << endl;
    qDebug() << " native orientation = " << scr[0]->nativeOrientation() << endl;
    qDebug() << " orientation = " << scr[0]->orientation() << endl;
    //Qt::ScreenOrientations 	orientationUpdateMask() const
    qDebug() << " physical dots per inch = " << scr[0]->physicalDotsPerInch() << endl;
    qDebug() << "physical dots per inch X = " << scr[0]->physicalDotsPerInchX() << endl;
    qDebug() << " physical dots per inch Y = " << scr[0]->physicalDotsPerInchY() << endl;
    qDebug() << "physical size = " << scr[0]->physicalSize() << endl;
    qDebug() << " primary orientation = " << scr[0]->primaryOrientation() << endl;
    qDebug() << " refresh rate = " << scr[0]->refreshRate() << endl;
    qDebug() << "serial number = " << scr[0]->serialNumber() << endl;
    //void 	setOrientationUpdateMask(Qt::ScreenOrientations mask)
    qDebug() << " size = " << scr[0]->size() << endl;
    //QTransform 	transformBetween(Qt::ScreenOrientation a, Qt::ScreenOrientation b, const QRect &target) const
    qDebug() << " virtual geometry = " << scr[0]->virtualGeometry() << endl;
    //QList<QScreen *> 	virtualSiblings() const
    qDebug() << "virtual size = " << scr[0]->virtualSize() << endl;

    qDebug() << " width = " << scr[0]->size().width() << " " << "height = " << scr[0]->size().height() << endl;

    if( scr[0]->size().width() < 1200 || scr[0]->size().height() < 1024 )
    {
        ui->dockWidget_2->setFloating(true);
        //qDebug() << " width = " << scr[0]->size().width() << " " << "height = " << scr[0]->size().height() << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
