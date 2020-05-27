#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fAppDownloadDialog.h"

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
    void OnAppDownloadButtonClicked();

    void unzipArchive(std::string fullPath);

private:
    Ui::MainWindow *ui;
    fAppDownloadDialog *appDlg;
    QString mDownloadLink;
    QString mDownloadFolder;
};

#endif // MAINWINDOW_H
