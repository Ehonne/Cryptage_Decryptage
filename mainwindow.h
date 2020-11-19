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
    static ArbreB courant;
    static ArbreB courant_ajout;
    static ArbreB courant_supp;
    static ArbreB courant_addi;
    static ArbreB courant_A;
    static ArbreB courant_fusion;
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent * event);
    void affiche_arbre(ArbreB B);

public slots:
    void doPainting();
    void doPainting_ajout();
    void doPainting_supp();
    void doPainting_addi();
    void doPainting_A();
    void doPainting_fusion();

private:
     QPushButton *m_bouton;
     QPushButton *m_bouton_ajout;
     QPushButton *m_bouton_supp;
     QPushButton *m_bouton_addi;
     QPushButton *m_bouton_A;
     QPushButton *m_bouton_fusion;
     bool state_bouton;
     bool state_bouton_ajout;
     bool state_bouton_supp;
     bool state_bouton_addi;
     bool state_bouton_A;
     bool state_bouton_fusion;


};

#endif // MAINWINDOW_H
