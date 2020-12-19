#include "abrwindow.h"
#include "ui_abrwindow.h"
#include "QPainter"
#include <iostream>
#include <ArbreB.h>
#include "occurence.h"
#include <queue>
#include <Sommet.h>
#include <QPoint>
#include <QBrush>

int WIDTH  = 800;
int VSPACE = 50;

vector<Sommet *> T;

Sommet* ajout_sommets(int freq, char c)
{
    Sommet * s = new Sommet;
    s->fils_gauche = NULL;
    s->fils_droite = NULL;
    s->caractere = c;
    s->valeur = freq;

    return s;
}

// recherche le sommet le plus petit dans le vecteur :
Sommet * recherche_mins()
{
    int min(9999), index(0);
    for(int i(0); i<(int)(T.size()); ++i)
    {
            if (min > T[i]->valeur) {
                min = T[i]->valeur;
                index = i;
            }
    }
   // cout << endl << "frequence : " << T[index]->valeur << " et " << T[index]->caractere << " // ";
    Sommet * s = T[index];
    T.erase(T.begin()+index);
    return s;
}

// fusionne et ajoute un sommet dans le vecteur :
void mins()
{
    // on prend les deux min :
    Sommet * s1 = recherche_mins();
    Sommet * s2 = recherche_mins();

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
    T.push_back(nouv);
}

AbrWindow::AbrWindow(string bobo, QWidget *parent) : QDialog(parent), ui(new Ui::AbrWindow)
{
    ui->setupUi(this);

    mots = bobo;
    mode = 1;
    WIDTH = mots.size() * 47;
    setFixedWidth(WIDTH);
}

AbrWindow::AbrWindow(map<char,string> huffman, QWidget *parent) : QDialog(parent), ui(new Ui::AbrWindow)
{
    ui->setupUi(this);

    mode = 2;
    huffmann = huffman;
    WIDTH = huffmann.size() * 49;
    resize(WIDTH,600);
}
void drawGraph(Sommet *node, QPainter *painter){

    QString test(QChar(node->caractere));
    const QRect rectangle = QRect((int)node->x, (int)node->y, 25, 25);
    painter->setBrush(Qt::red);
    painter->drawEllipse((int)node->x, (int)node->y, 25, 25);
    painter->drawText((int)node->x+27, (int)node->y+4,test);
    painter->drawText(rectangle, Qt::AlignCenter, QString("%1").arg(node->valeur));

    if(node->fils_gauche != NULL){
        node->fils_gauche->y = node->y + VSPACE;
        node->fils_gauche->x = node->x - WIDTH/(1<<(node->profondeur+1));
        node->fils_gauche->profondeur = node->profondeur + 1;
        painter->drawLine((int)node->x+18, (int)node->y+25,(int)node->fils_gauche->x+3, (int)node->fils_gauche->y+3);
        drawGraph(node->fils_gauche, painter);
    }
    if(node->fils_droite != NULL){
        node->fils_droite->y = node->y + VSPACE;
        node->fils_droite->x = node->x + WIDTH/(1<<(node->profondeur+1));
        node->fils_droite->profondeur = node->profondeur + 1;
        painter->drawLine((int)node->x+18, (int)node->y+25,(int)node->fils_droite->x+3, (int)node->fils_droite->y+3);
        drawGraph(node->fils_droite, painter);
    }
}
void AbrWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    if(mode == 1)
    {
        QString text = QString::fromStdString(mots);
        Occurence test(text.toStdString());

            // création d'un tableau d'arbre :
        for(int i(0); i<(int)(test.arr.size()); ++i)
        {
            T.push_back(ajout_sommets(test.frequence[i], test.arr[i]));
        }

            // boucle tant que la taille du vecteur n'est pas égale à 1
        while((int)(T.size()) > 1)
        {
            mins();
        }
        ArbreB abr;
        abr.racine = T[0];


        abr.racine->y = VSPACE;
        abr.racine->x = WIDTH/2.0;
        abr.racine->profondeur = 1;
        if(abr.racine != NULL){
            drawGraph(abr.racine, &painter);
        }
    T.clear();
    }
    if(mode == 2)
    {
        map<char, string>::iterator itr;

        ArbreB abr;         // on initialise un nouvel arbre :
        abr.Ajouter(0);     // on ajoute une racine d'étiquette (caractère) 0

        // On construit l'arbre :
        for (itr = huffmann.begin(); itr != huffmann.end(); ++itr)
        {cout << itr->first << itr->second << endl;
            abr.AjouterCar(itr->first, itr->second);    // on ajoute les sommets nécessaire pour pouvoir accéder au caractère itr->first
                                                                // en utilisant le code binaire, c'est à dire itr->second
        }
        abr.Affiche(abr.racine,0);
        abr.racine->y = VSPACE;
        abr.racine->x = WIDTH/2.0;
        abr.racine->profondeur = 1;
        if(abr.racine != NULL){
            drawGraph(abr.racine, &painter);
        }
    }


}


AbrWindow::~AbrWindow()
{
    delete ui;
}
