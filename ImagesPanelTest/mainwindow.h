#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fImagesPanel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnAddTableEntry();
    void CloseImage(QTableWidgetItem*);
    void CloseAllImages();
    void overlayChanged();

private:
    Ui::MainWindow *ui;
    fImagesPanel* imagesPanel;
    static int count;
};

#endif // MAINWINDOW_H
