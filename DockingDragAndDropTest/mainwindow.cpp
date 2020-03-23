#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dragndropdockwidget.h"
#include <QListWidget>
#include <QDropEvent>
#include <iostream>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_docker = new DragnDropDockWidget(this);

    m_docker->setFeatures(QDockWidget::DockWidgetFloatable);
    m_docker->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::TopDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea );
    m_docker->setWindowFlags(Qt::Window); // Change this to subwindow (or another window flag) to preview
    //m_docker->setFloating(true);
    addDockWidget(Qt::TopDockWidgetArea, m_docker);
    QListWidget* example_list = new QListWidget(m_docker);
    example_list->addItems(QStringList()
                << "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
                << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
                << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
                << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
                << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
                << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
    m_docker->setWidget(example_list);
    this->setAcceptDrops(true);
    m_docker->show();
    connect(m_docker, SIGNAL(dragEnterReceived(QDragEnterEvent*)), this, SLOT(dragEnterEvent(QDragEnterEvent*)));
    connect(m_docker, SIGNAL(dragAndDropReceived(QDropEvent*)), this, SLOT(dropEvent(QDropEvent*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDragEnterEvent(QDragEnterEvent* event) {
    std::cout<<"DragEnter event has reached the main window."<<std::endl;
    dragEnterEvent(event);
}
void MainWindow::receiveDropEvent(QDropEvent* event) {
    std::cout<<"Drop event has reached the main window."<<std::endl;
    dropEvent(event);
}

void MainWindow::dropEvent(QDropEvent* event) {

    // could break this off into a function
    QList<QUrl> urls = event->mimeData()->urls();
    QStringList vectorOfFiles;
    for (int i = 0; i < (int)urls.size(); i++)
    {
      std::cout<<urls[i].toString().toStdString()<<std::endl;
    }
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
        std::cout<<"Drag event detected on main window"<<std::endl;
    }
}


