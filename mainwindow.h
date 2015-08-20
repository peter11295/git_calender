#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include "warming.h"
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //void resetPrevioustime();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void updateTime();
    void updateDate();
    void Warmingshow();
    void checktime();
    void addnote();


private:
    Ui::MainWindow *ui; 
    QTimer *clock;
    QDate DateNow;
    QTime TimeNow,Previoustime;
    int LineTotal;
    QVector<QString>vector_date;
    QVector<QString>vector_note;
};

#endif // MAINWINDOW_H
