#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QFontDialog>
#include <QColorDialog>
#include <QSizePolicy>
#include <QDebug>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

    this->m_FontDialog = new QFontDialog(ui->stackedWidget);
    //this->m_FontDialog->setStyleSheet("background-color:blue;");
    this->m_FontDialog->setWindowFlags(Qt::SubWindow);
    this->m_FontDialog->setOptions(
                /* do not use native dialog */
                QFontDialog::DontUseNativeDialog
                /* you don't need to set it, but if you don't set this
                                        the "OK" and "Cancel" buttons will show up, I don't
                                        think you'd want that. */
                | QFontDialog::NoButtons
                );
    this->m_FontDialog->setSizeGripEnabled(false);

    this->m_ColorDialog = new QColorDialog(ui->stackedWidget);
    //this->m_ColorDialog->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //this->m_ColorDialog->setStyleSheet("background-color:green;");
    this->m_ColorDialog->setWindowFlags(Qt::Widget);
    this->m_ColorDialog->setOptions(
                /* do not use native dialog */
                QColorDialog::DontUseNativeDialog
                /* you don't need to set it, but if you don't set this
                                        the "OK" and "Cancel" buttons will show up, I don't
                                        think you'd want that. */
                | QColorDialog::NoButtons
                );
    ui->stackedWidget->insertWidget(0,this->m_FontDialog);
    ui->stackedWidget->insertWidget(1,this->m_ColorDialog);
    ui->stackedWidget->insertWidget(2,new QWidget(ui->stackedWidget));

    connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(OnItemSelectionChanged()));
    //this->m_FontDialog->showMaximized();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

QFontDialog *PreferencesDialog::GetFontDialog()
{
    return this->m_FontDialog;
}

void PreferencesDialog::SetApplicationFont()
{
    qDebug() << " SetApplicationFont " << endl;
    qDebug() << ui->stackedWidget->currentIndex() << endl;
    //if(ui->stackedWidget->currentIndex() == 0)
    {
        qDebug() << " inside if block " << endl;
        //qApp->setFont(this->m_FontDialog->currentFont());
        QColor c = this->m_ColorDialog->currentColor();
        int r = c.red();
        int g = c.green();
        int b = c.blue();
        QString rgbstr = "(" + QString::number(r) + ","
                + QString::number(g) + ","
                + QString::number(b) + ");";
        this->m_colorStyleSheetString = "background-color:rgb" + rgbstr;
        qDebug() << " color str = " << m_colorStyleSheetString << endl;
        //qApp->setStyleSheet(m_colorStyleSheetString);
        //qApp->setProperty("urgent", true);
        //ui->listWidget->setStyleSheet(colorstr);
    }
}

QString PreferencesDialog::GetColorStyleSheet()
{
    return this->m_colorStyleSheetString;
}

void PreferencesDialog::OnItemSelectionChanged()
{
    int currentItemIndex = ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(currentItemIndex);
}
