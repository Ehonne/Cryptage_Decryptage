#ifndef TABLECRYPTAGEWINDOW_H
#define TABLECRYPTAGEWINDOW_H

#include <QDialog>
#include <map>
#include <iostream>

using namespace std;

namespace Ui {
class Tablecryptagewindow;
}

class Tablecryptagewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Tablecryptagewindow(QWidget *parent = nullptr);
    ~Tablecryptagewindow();
    map<char,string> get_map();

public slots:
    void Tablecryptage();


private:
    Ui::Tablecryptagewindow *ui;
    map<char,string> huffman;
};

#endif // TABLECRYPTAGEWINDOW_H
