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
    int nbSommet;
public:
    Sommet *racine;		//Racine de l'arbre
    vector<int> pile;
    ArbreB();
    virtual ~ArbreB();

    int getNbSommet();
    void setNbSommet(int val);
    void Ajouter(int val);		// ajoute un sommet de valeur val
    void Inserer(Sommet * nouveau);
    void Supprimer(Sommet * del);		// supprime un sommet
    Sommet* Recherche(int val);		// Recherche un sommet dans l'arbre
    void Affiche(Sommet * courant, int prof);
    void ModifierEtiquette(int val1, int val2);

    // parcours préfixe :
    void parcoursPrefixe(Sommet * sommet);

    // surcharge d'operateurs :
    ArbreB& operator=(ArbreB& abr);
    friend ArbreB operator+(ArbreB& A, ArbreB& B);
    friend bool operator==(ArbreB& abr1,  ArbreB& abr2);
    friend bool operator!=(ArbreB& abr1,  ArbreB& abr2);

};

#endif /* ARBREB_H_ */
