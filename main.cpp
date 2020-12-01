#include "mainwindow.h"
#include <vector>
#include <QApplication>
#include "ArbreB.h"
#include "iostream"
#include <math.h>
#include "occurence.h"

using namespace std;

//  notre vecteur de sommet :
vector<Sommet *> T;

// fonction pour ajouter un sommet dans le vecteur
Sommet* ajout_sommet(int freq, char c)
{
    Sommet * s = new Sommet();
    s->caractere = c;
    s->valeur = freq;

    return s;
}

// recherche le sommet le plus petit dans le vecteur :
Sommet * recherche_min()
{
    int min(9999), index(0);
    for(int i(0); i<(int)(T.size()); ++i)
    {
            if (min > T[i]->valeur) {
                min = T[i]->valeur;
                index = i;
            }
    }
   // cout << endl << "frequence : " << T[index]->valeur << " et " << T[index]->caractere << " // ";
    Sommet * s = T[index];
    T.erase(T.begin()+index);
    return s;
}

// fusionne et ajoute un sommet dans le vecteur :
void min()
{
    // on prend les deux min :
    Sommet * s1 = recherche_min();
    Sommet * s2 = recherche_min();

    cout << endl;
    //fusion des deux sommets
    Sommet * nouv = new Sommet;
    nouv->valeur = s1->valeur+s2->valeur;
    if(s1->valeur >= s2->valeur)
    {
        nouv->fils_gauche = s1;
        nouv->fils_droite = s2;
    }
    else{
        nouv->fils_gauche = s2;
        nouv->fils_droite = s1;
    }

    // Puis on ajoute le nouveau sommet dans le vecteur de Sommets :
    T.push_back(nouv);
}

int calculTaille(int t)
{
    int i(-1), res(0);

    while (res < t)
    {
        i++;
        res = pow(2, i);
    }
    return i;
}


int main(int argc, char *argv[])
{
    cout << "Bienvenue sur le projet"<< endl;


    Occurence test("je suis ton pere");
    test.print_occurence();
    int nb_lettres = (int)(test.arr.size());

    // création d'un tableau d'arbre :
    for(int i(0); i<(int)(test.arr.size()); ++i)
    {
        T.push_back(ajout_sommet(test.frequence[i], test.arr[i]));
    }

    for(int i(0); i<(int)(T.size()); ++i)
    {
       cout << T[i]->valeur << " ";
    }

    // boucle tant que la taille du vecteur n'est pas égale à 1
    while((int)(T.size()) > 1)
    {
        min();
        cout << endl;
        for(int i(0); i<(int)(T.size()); ++i)
        {
           cout << T[i]->valeur << " ";
        }
    }



    cout << endl;

    ArbreB abr;
    abr.racine = T[0];
    abr.Affiche(abr.racine, 0);

    // initialisation du tableau de code binaire d'un caractère :
    string array;
    array.resize(calculTaille(nb_lettres));

    // initialisation du vecteur codage :
    abr.remplirVecteur_codage(nb_lettres);
    abr.parcoursHuffman(abr.racine, array, 0, test.arr);

    for(int i(0); i<(int)(abr.codage.size()); ++i)
    {
        cout << test.arr[i] << " : "<< abr.codage[i] << endl;
    }


    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();*/
    cout << "FIN" << endl;
    return 0;
}
