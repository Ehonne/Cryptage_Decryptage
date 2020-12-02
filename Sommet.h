/*
 * Sommet.h
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#ifndef SOMMET_H_
#define SOMMET_H_

class Sommet {

private:
    // compteur d'objet de type Sommet :
    static int compteurS;


public:
    char caractere;      // caractere
    int profondeur;     //Profondeur du sommet
    int valeur;		//Valeur du sommet
    double x;
    double y;
    Sommet *fils_gauche;		//Sommet gauche
    Sommet *fils_droite;		//Sommet droite
    Sommet();
    virtual ~Sommet();

    // fonction static pour l'attribut compteurS :
    static int nbObjetSommet();
};

#endif /* SOMMET_H_ */
