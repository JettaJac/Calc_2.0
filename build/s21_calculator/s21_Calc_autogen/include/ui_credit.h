/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_period;
    QLabel *total_overpayment;
    QLabel *overpayment;
    QLabel *month_min;
    QDoubleSpinBox *doubleSpinBox_precent_rate;
    QLabel *month_max;
    QSpinBox *spinBox_totalcredit;
    QPushButton *pushButton;
    QLabel *overpayment_2;
    QLabel *overpayment_3;
    QCheckBox *checkBox_aunt;
    QCheckBox *checkBox_diff;
    QCheckBox *checkBox_month;
    QCheckBox *checkBox_year;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName(QString::fromUtf8("Credit"));
        Credit->setEnabled(true);
        Credit->resize(606, 538);
        Credit->setMinimumSize(QSize(606, 538));
        Credit->setMaximumSize(QSize(606, 538));
        Credit->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color: #F8F8FF;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        centralwidget = new QWidget(Credit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 291, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 181, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 380, 181, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 181, 31));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 270, 181, 31));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 270, 181, 31));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 170, 201, 31));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 70, 221, 31));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        doubleSpinBox_period = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_period->setObjectName(QString::fromUtf8("doubleSpinBox_period"));
        doubleSpinBox_period->setGeometry(QRect(30, 436, 231, 41));
        QFont font2;
        font2.setPointSize(17);
        doubleSpinBox_period->setFont(font2);
        doubleSpinBox_period->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        doubleSpinBox_period->setDecimals(0);
        doubleSpinBox_period->setMaximum(2000.000000000000000);
        doubleSpinBox_period->setValue(12.000000000000000);
        total_overpayment = new QLabel(centralwidget);
        total_overpayment->setObjectName(QString::fromUtf8("total_overpayment"));
        total_overpayment->setGeometry(QRect(330, 100, 241, 41));
        total_overpayment->setFont(font2);
        total_overpayment->setStyleSheet(QString::fromUtf8("QLabel {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        overpayment = new QLabel(centralwidget);
        overpayment->setObjectName(QString::fromUtf8("overpayment"));
        overpayment->setGeometry(QRect(330, 200, 241, 41));
        overpayment->setFont(font2);
        overpayment->setStyleSheet(QString::fromUtf8("QLabel {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        month_min = new QLabel(centralwidget);
        month_min->setObjectName(QString::fromUtf8("month_min"));
        month_min->setGeometry(QRect(450, 360, 121, 41));
        month_min->setFont(font2);
        month_min->setStyleSheet(QString::fromUtf8("QLabel {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        doubleSpinBox_precent_rate = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_precent_rate->setObjectName(QString::fromUtf8("doubleSpinBox_precent_rate"));
        doubleSpinBox_precent_rate->setGeometry(QRect(30, 200, 101, 41));
        doubleSpinBox_precent_rate->setFont(font2);
        doubleSpinBox_precent_rate->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color:  black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        doubleSpinBox_precent_rate->setDecimals(1);
        doubleSpinBox_precent_rate->setValue(10.000000000000000);
        month_max = new QLabel(centralwidget);
        month_max->setObjectName(QString::fromUtf8("month_max"));
        month_max->setGeometry(QRect(450, 300, 121, 41));
        month_max->setFont(font2);
        month_max->setStyleSheet(QString::fromUtf8("QLabel {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        spinBox_totalcredit = new QSpinBox(centralwidget);
        spinBox_totalcredit->setObjectName(QString::fromUtf8("spinBox_totalcredit"));
        spinBox_totalcredit->setGeometry(QRect(30, 100, 241, 41));
        spinBox_totalcredit->setFont(font2);
        spinBox_totalcredit->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"padding: 9px;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"color:  black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        spinBox_totalcredit->setMinimum(10000);
        spinBox_totalcredit->setMaximum(100000000);
        spinBox_totalcredit->setSingleStep(1000);
        spinBox_totalcredit->setValue(50000);
        spinBox_totalcredit->setDisplayIntegerBase(10);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 436, 241, 41));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color:  black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        overpayment_2 = new QLabel(centralwidget);
        overpayment_2->setObjectName(QString::fromUtf8("overpayment_2"));
        overpayment_2->setGeometry(QRect(330, 360, 101, 31));
        overpayment_2->setFont(font1);
        overpayment_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        overpayment_3 = new QLabel(centralwidget);
        overpayment_3->setObjectName(QString::fromUtf8("overpayment_3"));
        overpayment_3->setGeometry(QRect(330, 310, 111, 31));
        overpayment_3->setFont(font1);
        overpayment_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:  black;\n"
"}"));
        checkBox_aunt = new QCheckBox(centralwidget);
        checkBox_aunt->setObjectName(QString::fromUtf8("checkBox_aunt"));
        checkBox_aunt->setEnabled(true);
        checkBox_aunt->setGeometry(QRect(30, 300, 121, 21));
        QFont font3;
        font3.setPointSize(15);
        checkBox_aunt->setFont(font3);
        checkBox_aunt->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	color:  black;\n"
"}"));
        checkBox_aunt->setChecked(true);
        checkBox_diff = new QCheckBox(centralwidget);
        checkBox_diff->setObjectName(QString::fromUtf8("checkBox_diff"));
        checkBox_diff->setGeometry(QRect(30, 330, 121, 21));
        checkBox_diff->setFont(font3);
        checkBox_diff->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	color:  black;\n"
"}"));
        checkBox_month = new QCheckBox(centralwidget);
        checkBox_month->setObjectName(QString::fromUtf8("checkBox_month"));
        checkBox_month->setGeometry(QRect(30, 410, 121, 21));
        checkBox_month->setFont(font3);
        checkBox_month->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	color:  black;\n"
"}"));
        checkBox_month->setChecked(true);
        checkBox_year = new QCheckBox(centralwidget);
        checkBox_year->setObjectName(QString::fromUtf8("checkBox_year"));
        checkBox_year->setGeometry(QRect(140, 410, 121, 21));
        checkBox_year->setFont(font3);
        checkBox_year->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	color:  black;\n"
"}"));
        Credit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Credit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 606, 24));
        Credit->setMenuBar(menubar);
        statusbar = new QStatusBar(Credit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Credit->setStatusBar(statusbar);

        retranslateUi(Credit);

        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QMainWindow *Credit)
    {
        Credit->setWindowTitle(QCoreApplication::translate("Credit", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Credit", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_2->setText(QCoreApplication::translate("Credit", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("Credit", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Credit", "\320\242\320\270\320\277 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        label_6->setText(QCoreApplication::translate("Credit", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266:", nullptr));
        label_7->setText(QCoreApplication::translate("Credit", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\321\213 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203 (%)", nullptr));
        label_8->setText(QCoreApplication::translate("Credit", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        total_overpayment->setText(QCoreApplication::translate("Credit", "0", nullptr));
        overpayment->setText(QCoreApplication::translate("Credit", "0", nullptr));
        month_min->setText(QCoreApplication::translate("Credit", "0", nullptr));
        month_max->setText(QCoreApplication::translate("Credit", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("Credit", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        overpayment_2->setText(QCoreApplication::translate("Credit", "\320\234\320\270\320\275.\320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        overpayment_3->setText(QCoreApplication::translate("Credit", "\320\234\320\260\320\272\321\201.\320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        checkBox_aunt->setText(QCoreApplication::translate("Credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        checkBox_diff->setText(QCoreApplication::translate("Credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        checkBox_month->setText(QCoreApplication::translate("Credit", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        checkBox_year->setText(QCoreApplication::translate("Credit", "\320\233\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
