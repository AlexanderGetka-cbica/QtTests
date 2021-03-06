#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
class QFontDialog;
class QColorDialog;
class GeneralDialog;

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

    QString GetColorStyleSheet();

public slots:

    void OnItemSelectionChanged();

private:
    Ui::PreferencesDialog *ui;
    QFontDialog *m_FontDialog;
    QColorDialog *m_ColorDialog;
    GeneralDialog *m_GeneralDialog;
    QString m_colorStyleSheetString;
};

#endif // PREFERENCESDIALOG_H
