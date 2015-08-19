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
    clock->start();
    clock->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString content,Time,Date;
    QDate date;
    QTime time,Previoustime;

    content=ui->textEdit->toPlainText();
    date=ui->calendarWidget->selectedDate();
    Date=ui->calendarWidget->selectedDate().toString();
    time=ui->timeEdit->time();
    Time=ui->timeEdit->time().toString("hh:mm a");
    Previoustime=time.addMSecs(-30);

    ui->textBrowser->append(Date+" "+Time);
    ui->textBrowser->append(content);

    QFile file("note.txt");
    if(file.open(QFile::WriteOnly |QFile::Truncate |QFile::Text))
    {
        QTextStream out(&file);
        out<<Date+" "+Time<<endl<<content<<endl;
    }
    if(Previoustime==TimeNow)
    {
        ui->Warmingshow();
    }

}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

}

void MainWindow::updateTime()
{
    TimeNow=TimeNow.currentTime();
}

void MainWindow::updateDate()
{
    DateNow=DateNow.currentDate();
}

void MainWindow::Warmingshow()
{
    Warming WM;
    WM.show();
}
