/********************************************************************************
** Form generated from reading UI file 'grafic.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFIC_H
#define UI_GRAFIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Grafic
{
public:
    QWidget *centralwidget;
    QLabel *label_fun;
    QCustomPlot *widget;
    QPushButton *pushButton_gr;
    QSpinBox *spinBox_xs;
    QSpinBox *spinBox_xe;
    QSpinBox *spinBox_ye;
    QSpinBox *spinBox_ys;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *dinamicButton;
    QRadioButton *staticButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Grafic)
    {
        if (Grafic->objectName().isEmpty())
            Grafic->setObjectName(QString::fromUtf8("Grafic"));
        Grafic->setEnabled(true);
        Grafic->resize(606, 538);
        Grafic->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-color: #FFFAFA;\n"
"}"));
        Grafic->setIconSize(QSize(41, 32));
        Grafic->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Grafic->setAnimated(false);
        Grafic->setTabShape(QTabWidget::Rounded);
        Grafic->setDockNestingEnabled(false);
        Grafic->setDockOptions(QMainWindow::AllowTabbedDocks);
        Grafic->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(Grafic);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_fun = new QLabel(centralwidget);
        label_fun->setObjectName(QString::fromUtf8("label_fun"));
        label_fun->setGeometry(QRect(30, 20, 421, 51));
        QFont font;
        font.setPointSize(23);
        label_fun->setFont(font);
        label_fun->setStyleSheet(QString::fromUtf8("QLabel {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        label_fun->setIndent(1);
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 120, 551, 271));
        pushButton_gr = new QPushButton(centralwidget);
        pushButton_gr->setObjectName(QString::fromUtf8("pushButton_gr"));
        pushButton_gr->setGeometry(QRect(470, 20, 111, 51));
        QFont font1;
        font1.setPointSize(15);
        pushButton_gr->setFont(font1);
        pushButton_gr->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #F8F8FF;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_gr->setCheckable(false);
        spinBox_xs = new QSpinBox(centralwidget);
        spinBox_xs->setObjectName(QString::fromUtf8("spinBox_xs"));
        spinBox_xs->setGeometry(QRect(30, 460, 105, 31));
        spinBox_xs->setMinimum(-1000000);
        spinBox_xs->setMaximum(1000000);
        spinBox_xs->setValue(-10);
        spinBox_xe = new QSpinBox(centralwidget);
        spinBox_xe->setObjectName(QString::fromUtf8("spinBox_xe"));
        spinBox_xe->setGeometry(QRect(170, 460, 105, 31));
        spinBox_xe->setMinimum(-1000000);
        spinBox_xe->setMaximum(1000000);
        spinBox_xe->setValue(10);
        spinBox_ye = new QSpinBox(centralwidget);
        spinBox_ye->setObjectName(QString::fromUtf8("spinBox_ye"));
        spinBox_ye->setGeometry(QRect(480, 460, 105, 31));
        spinBox_ye->setMinimum(-1000000);
        spinBox_ye->setMaximum(1000000);
        spinBox_ye->setValue(10);
        spinBox_ys = new QSpinBox(centralwidget);
        spinBox_ys->setObjectName(QString::fromUtf8("spinBox_ys"));
        spinBox_ys->setGeometry(QRect(340, 460, 105, 31));
        spinBox_ys->setMinimum(-1000000);
        spinBox_ys->setMaximum(1000000);
        spinBox_ys->setValue(-10);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 410, 248, 31));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 410, 248, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        dinamicButton = new QRadioButton(centralwidget);
        dinamicButton->setObjectName(QString::fromUtf8("dinamicButton"));
        dinamicButton->setGeometry(QRect(30, 80, 181, 20));
        dinamicButton->setFont(font1);
        dinamicButton->setChecked(true);
        staticButton = new QRadioButton(centralwidget);
        staticButton->setObjectName(QString::fromUtf8("staticButton"));
        staticButton->setGeometry(QRect(230, 80, 151, 20));
        staticButton->setFont(font1);
        Grafic->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Grafic);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Grafic->setStatusBar(statusbar);

        retranslateUi(Grafic);

        QMetaObject::connectSlotsByName(Grafic);
    } // setupUi

    void retranslateUi(QMainWindow *Grafic)
    {
        Grafic->setWindowTitle(QCoreApplication::translate("Grafic", "MainWindow", nullptr));
#if QT_CONFIG(statustip)
        Grafic->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        Grafic->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_fun->setText(QCoreApplication::translate("Grafic", "TextLabel", nullptr));
        pushButton_gr->setText(QCoreApplication::translate("Grafic", "Graph", nullptr));
        label->setText(QCoreApplication::translate("Grafic", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("Grafic", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        dinamicButton->setText(QCoreApplication::translate("Grafic", "\320\224\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        staticButton->setText(QCoreApplication::translate("Grafic", "\320\241\321\202\320\260\321\202\320\270\321\207\320\275\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Grafic: public Ui_Grafic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFIC_H
