#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <iostream>
#include <ArbreB.h>
#include "occurence.h"
#include <queue>
#include <Sommet.h>
#include <math.h>
#include <QPoint>
#include <QBrush>
#include "abrwindow.h"
#include <QMessageBox>
#include<bits/stdc++.h>

using namespace std;




vector<Sommet *> TT;

Sommet* ajout_sommet(int freq, char c)
{
    Sommet * s = new Sommet;
    s->fils_gauche = NULL;
    s->fils_droite = NULL;
    s->caractere = c;
    s->valeur = freq;

    return s;
}

// recherche le sommet le plus petit dans le vecteur :
Sommet * recherche_min()
{
    int min(9999), index(0);
    for(int i(0); i<(int)(TT.size()); ++i)
    {
            if (min > TT[i]->valeur) {
                min = TT[i]->valeur;
                index = i;
            }
    }
   // cout << endl << "frequence : " << T[index]->valeur << " et " << T[index]->caractere << " // ";
    Sommet * s = TT[index];
    TT.erase(TT.begin()+index);
    return s;
}

// fusionne et ajoute un sommet dans le vecteur :
void min()
{
    // on prend les deux min :
    Sommet * s1 = recherche_min();
    Sommet * s2 = recherche_min();

    //cout << endl;
    //fusion des deux sommets
    Sommet * nouv = new Sommet;
    nouv->valeur = s1->valeur+s2->valeur;
    if(s1->valeur >= s2->valeur)
    {
        nouv->fils_gauche = s1;
        nouv->fils_droite = s2;
    }
    else{
        nouv->fils_gauche = s2;
        nouv->fils_droite = s1;
    }

    // Puis on ajoute le nouveau sommet dans le vecteur de Sommets :
    TT.push_back(nouv);
}

int calculTaille(int t)
{
    int i(-1), res(0);

    while (res < t)
    {
        i++;
        res = pow(2, i);
    }
    return i;
}

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);  //Creation bouton et fentrre de saisie et de renvoie

    QObject::connect(ui->Cryptage, SIGNAL(clicked()), this, SLOT(doPainting())); //Renvoi le nombre d 'occurance de chaque lettre
    QObject::connect(ui->Affiche_nouv, SIGNAL(clicked()), this, SLOT(Affiche_nouv_texte()));    //Affiche le nouveau texte encodé
    QObject::connect(ui->Affiche_Arbre, SIGNAL(clicked()), this, SLOT(Affiche_ABR()));      //Affiche l'abre binaire associé au texte initiale dnas une nouvelle fenttre bloquante
}

void MainWindow::doPainting()
{
    QString text = ui->textEdit->toPlainText();
    string str = text.toStdString();
    std::transform(str.begin(),str.end(),str.begin(),::tolower); //Convertion to lower case
    Occurence test(str);
    int cpt = 0;
    for(int i = 0; i < (int)test.frequence.size(); i++)
    {
        cpt = cpt + test.frequence[i];
    }
    if(cpt != (int)str.size())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Caractere non reconnu !");
    }

    test.print_occurence();

}

void MainWindow::Affiche_nouv_texte()
{
    QString text = ui->textEdit->toPlainText();
    string str = text.toStdString();
    std::transform(str.begin(),str.end(),str.begin(),::tolower); //Convertion to lower case
    Occurence test(str);
    int cpt = 0;
    for(int i = 0; i < (int)test.frequence.size(); i++)
    {
        cpt = cpt + test.frequence[i];
    }
    if(cpt != (int)str.size())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Caractere non reconnu !");
        return;
    }

    int nb_lettres = (int)(test.arr.size());

       // création d'un tableau d'arbre :
    for(int i(0); i<(int)(test.arr.size()); ++i)
    {
        TT.push_back(ajout_sommet(test.frequence[i], test.arr[i]));
    }

       // boucle tant que la taille du vecteur n'est pas égale à 1
    while((int)(TT.size()) > 1)
    {
        min();
    }



    ArbreB abr;
    abr.racine = TT[0];
    //abr.Affiche(abr.racine, 0);

    // initialisation du tableau de code binaire d'un caractère :
    string array;
    array.resize(calculTaille(nb_lettres));

       // initialisation du vecteur codage :
    abr.remplirVecteur_codage(nb_lettres);
    abr.parcoursHuffman(abr.racine, array, 0, test.arr);

    //Affiche table de cryptage
    /*for(int i(0); i<(int)(abr.codage.size()); ++i)
    {
        cout << test.arr[i] << " : "<< abr.codage[i] << endl;
    }*/

    string text_code = "";  //creation du code binaire
    for(int i = 0; i < (int) text.toStdString().size(); i++)    //On parcours notre texte depart
    {
        for(int j = 0; j < (int) (abr.codage.size()); j++)      //On parcours notre table de codage
        {
            if(text.toStdString()[i] == test.arr[j])    //pour chaque carac on va rechercher le codage qu'il a
                text_code.operator+=(abr.codage[j]);    //On concat au code binaire final car on a pris en compte les espace dans notre table de codage
        }
    }

    QString qstr = QString::fromStdString(text_code);
    ui->textBrowser->setText(qstr);
    TT.clear();
}

void MainWindow::Affiche_ABR()
{
    string str = ui->textEdit->toPlainText().toStdString();
    std::transform(str.begin(),str.end(),str.begin(),::tolower); //Convertion to lower case
    Occurence test(str);
    int cpt = 0;
    for(int i = 0; i < (int)test.frequence.size(); i++)
    {
        cpt = cpt + test.frequence[i];
    }
    if(cpt != (int)str.size())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Caractere non reconnu !");
        return;
    }

    AbrWindow secWind(str);   //creation de la nouvelle fenettre
    secWind.setModal(true);        //Met la fenetre en priorité elevé
    secWind.exec();
    secWind.setAttribute(Qt::WA_DeleteOnClose); //Supprime memoir lorsque l'on clic sur la croix
}




