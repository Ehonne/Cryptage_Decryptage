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

// CONSTRUCTEUR :
ArbreB::ArbreB() {
    racine = NULL;
    nbSommet = 0;
}

// CONSTRUCTEUR PAR RECOPIE :
ArbreB::ArbreB(ArbreB & cible)
{
    racine = NULL;
    if (cible.racine)
    {
        cible.parcoursPrefixe(cible.racine);
        for(int i(0); i<cible.getNbSommet(); ++i)
        {
            Ajouter(cible.pile[i]);
        }
        cible.pile.clear();
    }
    else
    {
        nbSommet = 0;
        racine = NULL;
    }

}


// DESTRUCTEUR :
ArbreB::~ArbreB() {
    cout << "Appel des destructeurs Arbres" << endl;
    delete(racine);
}


// getter and setter :
int ArbreB::getNbSommet() const
{
    return nbSommet;
}

void ArbreB::setNbSommet(int val)
{
    nbSommet = val;
}

// AFFICHE ARBRE :
void ArbreB::Affiche(Sommet *courant, int prof)
{
     int i;
     for (i=0; i < prof; i++)
     {
         cout << "	";
     }
     cout << courant->valeur << "_" <<courant->caractere << endl;

     if (courant->fils_droite) Affiche(courant->fils_droite, prof + 1);
     if (courant->fils_gauche) Affiche(courant->fils_gauche, prof + 1);

}

/************************************************************/
// Pour la partie décryptage :
void ArbreB::AjouterCar(char c, string code)
{

    // on initialise deux sommets pour parcourir l'arbre :
    Sommet * courant = racine;
    Sommet * prec = NULL;

    int cpt(0);     // le compteur pour la profondeur dans l'arbre

    // on boucle sur le string code
    while(cpt < (int)code.size())
    {
        // on cherche un sommet NULL
        while(courant)
        {
            prec = courant;            // on conserve le pere du sommet courant
            if(code[cpt] == '0')        // si le ième chiffre du code est 0, on passe à gauche
            {
                courant = courant->fils_gauche;
                cpt++;     // on incrémente la profondeur
            }
            else if(code[cpt] == '1')       // si le ième chiffre du code est 1, on passe à droite
            {
                courant = courant->fils_droite;
                cpt++;    // on incrémente la profondeur
            }
        }


        // courant est null on ajoute donc un nouveau sommet

        if(code[cpt-1] == '0')      // on est passé à gauche (0), on ajoute un sommet au fils gauche de prec
        {
            Sommet * nouveau = new Sommet;
            nouveau->fils_droite = NULL;
            nouveau->fils_gauche = NULL;
            if(cpt == (int)code.size()) nouveau->caractere = c;     // si on atteint la profondeur max, on place notre caractère c
            else nouveau->caractere = 0;                            // sinon 0
            prec->fils_gauche = nouveau;
            courant = prec->fils_gauche;
        }

        if(code[cpt-1] == '1')      // on est passé à droite (1), on ajoute un sommet au fils droite de prec
        {
            Sommet * nouveau2 = new Sommet;
            nouveau2->fils_droite = NULL;
            nouveau2->fils_gauche = NULL;
            if(cpt == (int)code.size()) nouveau2->caractere = c;    // si on atteint la profondeur max, on place notre caractère c
            else nouveau2->caractere = 0;                           // sinon 0
            prec->fils_droite = nouveau2;
            courant = prec->fils_droite;
        }

    }

    return;
}


//
string ArbreB::decrypte(string message_code)
{
    string resultat = "";
    vector<char> v(message_code.begin(), message_code.end());   // string --> vector
    Sommet * courant = NULL;            // pointeur de sommet pour parcourir l'arbre
    courant = racine;
    for(int i(0); i<=(int)v.size(); ++i)
    {
        if(courant->fils_droite == NULL and courant->fils_gauche == NULL and courant->caractere != 0)  //si feuille
        {
            resultat.push_back(courant->caractere);
            courant = racine;

        }
        if(v[i] == '0')
        {
            if(courant->fils_gauche == NULL)
            {
                resultat.clear();
                return resultat;
            }
            courant = courant->fils_gauche;
        }
        else
        {
            if(courant->fils_droite == NULL)
            {
                resultat.clear();
                return resultat;
            }
            courant = courant->fils_droite;
        }
    }

    return resultat;    // on retourne le texte décrypté
}



/***********************************************************************************/


//
void ArbreB::Ajouter(int val)
{
    // on incrémente le nombre de sommet de l'arbre :
    nbSommet++;

    // création d'un nouveau sommet, allocation de la mémoire :
    Sommet * nouveau_sommet = new Sommet;
    nouveau_sommet->fils_gauche = NULL;
    nouveau_sommet->fils_droite = NULL;
    nouveau_sommet->valeur  = val;

    //On insere le nouveau sommet dans l'arbre :
    Inserer(nouveau_sommet);
}

// AJOUT D'UN SOMMET :
void ArbreB::Inserer(Sommet * nouveau)
{
    int cpt = 1;
    if (!nouveau) return;		//Si le sommet est nul, on sort


    if (racine == NULL)		//Si l'arbre est vide, on lui accroche le sommet et on sort
    {
        nouveau->profondeur = cpt;
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
        cpt++;
        precedent = courant;
       if (nouveau->valeur < courant->valeur)
           courant = courant->fils_gauche;
       else courant = courant->fils_droite;
    }

    nouveau->profondeur = cpt;
    //Maintenant on place le nouveau noeud dans la bonne branche
    if (nouveau->valeur < precedent->valeur)
        precedent->fils_gauche = nouveau;
    else precedent->fils_droite = nouveau;

    return;
}

// SUPPRIME UN SOMMET :
void ArbreB::Supprimer(Sommet * del)
{
    Sommet * droite = del->fils_droite;
    Sommet * gauche = del->fils_gauche;

    Sommet * courant = racine;

    // Cas où l'on veut supprimer la racine :
    if(del == courant)
    {
        --nbSommet;
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

    // on décrémente le nb de Sommet de l'arbre :
    nbSommet--;
}

// RECHERCHE UN SOMMET :
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

// CHANGE L'ETIQUETTE D'UN SOMMET :
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

Sommet* ArbreB::addition(Sommet * A, Sommet * B)
{
    if(!A) return NULL;
    if(!B) return A;
    A->valeur += B->valeur;
    A->fils_gauche = addition(A->fils_gauche, B->fils_gauche);
    A->fils_droite = addition(A->fils_droite, B->fils_droite);
    return A;
}

// ADDITION ETIQUETTE :
void ArbreB::additionEtiquettes(ArbreB &abr)
{
    racine = addition(racine, abr.racine);
}

// PARCOURS PREFIXE D'UN ARBRE :
void ArbreB::parcoursPrefixe(Sommet *sommet)
{
    if (sommet != NULL)
    {
       pile.push_back(sommet->valeur);

       parcoursPrefixe(sommet->fils_droite);
       parcoursPrefixe(sommet->fils_gauche);
    }
}

// FUSION DE DEUX ARBRES :
ArbreB& ArbreB::fusion(ArbreB & abr)
{
    if (abr.racine != NULL)
    {
       abr.parcoursPrefixe(abr.racine);
       for(int i(0); i<abr.getNbSommet(); ++i)
       {
          Ajouter(abr.pile[i]);
       }
       abr.pile.clear();
       return *this;
    }
    else
    {
        cout << "erreur : arbre vide \n";
        return *this;
    }


}

// parcours pour récupérer le codage binaire des caractères :
void ArbreB::parcoursHuffman(Sommet *sommet, string array, int index, vector<char> v)
{


    if (sommet->fils_gauche)
    {
        array[index] = '0';
        parcoursHuffman(sommet->fils_gauche, array, index+1, v);
    }

    if(sommet->fils_droite)
    {
        array[index] = '1';
        parcoursHuffman(sommet->fils_droite, array, index+1, v);
    }

    // si le sommet actuel est une feuille de l'arbre :
    if ((!sommet->fils_droite) and (!sommet->fils_gauche))
    {
        // on récupère l'indice dans vecteur occurence :
        for(int i(0); i<(int)(v.size()); ++i)
        {
            if(v[i] == sommet->caractere)
            {
                codage[i] = array;
                break;
            }
        }
    }
}

// pour Initialiser le vecteur codage :
void ArbreB::remplirVecteur_codage(int taille)
{
    for(int i(0); i<taille; ++i)
    {
        codage.push_back("");
    }
}


// operateur += :
ArbreB& ArbreB::operator+=(ArbreB &abr)
{
    fusion(abr);
    return *this;
}

// operateur d'affectation :
ArbreB& ArbreB::operator=(ArbreB &abr)
{

    if(racine != NULL)
    {
        for(int i(0); i<nbSommet; ++i)
        {
            Supprimer(racine);
        }
        racine = NULL;
    }

    racine = NULL;

    abr.parcoursPrefixe(abr.racine);

    for(int i(0); i<abr.getNbSommet(); ++i)
    {
        Ajouter(abr.pile[i]);
    }

    if(abr.racine != NULL) abr.pile.clear();
    setNbSommet(abr.getNbSommet());

    return *this;
}

//
bool operator==(ArbreB& abr1, ArbreB& abr2)
{
    if (abr1.getNbSommet() != abr2.getNbSommet()) return false;
    else {
        abr1.parcoursPrefixe(abr1.racine);
        abr2.parcoursPrefixe(abr2.racine);

        for(int i(0); i<abr1.getNbSommet(); ++i)
        {
            if (abr1.pile[i] != abr2.pile[i]) {
                abr1.pile.clear();
                abr2.pile.clear();
                return false;
            }
        }
        abr1.pile.clear();
        abr2.pile.clear();
        return true;
    }
}

//
bool operator != (ArbreB& abr1,  ArbreB& abr2)
{
    return !(abr1 == abr2);
}


// definition de la fonction de décomposition d'un arbre binaire :
ArbreB& ArbreB::decomposition(ArbreB& abr, int valeur)
{
    // On cherche le sommet à partir duquel on veut decomposer abr :
    Sommet * ptr = Recherche(valeur);

    if (ptr == racine)
    {
      parcoursPrefixe(ptr->fils_gauche);
    }
    else {
        pile.clear();
        // on stocke les valeurs en dessous du sommet ptr :
        parcoursPrefixe(ptr);
    }

    // On ajoute ces valeurs à notre nouvel arbre "abr" :
    for(int i(0); i<(int)(pile.size()); ++i)
    {
        abr.Ajouter(pile[i]);
    }

    // Puis, on supprime les sommets devenus inutiles à l'arbre "abr" :
    for(int i(0); i<(int)(pile.size()); ++i)
    {
        Sommet * ancien = Recherche(pile[i]);
        if (ancien) Supprimer(ancien);
    }
    pile.clear();

    // on retourne notre nouvel arbre :
    return *this;
}
