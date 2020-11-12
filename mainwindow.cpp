#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <iostream>
#include <ArbreB.h>
#include <queue>
#include <Sommet.h>
#include <QPoint>

using namespace std;




int getLevelUtil(Sommet *node,  int data, int level)    // Obtenir le niv d'un sommet
{
    if (node == NULL)
        return 0;

    if (node->valeur == data)
        return level;

    int downlevel = getLevelUtil(node->fils_gauche, data, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->fils_droite, data, level + 1);
    return downlevel;
}
int getLevel(Sommet *node, int data)
{
    if(data == 33333)
           return 3;
    if(data == 22222)
           return 2;
    if(data == 44444)
           return 4;
    return getLevelUtil(node, data, 1);
}

void MainWindow::affiche_arbre(ArbreB B)
{


    int etage_2 = 100;
    int etage_3 = etage_2 -50;
    QPainter painter(this);
    int cpt2 = 1; // compteur du nombre de sommet par etage;
    int cpt3 = 1;
    int cpt4 = 1;
    queue<Sommet*> fifo;      // Création d'une file
    fifo.push(B.racine);          // Mise de la racine dans la file
    while(!fifo.empty())
    {
        Sommet *n = fifo.front();       // Nouveau sommet à traiter en tête de file
        fifo.pop();

        //traitement du sommet :
        cout << "Level of "<< n->valeur << " is " << getLevel(B.racine, n->valeur) << endl;
        switch(getLevel(B.racine, n->valeur))
        {
            case 1: {       //Profondeur 1
                const QRect rectangle = QRect(200, 50, 50, 50);
                painter.setBrush(Qt::red);
                painter.drawEllipse(200, 50, 50, 50);
                painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                break;
            }

             case 2: {      //Profondeur 2

                if(cpt2 == 1)
                {
                    if(n->valeur == 22222)
                    {
                        etage_2 += 200;
                    }
                    else
                    {
                    painter.drawLine(225,100,etage_2+25,175);
                    const QRect rectangle = QRect(etage_2, 150, 50, 50);
                    painter.setBrush(Qt::red);
                    painter.drawEllipse(etage_2, 150, 50, 50);
                    painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));

                    etage_2 += 200;
                    }
                }
                if(cpt2 == 2)
                {
                    if(n->valeur == 22222)
                    {
                        etage_2 += 200;
                    }
                    else
                    {
                    painter.drawLine(225,100,etage_2+25,175);
                    const QRect rectangle = QRect(etage_2, 150, 50, 50);
                    painter.setBrush(Qt::red);
                    painter.drawEllipse(etage_2, 150, 50, 50);
                    painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                    etage_2 += 200;
                    }
                }
                break;
            }


             case 3: {      //Profondeur 3

                if (cpt3 == 1)
                {
                    if(n->valeur == 33333)
                    {
                        etage_3 += 100;
                    }
                    else
                    {
                        painter.drawLine(etage_2+25-400,200,etage_3+25,275);
                        const QRect rectangle = QRect(etage_3, 250, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3, 250, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3 += 100;
                    }
                }
                if (cpt3 == 2)
                {
                    if(n->valeur == 33333)
                    {
                        etage_3 += 100;
                    }
                    else
                    {
                        painter.drawLine(etage_2+25-400,200,etage_3+25,275);
                        const QRect rectangle = QRect(etage_3, 250, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3, 250, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3 += 100;
                    }
                }
                if (cpt3 == 3)
                {
                    if(n->valeur == 33333)
                    {
                        etage_3 += 100;
                    }
                    else
                    {
                        painter.drawLine(etage_2+25-200,200,etage_3+25,275);
                        const QRect rectangle = QRect(etage_3, 250, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3, 250, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3 += 100;
                    }
                }
                if (cpt3 == 4)
                {
                    if(n->valeur == 33333)
                    {
                        etage_3 += 100;
                    }
                    else
                    {
                        painter.drawLine(etage_2+25-200,200,etage_3+25,275);
                        const QRect rectangle = QRect(etage_3, 250, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3, 250, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3 += 100;
                    }

                }
                cpt3++;
                break;
             }
        }
        if (n->fils_gauche != NULL) fifo.push(n->fils_gauche);       // Ajout du fils gauche s'il existe

        //Cas ou on a que le coter droite (suite a une suppretion du coter gauche par exemple)
        //On rajoute 2 fantome a l'etage en amont
        if(!fifo.empty())
        {
            Sommet* prob_sup = fifo.front();
            if (((prob_sup->fils_droite != NULL) || (prob_sup->fils_gauche != NULL)) && ((n->fils_droite == NULL) && (n->fils_gauche == NULL)))
            {
                Sommet * vide = new Sommet;    Sommet* vide2 = new Sommet; //Sommet fantome
                vide->fils_droite = NULL;       vide2->fils_droite = NULL;
                vide->fils_gauche = NULL;       vide2->fils_gauche = NULL;
                if(getLevel(B.racine, n->valeur) == 2)
                {
                    vide->valeur = 33333;       //Valeur aberante pour profondeur 2;
                    vide2->valeur = 33333;
                }
                if(getLevel(B.racine, n->valeur) == 3)
                {
                    vide->valeur = 33333;       //Valeur aberante pour profondeur 3;
                    vide2->valeur = 33333;
                }
                if(getLevel(B.racine, n->valeur) == 4)
                {
                    vide->valeur = 44444;       //Valeur aberante pour profondeur 4;
                    vide2->valeur = 44444;
                }
                fifo.push(vide);
                fifo.push(vide2);
            }
        }
        if(((n->fils_droite == NULL) && (n->fils_gauche != NULL)) || ((n->fils_droite != NULL) && (n->fils_gauche == NULL)))    //SI on a 1 fils Creation d'un sommet fantom pour conserver l'espacement
        {
            Sommet * vide = new Sommet;     //Sommet fantome
            vide->fils_droite = NULL;
            vide->fils_gauche = NULL;

            if((n->fils_droite == NULL) && (n->fils_gauche != NULL))
            {
                if(getLevel(B.racine, n->fils_gauche->valeur) == 2)
                    vide->valeur = 22222;       //Valeur aberante pour profondeur 2;
                if(getLevel(B.racine, n->fils_gauche->valeur) == 3)
                    vide->valeur = 33333;       //Valeur aberante pour profondeur 3;
                if(getLevel(B.racine, n->fils_gauche->valeur) == 4)
                    vide->valeur = 44444;       //Valeur aberante pour profondeur 4;
            }
            if((n->fils_droite != NULL) && (n->fils_gauche == NULL))
            {
                if(getLevel(B.racine, n->fils_droite->valeur) == 2)
                    vide->valeur = 22222;       //Valeur aberante pour profondeur 2;
                if(getLevel(B.racine, n->fils_droite->valeur) == 3)
                    vide->valeur = 33333;       //Valeur aberante pour profondeur 3;
                if(getLevel(B.racine, n->fils_droite->valeur) == 4)
                    vide->valeur = 44444;       //Valeur aberante pour profondeur 4;
            }

            fifo.push(vide);
        }
        if (n->fils_droite != NULL) fifo.push(n->fils_droite);       // Ajout du fils droit s'il existe

    }
}


void MainWindow::paintEvent(QPaintEvent *event)
{

    setFixedSize(500, 500);


    ArbreB B;
    B.Ajouter(5);
    B.Ajouter(8);
    B.Ajouter(2);
    B.Ajouter(1);
    B.Ajouter(10);
    B.Ajouter(6);
    B.Affiche(B.racine,0);

    //affiche_arbre(B);

    Sommet * ptr = B.Recherche(1);

    B.Supprimer(ptr);
    B.Affiche(B.racine,0);
    affiche_arbre(B);


}



