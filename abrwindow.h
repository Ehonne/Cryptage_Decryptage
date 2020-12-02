#ifndef ABRWINDOW_H
#define ABRWINDOW_H

#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class AbrWindow;
}

class AbrWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AbrWindow(string boo, QWidget *parent = nullptr);
    string mots;
    void paintEvent(QPaintEvent *event);
    ~AbrWindow();

private:
    Ui::AbrWindow *ui;
};

#endif // ABRWINDOW_H
