#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    bool test_erreur_decryptage();
    bool test_erreur_cryptage();

public slots:
    void makecryptage();
    void makedecryptage();
    void doPainting();
    void Affiche_nouv_texte();
    void Affiche_ABR();
    void Affiche_table_decryptage();
    void Affiche_nouv_texte_decrypte();
    void Affiche_ABR_decryp();

private:
     Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

