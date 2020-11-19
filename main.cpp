#include "mainwindow.h"
#include <vector>
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

    // On recherche l'étiquette dont la valeur est 8 :
    Sommet * n = B.Recherche(8);

    // modification d'etiquette :
    cout << "on modifie 10 par 1 : \n";
    B.ModifierEtiquette(10, 1);
    B.Affiche(B.racine, 0);

    // Addition de 2 arbre :
    ArbreB A;
    A.Ajouter(15);      A.Ajouter(4);    A.Ajouter(9);
    cout << "Arbre A:" << endl;
    A.Affiche(A.racine,0);


    ArbreB C = A;
    C += B;
    cout << "Arbre C (addition de A et B):" << endl;
    C.Affiche(C.racine,0);
    if (A == C) cout << "l'arbre A est identique à l'arbre binaire C \n";
    else cout << "A est different de C \n";

    // recopie :
    ArbreB recopie(C), Cbis;
    cout << "Arbre recopie identique a C: \n";
    recopie.Affiche(recopie.racine, 0);

    C.decomposition(Cbis, 9);
    cout << "decomposition de l'arbre C : \n";
    C.Affiche(C.racine, 0);
    cout << "nb sommet de C : " << C.getNbSommet() << endl;
    cout << "Cbis l'arbre produit : \n";
    Cbis.Affiche(Cbis.racine, 0);
    cout << "nb sommet Cbis : " << Cbis.getNbSommet() << endl;


    cout << "-------------------------------------------------- \n";



/****************************************************/


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    cout << "FIN" << endl;
    return 0;
}
