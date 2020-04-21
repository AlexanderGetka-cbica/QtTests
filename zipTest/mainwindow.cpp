#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include "qzipreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mInputZipFile = "C:\\Users\\singhas\\Downloads\\incise_icons.zip";
    mOutputDirecty = "C:\\workspace\\QtTests\\zipTest";

    //signals/slots
    connect(ui->inBtn,SIGNAL(clicked()),this,SLOT(OnInputButtonClicked()));
    connect(ui->outBtn,SIGNAL(clicked()),this,SLOT(OnOutputDirectoryButtonClicked()));
    connect(ui->runBtn,SIGNAL(clicked()),this,SLOT(OnRunButtonClicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnInputButtonClicked()
{
    qDebug() << "OnInputButtonClicked" << endl;
    mInputZipFile = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QDir::currentPath(),
                                                    tr("Zipball(*.zip *.7z *.tar.gz)"));
}

void MainWindow::OnOutputDirectoryButtonClicked()
{
    qDebug() << "OnOutputDirectoryButtonClicked" << endl;
    mOutputDirecty = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
}

void MainWindow::OnRunButtonClicked()
{
    qDebug() << "OnRunButtonClicked" << endl;
    QZipReader zr(mInputZipFile);
    bool ret = zr.extractAll(mOutputDirecty);
    qDebug() << " extracted = " << ret << endl;

}
