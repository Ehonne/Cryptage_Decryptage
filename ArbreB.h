/*
 * ArbreB.h
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#ifndef ARBREB_H_
#define ARBREB_H_
#include "Sommet.h"

class ArbreB {
private:
    int nbSommet;
public:
    Sommet *racine;		//Racine de l'arbre
    ArbreB();
    virtual ~ArbreB();

    int getNbSommet();
    void Ajouter(int val);		// ajoute un sommet de valeur val
    void Inserer(Sommet * nouveau);
    void Supprimer(Sommet * del);		// supprime un sommet
    Sommet* Recherche(int val);		// Recherche un sommet dans l'arbre
    void Affiche(Sommet * courant, int prof);
<<<<<<< Updated upstream
    void ModifierEtiquette(int val1, int val2);
=======
    friend ArbreB operator+(ArbreB A, ArbreB B);

>>>>>>> Stashed changes
};

#endif /* ARBREB_H_ */
