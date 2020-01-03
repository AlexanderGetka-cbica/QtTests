#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

int MainWindow::count = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imagesPanel = new fImagesPanel();

    //! add new imagespanel
    ui->tabWidget->addTab(imagesPanel,"Images Panel");

    //! connect
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnAddTableEntry()));
    connect(imagesPanel,SIGNAL(sigOverlayChanged()),this,SLOT(overlayChanged()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnAddTableEntry()
{
    //imagesPanel->NewImageLoaded(QString::number(count), "test", count, "strImageType", 0, this);
    imagesPanel->AddDummyItem(QString::number(count), "test", count, "strImageType", 0, this);
    count++;
}

void MainWindow::CloseImage(QTableWidgetItem *)
{
    qDebug() << "MainWindow::CloseImage(QTableWidgetItem *)" << endl;
}

void MainWindow::CloseAllImages()
{
    qDebug() << "MainWindow::CloseAllImages()" << endl;
}

void MainWindow::overlayChanged()
{
    qDebug() << "MainWindow::overlayChanged()" << endl;
}
