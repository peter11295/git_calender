#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    LineTotal=0;
    ui->setupUi(this);
    clock = new QTimer ;
    clock ->setInterval(1000);
    connect(clock,SIGNAL(timeout()),this,SLOT(updateTime()));
//    connect(clock,SIGNAL(timeout()),this,SLOT(updateDate()));
    connect(clock,SIGNAL(timeout()),this,SLOT(checktime()));

    clock->start();

    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly)){
        QString line ;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
            LineTotal++;
        }
    }
    addnote();
    qDebug()<<LineTotal;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString content,Time,Date;
    content=ui->textEdit->toPlainText();

    Date=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    Time=ui->timeEdit->time().toString("HH:mm");

    ui->textBrowser->append(Date+" "+Time);
    ui->textBrowser->append(content);

    QFile file("note.txt");
    if(file.open(QFile::WriteOnly |QFile::Append |QFile::Text))
    {
        QTextStream out(&file);
        out<<Date+" "+Time<<endl<<content<<endl;
    }
    addnote();
}

void MainWindow::updateTime()
{
    TimeNow=TimeNow.currentTime();
    DateNow=DateNow.currentDate();
    qDebug() << DateNow.toString("yyyy-MM-dd")+" "
                +TimeNow.toString("HH:mm");
}


void MainWindow::Warmingshow()
{
    Warming wm;
    wm.setModal(1);
    wm.exec();
}

void MainWindow::checktime()
{
    if(LineTotal!=0)
    {
        for(int i=0;i<(LineTotal/2);i++)
        {
            if((vector_date[i])==DateNow.toString("yyyy-MM-dd")+" "
                    +TimeNow.toString("HH:mm"))
            {               
                Warmingshow(); 
            }

        }
        qDebug()<<LineTotal;
        qDebug()<<vector_date[(LineTotal/2)-1];

    }
}

void MainWindow::addnote()
{
    vector_date.clear();
    vector_note.clear();
    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly)){
        int i=0;
        QString line ;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
            if(i%2==0)
            {
            vector_date.append(line);
            }
            if(i%2!=0)
            {
            vector_note.append(line);
            }
            i++;
        }
        LineTotal=i;
    }

}
