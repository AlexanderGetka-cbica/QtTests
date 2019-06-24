#include <QApplication>
#include <QStringList>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    //a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    a.setStyleSheet(
                "QWidget \
    {\
      color: rgb(255 ,255, 255); \
      background-color: rgb(50, 50, 50); \
    } \
                    QHeaderView::section \
    {\
                        color: rgb(255 ,255, 255);\
                        background-color: rgb(50, 50, 50);\
                    }\
                QToolButton::hover\
                {\
                  border: 2px solid rgb(0,140,149);\
                }\
                ");

    QStringList files = QFileDialog::getOpenFileNames(nullptr,
                                                      QObject::tr("Load Images"),
                                                      QDir::currentPath(),
                                                      "Images (*.png *.xpm *.jpg)",
                                                      nullptr,
                                                      QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog);

    return a.exec();
}
