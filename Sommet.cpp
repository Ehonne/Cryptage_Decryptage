/*
 * Sommet.cpp
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#include "Sommet.h"
#include <iostream>

// on initialise l'attribut statique :
int Sommet::compteurS(0);

Sommet::Sommet() {
    caractere = 0;
    valeur = 0;
    profondeur = 0;
    fils_droite = NULL;
    fils_gauche = NULL;
    ++compteurS;
}

Sommet::~Sommet() {
    // TODO Auto-generated destructor stub
    --compteurS;
}


// fonction static qui retourne le nb d'objet de type Sommet instancié:
int Sommet::nbObjetSommet()
{
    return compteurS;
}
