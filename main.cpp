#include "mainwindow.h"
#include <QApplication>
#include "Controller.h"
#include "HTMLWatchlist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{"D:/laborator OOP/GRAFIC/readFilm.txt"};
    FileWatchList *p = new HTMLWatchlist{};
    Controller ctrl(repo, p);
    MainWindow w(ctrl);
    w.show();

    return a.exec();
}
