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

   /* QApplication a(argc, argv);
    *  MainWindow w;
    *  w.show();
    *   a.exec();
    */

    string chaineCrypte = "100110110100010000011000";               // le txt crypté entré par l'utilisateur
    string TOTO = "a : 000\nb : 001\nc : 010\nd : 101\ne : 100\nf : 110\ng : 011\nh : 111";     // la table de cryptage de l'utilisateur
         map<char,string> huffman;
         std::istringstream f(TOTO);
         std::string line;
         while (std::getline(f, line)) {
             string code_binaire;
             for(int i = 4; i < (int)line.size(); i++)
             {
                 if((line[i] != '0') && (line[i] != '1'))
                 {
                     cout << line[i] << endl;
                     exit(1);
                 }
                 code_binaire.push_back(line[i]);
             }
            huffman.insert(pair<char, string>(line[0],code_binaire));
         }
          map<char, string>::iterator itr;
         for (itr = huffman.begin(); itr != huffman.end(); ++itr) {
                 cout << itr->first << "  " << itr->second << '\n';
             }
             cout << endl;




    ArbreB abrDecrypte;         // on initialise un nouvel arbre :
    abrDecrypte.Ajouter(0);     // on ajoute une racine d'étiquette (caractère) 0

    // On construit l'arbre :
    for (itr = huffman.begin(); itr != huffman.end(); ++itr)
    {
        abrDecrypte.AjouterCar(itr->first, itr->second);    // on ajoute les sommets nécessaire pour pouvoir accéder au caractère itr->first
                                                            // en utilisant le code binaire, c'est à dire itr->second
    }

    abrDecrypte.Affiche(abrDecrypte.racine, 0);     // test si ca fonctionne en affichant l'arbre construit

    string chaineDecrypte = "";         // notre résultat texte
    vector<char> v(chaineCrypte.begin(), chaineCrypte.end());       // string ---> vecto
    Sommet * courant = NULL;
    courant = abrDecrypte.racine;
    for(int i(0); i<=(int)v.size(); ++i)
    {
        cout << "i : " << i << endl;
        if(courant->fils_droite == NULL and courant->fils_gauche == NULL and courant->caractere != 0) //si feuille
        {
            chaineDecrypte.push_back(courant->caractere);
            courant = abrDecrypte.racine;

        }
        if(v[i] == '0') courant = courant->fils_gauche;
        else courant = courant->fils_droite;
    }

    cout << "texte decode : " << chaineDecrypte << endl;

    //Note : caster le string chaineCryte en vector
    //      Puis boucler sur la size() de ce vector créé et pour chaque push_back de celui-ci
    //          on avance dans l'arbre en vérifiant si on est dans une feuille ou non
       //           si oui, on push dans un vecteur decrypte le caractère correspondant

    cout << "FIN" << endl;
    return 0;
}
