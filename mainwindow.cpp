#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clock = new QTimer ;
    clock ->setInterval(1000);
    connect(clock,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(clock,SIGNAL(timeout()),this,SLOT(updateDate()));
    connect(clock,SIGNAL(timeout()),this,SLOT(Warmingshow()));
    connect(clock,SIGNAL(timeout()),this,SLOT(checktime()));

    clock->start();

    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly)){
        int i=0;
        QString line ;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
            i++;
        }
        LineTotal=i;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString content,Time,Date;
    QDate date;
    QTime time;

    content=ui->textEdit->toPlainText();
//    date=ui->calendarWidget->selectedDate();
    Date=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
//    time=ui->timeEdit->time();
    Time=ui->timeEdit->time().toString("hh:mm a");
//    Previoustime=time.addSecs(-1800);

    ui->textBrowser->append(Date+" "+Time);
    ui->textBrowser->append(content);

    QFile file("note.txt");
    if(file.open(QFile::WriteOnly |QFile::Append |QFile::Text))
    {
        QTextStream out(&file);
        out<<Date+" "+Time<<endl<<content<<endl;
    }
    qDebug()<<Previoustime.toString("hh:mm");


}


void MainWindow::updateTime()
{
    TimeNow=TimeNow.currentTime();
    qDebug() << TimeNow.toString("hh:mm");
}

void MainWindow::updateDate()
{
    DateNow=DateNow.currentDate();
}

void MainWindow::Warmingshow()
{
//    if(TimeNow.toString("hh:mm")>=Previoustime.toString("hh:mm")
//            &&TimeNow.toString("hh:mm")<=Previoustime.addSecs(1800).toString("hh:mm"))

        Warming WM;
        WM.setModal(1);
        WM.exec();
//        Previoustime=Previoustime.addSecs(-3600);

}

void MainWindow::checktime()
{

    for(int i=0;i<=LineTotal;i++)
    {
        int j=i*2;
        if((vector_date.at(j))==TimeNow.toString("yyyy-MM-dd hh:mm"))
        {
            Warmingshow();
        }
    }
}

void MainWindow::addnote()
{

    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly)){
        int i=0;
        QString line ;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
            if(i%2==0)
            {
            vector_date.append("line");
            }
            if(i%2!=0)
            {
            vector_note.append("line");
            }
            i+=1;
        }
    }
}
