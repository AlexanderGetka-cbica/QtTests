#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void OnInputButtonClicked();
    void OnOutputDirectoryButtonClicked();
    void OnRunButtonClicked();

private:
    Ui::MainWindow *ui;
    QString mInputZipFile, mOutputDirecty;
};

#endif // MAINWINDOW_H
