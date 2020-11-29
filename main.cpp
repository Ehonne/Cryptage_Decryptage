#include "mainwindow.h"
#include <vector>
#include <QApplication>
#include "ArbreB.h"
#include "iostream"
#include "occurence.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Bienvenue sur le projet"<< endl;

    Occurence test("bonjour");
    test.print_occurence();


    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();*/
    cout << "FIN" << endl;
    return 0;
}
