/*
 * ArbreB.h
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#ifndef ARBREB_H_
#define ARBREB_H_
#include "Sommet.h"
#include <vector>
using namespace std;

class ArbreB {
private:
    int nbSommet;       // nombre de sommet dans un arbre
public:
    Sommet *racine;		//Racine de l'arbre
    vector<int> pile;

    ArbreB();               // Constructeur
    ArbreB(ArbreB & cible);  // Constructeur par recopie

    void DestroyRecursive(Sommet *B);
    virtual ~ArbreB();                  // Destructeur

    int getNbSommet() const;            // getter
    void setNbSommet(int val);          // setter

    void Ajouter(int val);         // ajoute un sommet de valeur val
    void Inserer(Sommet * nouveau);
    void Supprimer(Sommet * del);		// supprime un sommet
    Sommet* Recherche(int val);		// Recherche un sommet dans l'arbre
    void Affiche(Sommet * courant, int prof);   //Affiche dans le terminal
    void ModifierEtiquette(int val1, int val2);

    void additionEtiquettes(ArbreB & abr);       // addition des étiquettes de deux arbres
    Sommet * addition(Sommet * A, Sommet * B);

    void parcoursPrefixe(Sommet * sommet);      // parcours préfixe

    ArbreB& fusion(ArbreB & abr);          // fusion de deux arbres

    // surcharge d'operateurs :
    ArbreB& operator+=(ArbreB & abr);
    ArbreB& operator=(ArbreB& abr);
    friend bool operator==(ArbreB& abr1,  ArbreB& abr2);
    friend bool operator!=(ArbreB& abr1,  ArbreB& abr2);

    // fonction membre de décomposition :
    ArbreB& decomposition(ArbreB& abr, int valeur);
};

#endif /* ARBREB_H_ */
