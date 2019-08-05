#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class PreferenceDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnPreferencesClicked();

private:
    Ui::MainWindow *ui;
    PreferenceDialog *m_PreferenceDialog;
};

#endif // MAINWINDOW_H
