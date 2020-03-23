#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dragndropdockwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void dropEvent(QDropEvent* event);
    //void dragEnterEvent(QDragEnterEvent* event);

    DragnDropDockWidget* m_docker;

public slots:
    void receiveDragEnterEvent(QDragEnterEvent* event);
    void receiveDropEvent(QDropEvent* event);
    void dropEvent(QDropEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
