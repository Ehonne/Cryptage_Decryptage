#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include "QPainter"
#include <ArbreB.h>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent * event);
    void affiche_arbre(ArbreB B);

public slots:
    void doPainting();
    void doPainting_ajout();
    void doPainting_supp();

private:
     QPushButton *m_bouton;
     QPushButton *m_bouton_ajout;
     QPushButton *m_bouton_supp;
     bool state_bouton;
     bool state_bouton_ajout;
     bool state_bouton_supp;
     ArbreB courant;
     ArbreB courant_ajout;
     ArbreB courant_supp;

};

#endif // MAINWINDOW_H
