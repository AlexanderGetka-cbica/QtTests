//#include "mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}


#include <QApplication>
#include <QWidget>
#include <QColorDialog>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = new QWidget(nullptr);

    QColorDialog *cDialog = new QColorDialog(w);
    cDialog->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    cDialog->setWindowFlags(Qt::Widget);
    cDialog->setOptions(
                /* do not use native dialog */
                QColorDialog::DontUseNativeDialog
                /* you don't need to set it, but if you don't set this
                                        the "OK" and "Cancel" buttons will show up, I don't
                                        think you'd want that. */
                | QColorDialog::NoButtons
                );

    QHBoxLayout *hl = new QHBoxLayout(w);
    hl->addWidget(cDialog);
    //w->setLayout(hl);

    w->show();
    return a.exec();
}
