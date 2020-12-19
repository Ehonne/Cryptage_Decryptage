#include "mainwindow.h"
#include <vector>
#include <QApplication>
#include "ArbreB.h"
#include "iostream"
#include <math.h>
#include <map>
#include <sstream>
#include "occurence.h"

using namespace std;


int main(int argc, char *argv[])
{
    cout << "Bienvenue sur le projet de crytage Hoffman"<< endl;

   QApplication a(argc, argv);
   MainWindow w;
   w.show();
   a.exec();

    cout << "FIN" << endl;
    return 0;
}
