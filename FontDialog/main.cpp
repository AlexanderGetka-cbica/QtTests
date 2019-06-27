#include "mainwindow.h"
#include <QApplication>
#include <QFontDialog>
#include <QWidget>
#include <QStackedWidget>
#include <QSpinBox>
#include <QColorDialog>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFontDialog fd;
    //fd.show();
    MainWindow w;
    w.show();

//    QStackedWidget sw;
//    //QWidget sw;
//    QHBoxLayout hl(&sw);

//    QWidget w1(&sw);
//    QWidget w2(&sw);
//    hl.addWidget(&w1);
//    hl.addWidget(&w2);

//    QSpinBox sb;
//    QColorDialog fd(&sw);
//    fd.setWindowFlags((Qt::SubWindow));
////    fd.setOptions(
////                    /* do not use native dialog */
////                    QColorDialog::DontUseNativeDialog
////                    /* you don't need to set it, but if you don't set this
////                        the "OK" and "Cancel" buttons will show up, I don't
////                        think you'd want that. */
////                    | QColorDialog::NoButtons
////        );

//   // w1.setStyleSheet("background-color: rgb(47, 221, 255);");
//   // w2.setStyleSheet("background-color: rgb(247, 21, 55);");

//    sw.addWidget(&w1);
//    sw.addWidget(&fd);

//    QObject::connect(&sb,SIGNAL(valueChanged(int)),&sw,SLOT(setCurrentIndex(int)));

//    sw.show();
//    sb.show();

    return a.exec();
}

//----
//#include <QApplication>
//#include <QMainWindow>
//#include <QColorDialog>
//#include <QFontDialog>
//#include <QHBoxLayout>
//#include <QStackedWidget>
//#include <QSpinBox>
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QSpinBox sb;
//    /* setup a quick and dirty window */
//    QStackedWidget app;
//    app.setGeometry(250, 250, 600, 400);

//    QFontDialog *colorDialog = new QFontDialog(&app);
//    QWidget w(&app);
//    w.setMinimumWidth(500);
//    QHBoxLayout hl(&app);
//    app.addWidget(colorDialog);
//    app.addWidget(&w);
//    /* set it as our widiget, you can add it to a layout or something */
//    //app.setCentralWidget(colorDialog);
//    /* define it as a Qt::Widget (SubWindow would also work) instead of a dialog */
//    colorDialog->setWindowFlags(Qt::Widget);
//    /* a few options that we must set for it to work nicely */
//    colorDialog->setOptions(
//                /* do not use native dialog */
//                QFontDialog::DontUseNativeDialog
//                /* you don't need to set it, but if you don't set this
//                    the "OK" and "Cancel" buttons will show up, I don't
//                    think you'd want that. */
//                | QFontDialog::NoButtons
//    );

//    QObject::connect(&sb,SIGNAL(valueChanged(int)),&app,SLOT(setCurrentIndex(int)));

//    sb.show();
//    app.show();
//    return a.exec();
//}
