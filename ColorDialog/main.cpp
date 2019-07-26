#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


//#include <QApplication>
//#include <QWidget>
//#include <QColorDialog>
//#include <QHBoxLayout>
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QWidget *w = new QWidget(nullptr);

//    QColorDialog *cDialog = new QColorDialog();
//    //cDialog->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
//    cDialog->layout()->setSizeConstraint(QLayout::SetDefaultConstraint);
//    cDialog->setWindowFlags(Qt::Widget);
//    cDialog->setOptions(QColorDialog::DontUseNativeDialog
//                 | QColorDialog::NoButtons);

//    QHBoxLayout *hl = new QHBoxLayout(w);
//    hl->addWidget(cDialog);
//    w->setLayout(hl);

//    //cDialog->show();
//    w->show();
//    return a.exec();
//}
