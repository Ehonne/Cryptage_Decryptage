#include "mainwindow.h"

#include <QApplication>
#include "ArbreB.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Bienvenue sur le projet"<< endl;

    ArbreB B;
    B.Ajouter(5);
    B.Ajouter(8);
    B.Ajouter(2);
    B.Ajouter(1);
    B.Ajouter(10);
    B.Ajouter(6);
    B.Affiche(B.racine,0);

    // On recherche le sommmet dont l'étiquette est de valeur 1 :
    Sommet * ptr = B.Recherche(1);
    if (ptr != NULL) cout << "Sommet trouvé : " << ptr->valeur << endl;

    // suppression du sommet recherché :
    B.Supprimer(ptr);
    B.Affiche(B.racine, 0);

    cout << endl;

    // On recherche l'étiquette dont la valeur est 8 :
    Sommet * n = B.Recherche(8);
    if (n != NULL) cout << "Sommet trouvé : " << n->valeur << endl;
    B.Supprimer(n);
    B.Affiche(B.racine, 0);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
