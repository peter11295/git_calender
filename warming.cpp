#include "warming.h"
#include "ui_warming.h"

Warming::Warming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warming)
{
    ui->setupUi(this);

    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly)){
        QString line ;
        QTextStream in(&file);
        while (!in.atEnd()){
            line=in.readLine();
        }
        ui->textBrowser->append(line);
    }
}

Warming::~Warming()
{
    delete ui;
}

void Warming::on_pushButton_clicked()
{
    close();
}
