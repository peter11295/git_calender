/********************************************************************************
** Form generated from reading UI file 'warming.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARMING_H
#define UI_WARMING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Warming
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Warming)
    {
        if (Warming->objectName().isEmpty())
            Warming->setObjectName(QStringLiteral("Warming"));
        Warming->resize(508, 401);
        textBrowser = new QTextBrowser(Warming);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(60, 120, 361, 191));
        label = new QLabel(Warming);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 391, 41));
        QFont font;
        font.setPointSize(35);
        label->setFont(font);
        pushButton = new QPushButton(Warming);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 330, 161, 51));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);

        retranslateUi(Warming);

        QMetaObject::connectSlotsByName(Warming);
    } // setupUi

    void retranslateUi(QDialog *Warming)
    {
        Warming->setWindowTitle(QApplication::translate("Warming", "Dialog", 0));
        label->setText(QApplication::translate("Warming", "\344\270\211\345\215\201\345\210\206\351\220\230\345\211\215\346\217\220\351\206\222\344\275\240", 0));
        pushButton->setText(QApplication::translate("Warming", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Warming: public Ui_Warming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARMING_H
