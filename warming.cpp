#include "warming.h"
#include "ui_warming.h"

Warming::Warming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warming)
{
    ui->setupUi(this); 
}

Warming::~Warming()
{
    delete ui;
}

void Warming::on_pushButton_clicked()
{
    close();
}
