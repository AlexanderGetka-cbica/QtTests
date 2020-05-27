#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMimeData>
#include <mydockwidget.h>

int MainWindow::count = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imagesPanel = new fImagesPanel();
    drawingPanel = new fDrawingPanel();
    //this->ui->dockWidget->hide();

    //MyDockWidget *dkw = new MyDockWidget();
    //this->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,dkw);

    //! add new imagespanel
    ui->tabWidget->addTab(imagesPanel,"Images Panel");
    ui->tabWidget->addTab(drawingPanel,"Drawing Panel");

    //! connect
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnAddTableEntry()));
    connect(imagesPanel,SIGNAL(sigOverlayChanged()),this,SLOT(overlayChanged()));

    this->setAcceptDrops(true);
    //this->ui->dockWidget->setAcceptDrops(true);
    //this->ui->dockWidgetContents->setAcceptDrops(true);
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

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    foreach (const QUrl &url, event->mimeData()->urls())
    {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
    }
}
