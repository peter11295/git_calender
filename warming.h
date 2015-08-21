#ifndef WARMING_H
#define WARMING_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QTime>
#include <QDate>
#include <QVector>

namespace Ui {
class Warming;
}

class Warming : public QDialog
{
    Q_OBJECT

public:
    explicit Warming(QWidget *parent = 0);
    ~Warming();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Warming *ui;

};

#endif // WARMING_H
