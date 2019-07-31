#include "generaldialog.h"
#include "ui_generaldialog.h"
#include <QDebug>
#include <QFile>

GeneralDialog::GeneralDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralDialog)
{
    ui->setupUi(this);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(OnChangeTheme(int)));
}

GeneralDialog::~GeneralDialog()
{
    delete ui;
}

void GeneralDialog::OnChangeTheme(int theme)
{
    ThemeType t = ThemeType(theme);
    qDebug() << t << endl;
    if(t == ThemeType::Dark)
    {
        qDebug() << "dark theme " << endl;
        QFile qss("C:\\workspace\\QtTests\\build-FontDialog-Desktop_Qt_5_11_1_MSVC2017_64bit-Debug\\debug\\darkTheme.qss");
        bool success = qss.open(QFile::ReadOnly);
        qDebug() << "success = " << success << endl;
        if(success)
        {
            qDebug() << "reading succeeded" << endl;
            qApp->setStyleSheet(qss.readAll());
            qss.close();
        }
    }
    else
        qApp->setStyleSheet("");
}
