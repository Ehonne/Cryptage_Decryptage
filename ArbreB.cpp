/*
 * ArbreB.cpp
 *
 *  Created on: 9 nov. 2020
 *      Author: PL Gwen
 */

#include "ArbreB.h"
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

ArbreB::ArbreB() {
    racine = NULL;
}

ArbreB::~ArbreB() {
    // TODO Auto-generated destructor stub
}




void ArbreB::Affiche(Sommet *courant, int prof)
{
     int i;
     for (i=0; i < prof; i++)
     {
         cout << "	";
     }

     cout << courant->valeur << endl;

     if (courant->fils_droite) Affiche(courant->fils_droite, prof + 1);
     if (courant->fils_gauche) Affiche(courant->fils_gauche, prof + 1);

}

void ArbreB::Ajouter(int val)
{
    // création d'un nouveau sommet, allocation de la mémoire :
    Sommet * nouveau_sommet = new Sommet;
    nouveau_sommet->fils_gauche = NULL;
    nouveau_sommet->fils_droite = NULL;
    nouveau_sommet->valeur = val;

    //On insere le nouveau sommet dans l'arbre :
    Inserer(nouveau_sommet);
}

void ArbreB::Inserer(Sommet * nouveau)
{

    if (!nouveau) return;		//Si le sommet est nul, on sort


    if (racine == NULL)		//Si l'arbre est vide, on lui accroche le sommet et on sort
    {
        racine = nouveau;
        return;
    }

    //Création de deux pointeurs pour se deplacer dans l'arbre
    Sommet* courant = racine;
    Sommet* precedent = NULL;

    //On se déplace à travers l'arbre jusqu'a ce que courant atteint la valeur NULL
    //precedent memorise l'adresse du dernier Sommet visité
    while (courant)
    {
        precedent = courant;
        if (nouveau->valeur < courant->valeur)
            courant = courant->fils_gauche;
        else
            courant = courant->fils_droite;
    }

    //Maintenant on place le nouveau noeud dans la bonne branche
    if(nouveau->valeur < precedent->valeur)
        precedent->fils_gauche = nouveau;
    else
        precedent->fils_droite = nouveau;

    return;
}


void ArbreB::Supprimer(Sommet * del)
{
    Sommet * droite = del->fils_droite;
    Sommet * gauche = del->fils_gauche;

    Sommet * courant = racine;

    // Cas où l'on veut supprimer la racine :
    if(del == courant)
    {
        racine = droite;
        if (gauche != NULL)
        {
            Inserer(gauche);
        }
        delete del;
        return;
    }

    // on cherche le noeud à supprimer à l'aide del'étiquette :
    while(courant)
    {
        if(courant->fils_droite == del or courant->fils_gauche == del)
        {
            break;
        }
        else if (del->valeur >= courant->valeur) courant = courant->fils_droite;
        else courant = courant->fils_gauche;
    }

    //courant pointe sur le père du noeud à supprimer :
    if (courant->fils_droite == del) courant->fils_droite = droite;
    else courant->fils_gauche = droite;

    if(gauche != NULL) Inserer(gauche);

    delete del;
}

Sommet* ArbreB::Recherche(int val)
{
    if (racine == NULL)		//Si l'arbre est vide, on sort FAUX
    {
            return 0;
    }
    //Création d'un pointeur pour se deplacer dans l'arbre
    Sommet* courant = racine;

    //On se déplace à travers l'arbre jusqu'a ce que courant atteint la valeur NULL
    //si elem egal a la valeur du sommet courant alors on sort VRAI
    while (courant)
    {
        if (val == courant->valeur)
            return courant;
        if (val < courant->valeur)
            courant = courant->fils_gauche;
        else
            courant = courant->fils_droite;
    }

    return NULL;
}

<<<<<<< Updated upstream
void ArbreB::ModifierEtiquette(int val1, int val2)
{
    Sommet * adn = Recherche(val1);
    Sommet * gauche = adn->fils_gauche;
    Sommet * droite = adn->fils_droite;

    // Si on modifie l'étiquette de la racine :
    if (adn == racine)
    {
        adn->valeur = val2;
        if (gauche == NULL and droite == NULL)
        {
            Supprimer(adn);
            Ajouter(val2);
        }
        else if(val2 < adn->fils_gauche->valeur)
        {
            Supprimer(adn->fils_gauche);
            if (gauche != NULL) Inserer(gauche);
        }
        if(val2 > adn->fils_droite->valeur)
        {
            Supprimer(adn->fils_droite);
            if (droite != NULL) Inserer(droite);
        }
    }
    else
    {
        // On supprime le Sommet avec l'étiquette val1
        // et on ajoute un nouveau sommet d'étiquette val2
        Supprimer(adn);
        Ajouter(val2);
    }
}
=======

Sommet* addition(Sommet * A, Sommet *B)
{
    if (!A)
        return B;
    if (!B)
        return A;
    A->valeur += B->valeur;
    A->fils_gauche = addition(A->fils_gauche, B->fils_gauche);
    A->fils_droite = addition(A->fils_droite, B->fils_droite);
    return A;
}
ArbreB operator+(ArbreB A, ArbreB B)
{
    //Création du nouvelle arbre
    ArbreB NOUV = A;
    ArbreB Tempon;

    Tempon.racine = addition(NOUV.racine, B.racine);

    return Tempon;
}

>>>>>>> Stashed changes
