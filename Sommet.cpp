/*
 * Sommet.cpp
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#include "Sommet.h"
#include <iostream>


Sommet::Sommet() {
    valeur = 0;
    profondeur = 0;
    fils_droite = NULL;
    fils_gauche = NULL;

}

Sommet::~Sommet() {
    // TODO Auto-generated destructor stub
}
