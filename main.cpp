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


    string chaineCrypte = "100110110100010000011101000";               // le txt crypté entré par l'utilisateur
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




    ArbreB abr;         // on initialise un nouvel arbre :
    abr.Ajouter(0);     // on ajoute une racine d'étiquette (caractère) 0

    // On construit l'arbre :
    for (itr = huffman.begin(); itr != huffman.end(); ++itr)
    {
        abr.AjouterCar(itr->first, itr->second);    // on ajoute les sommets nécessaire pour pouvoir accéder au caractère itr->first
                                                            // en utilisant le code binaire, c'est à dire itr->second
    }

    abr.Affiche(abr.racine, 0);     // test si ca fonctionne en affichant l'arbre construit

    string chaineDecrypte = "";         // notre résultat texte
    chaineDecrypte = abr.decrypte(chaineCrypte);    // appel de la fonction pour decrypter

    cout << "texte decode : " << chaineDecrypte << endl;    // affichage du résultat


    cout << "FIN" << endl;
    return 0;
}
