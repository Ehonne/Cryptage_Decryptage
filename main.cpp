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
    if (ptr != NULL) cout << "Sommet trouvé : " << ptr->valeur << endl;

    // suppression du sommet recherché :
    B.Supprimer(ptr);
    cout << "Arbre B sans 1:" << endl;
    B.Affiche(B.racine, 0);

    cout << endl;

    // On recherche l'étiquette dont la valeur est 8 :
    Sommet * n = B.Recherche(8);
    if (n != NULL) cout << "Sommet trouvé : " << n->valeur << endl;
    B.Supprimer(n);
    cout << "Arbre B sans 8:" << endl;
    B.Affiche(B.racine, 0);

    cout << endl;

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
    cout << "Arbre A : \n";
    A.Affiche(A.racine,0);

    cout << "\n\n";
    if (A == C) cout << "l'arbre A est identique à l'arbre binaire C \n";
    else cout << "A est different de C \n";


    cout << "nb de sommet de l'arbre B : " << B.getNbSommet() << endl;

    cout << endl;
    ArbreB nouv;
    nouv.Ajouter(1);
    nouv.Ajouter(2);
    nouv.Ajouter(3);
    nouv.Ajouter(-2);
    B = nouv;
    cout << "l'abre B : \n";
    B.Affiche(B.racine, 0);
    cout << "l'abre nouv : \n";
    nouv.Affiche(nouv.racine, 0);


    ArbreB test;
    nouv.decomposition(test, 2);
    cout << "Arbre nouv après decomposition : \n";
    nouv.Affiche(nouv.racine, 0);
    cout << "Arbre test après décomposition de nouv : \n";
    test.Affiche(test.racine, 0);

    // recopie :
    ArbreB recopie(C), Cbis;
    cout << "Arbre recopie : \n";
    recopie.Affiche(recopie.racine, 0);

    C.decomposition(Cbis, 9);
    cout << "decomposition de l'arbre C : \n";
    C.Affiche(C.racine, 0);
    cout << "nb sommet de C : " << C.getNbSommet() << endl;
    cout << "Cbis l'arbre produit : \n";
    Cbis.Affiche(Cbis.racine, 0);
    cout << "nb sommet Cbis : " << Cbis.getNbSommet() << endl;

    Cbis += B;
    cout << "l'arbre Cbis + l'arbre B : \n";
    Cbis.Affiche(Cbis.racine, 0);



    nouv.additionEtiquettes(test);
    cout << "Addition des etiquettes des arbres nouv et test : \n";
    nouv.Affiche(nouv.racine, 0);
    cout << "arbre test : \n";
    test.Affiche(test.racine, 0);

    cout << "-------------------------------------------------- \n";



/****************************************************/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    cout << "FIN" << endl;
    return 0;
}
