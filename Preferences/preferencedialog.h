#ifndef PREFERENCEDIALOG_H
#define PREFERENCEDIALOG_H

#include <QDialog>

namespace Ui {
class PreferenceDialog;
}
class FontDialog;
class ThemeDialog;

class FontWidget;
class ThemeWidget;
class IPreferencePage;

class PreferenceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferenceDialog(QWidget *parent = nullptr);
    ~PreferenceDialog();

public slots:
    void OnItemSelectionChanged();
    void OnAccepted();
    void OnRejected();

private:
    Ui::PreferenceDialog *ui;
//    FontDialog *m_FontDialog;
//    ThemeDialog *m_ThemeDialog;

    FontWidget *m_FontWidget;
    ThemeWidget *m_ThemeWidget;
    IPreferencePage *m_PreferencePage;

};

#endif // PREFERENCEDIALOG_H
