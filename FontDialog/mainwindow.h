#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class PreferencesDialog;

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
    void OnPreferencesClicked();

private:
    void LoadSettings();
    void SaveSettings();

    Ui::MainWindow *ui;
    PreferencesDialog *m_PreferencesDialog;

};

#endif // MAINWINDOW_H
