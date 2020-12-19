#ifndef ABRWINDOW_H
#define ABRWINDOW_H

#include <QDialog>
#include <iostream>
#include <map>

using namespace std;

namespace Ui {
class AbrWindow;
}

class AbrWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AbrWindow(string boo, QWidget *parent = nullptr);
    explicit AbrWindow(map<char,string> huffman, QWidget *parent = nullptr);
    string mots;
    map<char,string> huffmann;
    int mode; //1 cryptage 2 decryptage
    void paintEvent(QPaintEvent *event);
    ~AbrWindow();

private:
    Ui::AbrWindow *ui;
};

#endif // ABRWINDOW_H
