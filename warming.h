#ifndef WARMING_H
#define WARMING_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Warming;
}

class Warming : public QDialog
{
    Q_OBJECT

public:
    explicit Warming(QWidget *parent = 0);
    ~Warming();

private:
    Ui::Warming *ui;
};

#endif // WARMING_H
