#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include <warming.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_calendarWidget_clicked(const QDate &date);
    void updateTime();
    void updateDate();
    void Warmingshow();

private:
    Ui::MainWindow *ui; 
    QTimer *clock;
    QDate DateNow;
    QTime TimeNow;
};

#endif // MAINWINDOW_H
