#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->m_ColorDialog = new QColorDialog(this);
    this->m_ColorDialog->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    //this->m_ColorDialog->setStyleSheet("background-color:green;");
    this->m_ColorDialog->setWindowFlags(Qt::Widget);
    this->m_ColorDialog->setOptions(
                /* do not use native dialog */
                QColorDialog::DontUseNativeDialog
                /* you don't need to set it, but if you don't set this
                                        the "OK" and "Cancel" buttons will show up, I don't
                                        think you'd want that. */
                | QColorDialog::NoButtons
                );

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    QHBoxLayout *hl = new QHBoxLayout(centralWidget);
    hl->addWidget(this->m_ColorDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}
