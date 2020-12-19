#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ArbreB.h>
#include "occurence.h"
#include <queue>
#include <Sommet.h>
#include <math.h>
#include <QPoint>
#include "abrwindow.h"
#include "tablecryptagewindow.h"
#include <QMessageBox>

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

bool MainWindow::test_erreur_cryptage()
{
    QString text = ui->textEdit->toPlainText();
    if(text.isEmpty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Vous n'avez pas saisie de texte !");
        return false;
    }
    return true;
}
bool MainWindow::test_erreur_decryptage()
{
    string str = ui->textEdit->toPlainText().toStdString();
    if(str.empty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Vous n'avez pas saisie de texte !");
        return false;
    }

    for(int i = 0; i < (int)str.size(); i++)
    {
        if((str[i] != '0') && (str[i] != '1'))
        {
            QMessageBox::critical(this, "Erreur de saisie", "Vérifiez que vous avez bien rentré un code binaire.");
            return false;
        }
    }
    return true;
}

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);  //Creation bouton et fentrre de saisie et de renvoie

    ui->Cryptage->setVisible(false);
    ui->Affiche_Arbre->setVisible(false);
    ui->Affiche_nouv->setVisible(false);
    ui->Cryptage_3->setVisible(false);
    ui->Affiche_Arbre_2->setVisible(false);
    ui->Affiche_nouv_2->setVisible(false);
    ui->changementC->setVisible(false);
    ui->changementD->setVisible(false);



    QObject::connect(ui->Cryptage_2, SIGNAL(clicked()), this, SLOT(makecryptage()));
    QObject::connect(ui->changementC, SIGNAL(clicked()), this, SLOT(makecryptage()));
    QObject::connect(ui->changementD, SIGNAL(clicked()), this, SLOT(makedecryptage()));
    QObject::connect(ui->Decryptage, SIGNAL(clicked()), this, SLOT(makedecryptage()));
    //Bouton cryptage
    QObject::connect(ui->Cryptage, SIGNAL(clicked()), this, SLOT(doPainting())); //Renvoi le nombre d 'occurance de chaque lettre
    QObject::connect(ui->Affiche_nouv, SIGNAL(clicked()), this, SLOT(Affiche_nouv_texte()));    //Affiche le nouveau texte encodé
    QObject::connect(ui->Affiche_Arbre, SIGNAL(clicked()), this, SLOT(Affiche_ABR()));      //Affiche l'abre binaire associé au texte initiale dnas une nouvelle fenttre bloquante
    //Bouton decryptage
    QObject::connect(ui->Cryptage_3, SIGNAL(clicked()), this, SLOT(Affiche_table_decryptage())); //Renvoi le nombre d 'occurance de chaque lettre
    QObject::connect(ui->Affiche_nouv_2, SIGNAL(clicked()), this, SLOT(Affiche_nouv_texte_decrypte()));    //Affiche le nouveau texte encodé
    QObject::connect(ui->Affiche_Arbre_2, SIGNAL(clicked()), this, SLOT(Affiche_ABR_decryp()));      //Affiche l'abre binaire associé au texte initiale dnas une nouvelle fenttre bloquante

}

void MainWindow::makecryptage()
{
    //Bouton principal
    ui->Cryptage_2->setVisible(false);
    ui->Decryptage->setVisible(false);
    //Bouton changement etat
    ui->changementC->setVisible(false);
    ui->changementD->setVisible(true);
    //Bouton decryptage
    ui->Cryptage_3->setVisible(false);
    ui->Affiche_Arbre_2->setVisible(false);
    ui->Affiche_nouv_2->setVisible(false);
    //Bouton cryptage
    ui->Cryptage->setVisible(true);
    ui->Affiche_Arbre->setVisible(true);
    ui->Affiche_nouv->setVisible(true);

    ui->textBrowser->clear();
    string texte_dep = "Tapez ici le texte que vous voulez crypter. (Attention les caractères a accents ne sont pas acceptés)";
    QString text = QString::fromStdString(texte_dep);
    ui->textEdit->setText(text);
}

void MainWindow::makedecryptage()
{
    //Bouton principal
    ui->Cryptage_2->setVisible(false);
    ui->Decryptage->setVisible(false);
    //Bouton changement etat
    ui->changementD->setVisible(false);
    ui->changementC->setVisible(true);
    //Bouton cryptage
    ui->Cryptage->setVisible(false);
    ui->Affiche_Arbre->setVisible(false);
    ui->Affiche_nouv->setVisible(false);
    //Bouton decryptage
    ui->Cryptage_3->setVisible(true);
    ui->Affiche_Arbre_2->setVisible(true);
    ui->Affiche_nouv_2->setVisible(true);

    ui->textBrowser->clear();
    string texte_dep = "Tapez ici le code binaire que vous voulez decrypter.";
    QString text = QString::fromStdString(texte_dep);
    ui->textEdit->setText(text);
}


void MainWindow::doPainting()
{
    QString text = ui->textEdit->toPlainText();
    if(!test_erreur_cryptage())
        return;
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

    //Afficher occurence de chaque lettre
    //test.print_occurence();
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
    string table_cryptage = "";
    for(int i(0); i<(int)(abr.codage.size()); ++i)
    {
        table_cryptage += test.arr[i];
        table_cryptage += " : " + abr.codage[i] + "\n";
    }
    QString qstr = QString::fromStdString(table_cryptage);
    ui->textBrowser->setText(qstr);
    TT.clear();

}

void MainWindow::Affiche_nouv_texte()
{
    QString text = ui->textEdit->toPlainText();
    if(!test_erreur_cryptage())
        return;
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
    if(!test_erreur_cryptage())
        return;
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


void MainWindow::Affiche_table_decryptage()
{
    if(!test_erreur_decryptage())
        return;

    Tablecryptagewindow tbl;
    tbl.setModal(true);
    tbl.exec();

    map<char,string> huffman = tbl.get_map();
    if(huffman.empty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Vous n'avez pas rentré de texte !");
        return;
    }

    map<char, string>::iterator itr;
    string table_decryptage;
    for (itr = huffman.begin(); itr != huffman.end(); ++itr) {
           table_decryptage.push_back(itr->first) ;
           table_decryptage += "  " + itr->second + '\n';
    }

    QString qstr = QString::fromStdString(table_decryptage);
    ui->textBrowser->setText(qstr);

}

void MainWindow::Affiche_ABR_decryp()
{
    if(!test_erreur_decryptage())
        return;

    Tablecryptagewindow tbl;
    tbl.setModal(true);
    tbl.exec();

    map<char,string> huffman = tbl.get_map();
    if(huffman.empty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Vous n'avez pas rentré de texte !");
        return;
    }

    AbrWindow secWind(huffman);   //creation de la nouvelle fenettre
    secWind.setModal(true);        //Met la fenetre en priorité elevé
    secWind.exec();
    secWind.setAttribute(Qt::WA_DeleteOnClose); //Supprime memoir lorsque l'on clic sur la croix
}

void MainWindow::Affiche_nouv_texte_decrypte()
{
    if(!test_erreur_decryptage())
        return;

    Tablecryptagewindow tbl;
    tbl.setModal(true);
    tbl.exec();


    map<char,string> huffman = tbl.get_map(); //Obtention table de cryptage
    if(huffman.empty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Vous n'avez pas rentré de texte !");
        return;
    }

    string chaineCrypte = ui->textEdit->toPlainText().toStdString();               // le txt crypté entré par l'utilisateur
    map<char, string>::iterator itr;

    ArbreB abr;         // on initialise un nouvel arbre :
    abr.Ajouter(0);     // on ajoute une racine d'étiquette (caractère) 0

    // On construit l'arbre :
    for (itr = huffman.begin(); itr != huffman.end(); ++itr)
    {
        abr.AjouterCar(itr->first, itr->second);    // on ajoute les sommets nécessaire pour pouvoir accéder au caractère itr->first
                                                            // en utilisant le code binaire, c'est à dire itr->second
    }

    string chaineDecrypte = "";         // notre résultat texte
    chaineDecrypte = abr.decrypte(chaineCrypte);    // appel de la fonction pour decrypter

    if(chaineDecrypte.empty())
    {
        QMessageBox::critical(this, "Erreur de saisie", "Aucun texte decryptage a partir de cette table de decryptage et de ce code bianire !");
        return;
    }
    QString qstr = QString::fromStdString(chaineDecrypte);
    ui->textBrowser->setText(qstr);
}
