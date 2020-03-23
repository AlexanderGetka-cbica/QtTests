#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include "PreferencesDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PreferencesDialog* preferencesDialog = new PreferencesDialog(this);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QVBoxLayout* greaterLayout = new QVBoxLayout;
    QTextEdit* textEdit = new QTextEdit();

    QPushButton* button1 = new QPushButton("button1");
    QPushButton* button2 = new QPushButton("Show Preferences Menu", this);
    connect(button2, SIGNAL(clicked()), preferencesDialog, SLOT(exec()));

    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    greaterLayout->addWidget(new QLabel("test text label", this));
    greaterLayout->addWidget(textEdit);
    greaterLayout->addLayout(buttonLayout);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(greaterLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

