#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <iostream>
#include <ArbreB.h>
#include <queue>
#include <Sommet.h>
#include <QPoint>

using namespace std;

//On fait un parcour en largeur de l'arbre de facons a le dessiner etage par etage. Pour se faire on stoke la racine de l'arbre dans une pile.
// puis des que l'on va depiler on va dessiner le sommet avec son lien a son pere, puis on va ajouter ses fils dans la pile
// Enfin pour des raisons d'affichage on rajoute des sommet fantome (sans valeur ni fils).
void MainWindow::affiche_arbre(ArbreB B)
{
    int etage_2 = 125;
    int etage_3 = etage_2 -75;
    int etage_3_bis = 325;
    int etage_4 = etage_3 - 37;
    int etage_4_bis = 200-37;
    int etage_4_bis_bis = etage_3_bis -37;
    int etage_4_bis_bis_bis = 475-37;

    QPainter painter(this);
    int cpt2 = 1;       // compteur du nombre de sommet par etage;
    int cpt3 = 1;
    int cpt4 = 1;
    queue<Sommet*> fifo;        // Création d'une file
    fifo.push(B.racine);        // Mise de la racine dans la file
    while(!fifo.empty())
    {
        Sommet *n = fifo.front();       // Nouveau sommet à traiter en tête de file
        fifo.pop();                     //On supprime de la file le sommet que l'on va traiter

        //traitement du sommet :
        switch(n->profondeur)   //Derterminer a quel etage de l'arbre on se trouve (profondeur)
        {
            case 1: {       //Profondeur 1
                const QRect rectangle = QRect(265, 25, 50, 50);
                painter.setBrush(Qt::red);  //Coloration en rouge
                painter.drawEllipse(265, 25, 50, 50);
                painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));     //Dessine le numero du sommet dans le cerlce
                break;
            }

             case 2: {      //Profondeur 2

                if(cpt2 == 1)   //Fils droite
                {
                    if(n->valeur == 22222) //Si on a un sommet fantome
                    {
                        etage_2 += 275;
                    }
                    else
                    {
                        painter.drawLine(290,75,etage_2+25,150);
                        const QRect rectangle = QRect(etage_2, 125, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_2, 125, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));

                        etage_2 += 275;
                    }
                }
                if(cpt2 == 2) //Fils gauche
                {
                    if(n->valeur == 22222)
                    {
                        etage_2 += 275;
                    }
                    else
                    {
                    painter.drawLine(290,75,etage_2+25,150);
                    const QRect rectangle = QRect(etage_2, 125, 50, 50);
                    painter.setBrush(Qt::red);
                    painter.drawEllipse(etage_2, 125, 50, 50);
                    painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                    //etage_2 += 275;
                    }
                }
                break;
            }


             case 3: {      //Profondeur 3

                if ((cpt3 == 1) || (cpt3 == 2))
                {
                    if(n->valeur == 33333)
                    {
                        etage_3 += 150;
                    }
                    else
                    {
                        painter.drawLine(etage_2-525,175,etage_3+25,250);
                        const QRect rectangle = QRect(etage_3, 225, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3, 225, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3 += 150;
                    }
                }
                if ((cpt3 == 3) || (cpt3 == 4))
                {
                    if(n->valeur == 33333)
                    {
                        etage_3_bis += 150;
                    }
                    else
                    {
                        painter.drawLine(400+25,175,etage_3_bis+25,250);
                        const QRect rectangle = QRect(etage_3_bis, 225, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_3_bis, 225, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_3_bis += 150;
                    }
                }
                cpt3++;
                break;
             }
             case 4: {      //Profondeur 4

                if ((cpt4 == 1) || (cpt4 == 2))
                {
                    if(n->valeur == 44444)
                    {
                        etage_4 += 75;
                    }
                    else
                    {
                        painter.drawLine(etage_3+25-300,275,etage_4+25,325);
                        const QRect rectangle = QRect(etage_4, 325, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_4, 325, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_4 += 75;
                    }
                }
                if ((cpt4 == 3) || (cpt4 == 4))
                {
                    if(n->valeur == 44444)
                    {
                        etage_4_bis += 75;
                    }
                    else
                    {
                        painter.drawLine(etage_3+25-150,275,etage_4_bis+25,325);
                        const QRect rectangle = QRect(etage_4_bis, 325, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_4_bis, 325, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_4_bis += 75;
                    }
                }
                if ((cpt4 == 5) || (cpt4 == 6))
                {
                    if(n->valeur == 44444)
                    {
                        etage_4_bis_bis += 75;
                    }
                    else
                    {
                        painter.drawLine(etage_3_bis+25-300,275,etage_4_bis_bis+25,325);
                        const QRect rectangle = QRect(etage_4_bis_bis, 325, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_4_bis_bis, 325, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_4_bis_bis += 75;
                    }
                }
                if ((cpt4 == 7) || (cpt4 == 8))
                {
                    if(n->valeur == 44444)
                    {
                        etage_4_bis_bis_bis += 75;
                    }
                    else
                    {
                        painter.drawLine(etage_3_bis+25-150,275,etage_4_bis_bis_bis+25,325);
                        const QRect rectangle = QRect(etage_4_bis_bis_bis, 325, 50, 50);
                        painter.setBrush(Qt::red);
                        painter.drawEllipse(etage_4_bis_bis_bis, 325, 50, 50);
                        painter.drawText(rectangle, Qt::AlignCenter, QString("%1").arg(n->valeur));
                        etage_4_bis_bis_bis += 75;
                    }
                }
                cpt4++;
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
                if(n->profondeur == 2)
                {
                    vide->valeur = 33333;       //Valeur aberante pour profondeur 2;
                    vide2->valeur = 33333;
                    vide->profondeur = 3;
                    vide2->profondeur = 3;
                }
                if(n->profondeur == 3)
                {
                    vide->valeur = 44444;       //Valeur aberante pour profondeur 3;
                    vide2->valeur = 44444;
                    vide->profondeur = 4;
                    vide2->profondeur = 4;
                }
                if(n->profondeur == 4)
                {
                    vide->valeur = 55555;       //Valeur aberante pour profondeur 4;
                    vide2->valeur = 55555;
                    vide->profondeur = 5;
                    vide2->profondeur = 5;
                }
                fifo.push(vide);
                fifo.push(vide2);
            }
        }
        //SI on a 1 fils Creation d'un sommet fantome pour conserver l'espacement
        if(((n->fils_droite == NULL) && (n->fils_gauche != NULL)) || ((n->fils_droite != NULL) && (n->fils_gauche == NULL)))
        {
            Sommet * vide = new Sommet;     //Sommet fantome
            vide->fils_droite = NULL;
            vide->fils_gauche = NULL;

            if((n->fils_droite == NULL) && (n->fils_gauche != NULL))
            {
                if(n->fils_gauche->profondeur == 2)
                {   vide->valeur = 22222;    vide->profondeur = 2;}       //Valeur aberante pour profondeur 2;
                if(n->fils_gauche->profondeur == 3)
                {   vide->valeur = 33333;    vide->profondeur = 3;}       //Valeur aberante pour profondeur 3;
                if(n->fils_gauche->profondeur == 4)
                {   vide->valeur = 44444;    vide->profondeur = 4;}       //Valeur aberante pour profondeur 4;
            }
            if((n->fils_droite != NULL) && (n->fils_gauche == NULL))
            {
                if(n->fils_droite->profondeur == 2)
                {   vide->valeur = 22222;    vide->profondeur = 2;}  //Valeur aberante pour profondeur 2;
                if(n->fils_droite->profondeur == 3)
                {   vide->valeur = 33333;    vide->profondeur = 3;}       //Valeur aberante pour profondeur 3;
                if(n->fils_droite->profondeur == 4)
                {   vide->valeur = 44444;    vide->profondeur = 4;}       //Valeur aberante pour profondeur 4;
            }

            fifo.push(vide);
        }
        if (n->fils_droite != NULL) fifo.push(n->fils_droite);       // Ajout du fils droit s'il existe

    }
}

MainWindow::MainWindow(QWidget *parent)
{
    setFixedSize(600,600);
    state_bouton = false;
    state_bouton_ajout = false;
    state_bouton_supp = false;
    m_bouton = new QPushButton("Afficher Arbre", this);
    m_bouton->setFont(QFont("Comic Sans MS", 10));
    m_bouton->move(250, 550);
    m_bouton_ajout = new QPushButton("Ajout valeur Arbre", this);
    m_bouton_ajout->setFont(QFont("Comic Sans MS", 10));
    m_bouton_ajout->move(50, 550);
    m_bouton_supp = new QPushButton("Supprimer valeur Arbre", this);
    m_bouton_supp->setFont(QFont("Comic Sans MS", 10));
    m_bouton_supp->move(400, 550);


    ArbreB B;
    B.Ajouter(5);
    B.Ajouter(8);
    B.Ajouter(2);
    B.Ajouter(0);
    courant = B;
    B.Ajouter(10);
    B.Ajouter(6);
    B.Ajouter(3);
    B.Ajouter(4);
    B.Ajouter(7);
    B.Ajouter(1);
    B.Ajouter(9);
    B.Ajouter(11);
    B.Ajouter(-1);

    courant_ajout = B;
    B.Affiche(B.racine,0);

    Sommet * ptr = B.Recherche(1);

    B.Supprimer(ptr);
    courant_supp = B;


    // Connexion du clic du bouton à l'affichage de l'arbre
    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(doPainting()));
    QObject::connect(m_bouton_ajout, SIGNAL(clicked()), this, SLOT(doPainting_ajout()));
    QObject::connect(m_bouton_supp, SIGNAL(clicked()), this, SLOT(doPainting_supp()));
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //QPushButton::paintEvent(event);
    if(state_bouton){
        affiche_arbre(courant);
    }
    if(state_bouton_ajout){
        affiche_arbre(courant_ajout);
    }
    if(state_bouton_supp){
        affiche_arbre(courant_supp);
    }

}

void MainWindow::doPainting()
{
    state_bouton = !state_bouton;
    update();
}
void MainWindow::doPainting_ajout()
{
    state_bouton_ajout = !state_bouton_ajout;
    update();
}
void MainWindow::doPainting_supp()
{
    state_bouton_supp = !state_bouton_supp;
    update();
}

