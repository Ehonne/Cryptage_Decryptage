#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include "QPainter"
#include <ArbreB.h>

class MainWindow : public QWidget {


    protected:
        void paintEvent(QPaintEvent* e);
    signals:

    public slots:

};

#endif // MAINWINDOW_H
