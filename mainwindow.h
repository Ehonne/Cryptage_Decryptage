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

public slots:
    void doPainting();
    void Affiche_nouv_texte();
    void Affiche_ABR();

private:
     Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

