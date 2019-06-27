#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
class QFontDialog;

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog();

    QFontDialog* GetFontDialog();

    void SetApplicationFont();

public slots:

    void OnItemSelectionChanged();

private:
    Ui::PreferencesDialog *ui;
    QFontDialog *m_FontDialog;
};

#endif // PREFERENCESDIALOG_H
