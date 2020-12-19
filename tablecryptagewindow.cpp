#include "tablecryptagewindow.h"
#include "ui_tablecryptagewindow.h"
#include <map>
#include <sstream>
#include <QMessageBox>
#include <QString>

Tablecryptagewindow::Tablecryptagewindow(QWidget *parent) :QDialog(parent), ui(new Ui::Tablecryptagewindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Tablecryptage()));
}

Tablecryptagewindow::~Tablecryptagewindow()
{
    delete ui;
}

void Tablecryptagewindow::Tablecryptage()
{
    QString TOTOO = ui->textEdit->toPlainText();
    string TOTO = TOTOO.toStdString();


    std::istringstream f(TOTO);
    std::string line;
    int j = 0;
    while (std::getline(f, line)) { //On travail ligne par ligne
        string code_binaire;
        if(line[2] != ':') //Respect de la forme demandée
        {
            QMessageBox::critical(this, "Erreur de saisie", "Vérifiez que vous avez bien rentré des codes binaires ainsi que des caracteres autorisés. Attention aussi a avoir respecter la forme demandée.");
            return;
        }
        for(int i = 4; i < (int)line.size(); i++)
        {
            if((line[i] != '0') && (line[i] != '1'))
            {
                cout << "caractere :" << i << ":" << line[i] << "ligne :" << j << endl;
                QMessageBox::critical(this, "Erreur de saisie", "Vérifiez que vous avez bien rentré des codes binaires ainsi que des caracteres autorisés. Attention aussi a avoir respecter la forme demandée.");
                return;
             }
             code_binaire.push_back(line[i]);   //on rempli notre string avec les 0 et 1

         }
         huffman.insert(pair<char, string>(line[0],code_binaire));  //On rempli notre map avec le char et son code binaire
         j++;
    }
    close();
}

map<char,string> Tablecryptagewindow::get_map()
{
    return huffman;
}
