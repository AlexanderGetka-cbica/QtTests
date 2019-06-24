#include <QApplication>
#include <QStringList>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    //a.setAttribute(Qt::AA_EnableHighDpiScaling);

    QStringList files = QFileDialog::getOpenFileNames(nullptr,
                                                      QObject::tr("Load Images"),
                                                      QDir::currentPath(),
                                                      "Images (*.png *.xpm *.jpg)",
                                                      nullptr,
                                                      QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog);

    return a.exec();
}
