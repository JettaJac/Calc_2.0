/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_bin;
    QPushButton *pushButton_div;
    QPushButton *pushButton_proc;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_5;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_0;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_x;
    QPushButton *pushButton_del;
    QPushButton *pushButton_lb;
    QPushButton *pushButton_log;
    QPushButton *pushButton_rb;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_atag;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_pov;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_mod;
    QLabel *data_x;
    QLabel *err_c;
    QLabel *err_x;
    QDoubleSpinBox *doubleSpinBox_x;
    QPushButton *pushButton_graph;
    QLabel *result_show_2;
    QPushButton *pushButton_credit;
    QPushButton *pushButton_E;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(606, 538);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(606, 538));
        MainWindow->setMaximumSize(QSize(606, 538));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"qproperty-aligment: 'AlignVCenter | AlignRight';\n"
"border-botton: 5px solid green;\n"
"background-color : #FFFAFA;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"\n"
"background-color : #FFFAFA;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result_show = new QLabel(centralwidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setEnabled(true);
        result_show->setGeometry(QRect(30, 28, 415, 69));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        result_show->setFont(font);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"qproperty-alignment: 'AlignRight';\n"
"background-color: white;\n"
"border: 1px solid grey;\n"
"border-radius: 8px;\n"
"  margin: 4px;\n"
"  padding: 4px;\n"
"  font-size: 23px;\n"
"color: black;\n"
"}\n"
"\n"
"background-color: white;"));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(520, 32, 61, 61));
        QFont font1;
        font1.setPointSize(23);
        pushButton_clear->setFont(font1);
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #F8F8FF;\n"
"border: 1px solid gray;\n"
"border-radius: 8px; \n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #FFFAFA);\n"
"}"));
        pushButton_bin = new QPushButton(centralwidget);
        pushButton_bin->setObjectName(QString::fromUtf8("pushButton_bin"));
        pushButton_bin->setGeometry(QRect(1000, 500, 61, 61));
        pushButton_bin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(240, 320, 61, 61));
        QFont font2;
        font2.setPointSize(18);
        pushButton_div->setFont(font2);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_proc = new QPushButton(centralwidget);
        pushButton_proc->setObjectName(QString::fromUtf8("pushButton_proc"));
        pushButton_proc->setGeometry(QRect(1000, 430, 61, 61));
        pushButton_proc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(215, 215, 215);\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(170, 110, 61, 61));
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(100, 110, 61, 61));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 110, 61, 61));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(240, 250, 61, 61));
        pushButton_mult->setFont(font2);
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(100, 180, 61, 61));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(240, 180, 61, 61));
        pushButton_minus->setFont(font2);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(170, 320, 61, 61));
        pushButton_dot->setFont(font2);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_eq = new QPushButton(centralwidget);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(310, 390, 271, 61));
        pushButton_eq->setFont(font2);
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #F8F8FF;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(30, 320, 131, 61));
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(170, 180, 61, 61));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 180, 61, 61));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 250, 61, 61));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(240, 110, 61, 61));
        pushButton_plus->setFont(font2);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 250, 61, 61));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(30, 250, 61, 61));
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"background-color: #FFFAFA;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(452, 321, 58, 58));
        pushButton_x->setFont(font2);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(450, 32, 61, 61));
        QFont font3;
        font3.setPointSize(20);
        pushButton_del->setFont(font3);
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #F8F8FF;\n"
"border: 1px solid gray;\n"
"border-radius: 8px; \n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #FFFAFA);\n"
"}"));
        pushButton_lb = new QPushButton(centralwidget);
        pushButton_lb->setObjectName(QString::fromUtf8("pushButton_lb"));
        pushButton_lb->setGeometry(QRect(450, 250, 61, 61));
        pushButton_lb->setFont(font2);
        pushButton_lb->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(450, 180, 61, 61));
        pushButton_log->setFont(font2);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_rb = new QPushButton(centralwidget);
        pushButton_rb->setObjectName(QString::fromUtf8("pushButton_rb"));
        pushButton_rb->setGeometry(QRect(520, 250, 61, 61));
        pushButton_rb->setFont(font2);
        pushButton_rb->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(520, 180, 61, 61));
        pushButton_ln->setFont(font2);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_atag = new QPushButton(centralwidget);
        pushButton_atag->setObjectName(QString::fromUtf8("pushButton_atag"));
        pushButton_atag->setGeometry(QRect(520, 110, 61, 61));
        pushButton_atag->setFont(font2);
        pushButton_atag->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(380, 180, 61, 61));
        pushButton_acos->setFont(font2);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(310, 180, 61, 61));
        pushButton_asin->setFont(font2);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(310, 110, 61, 61));
        pushButton_sin->setFont(font2);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(380, 110, 61, 61));
        pushButton_cos->setFont(font2);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(450, 110, 61, 61));
        pushButton_tan->setFont(font2);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_pov = new QPushButton(centralwidget);
        pushButton_pov->setObjectName(QString::fromUtf8("pushButton_pov"));
        pushButton_pov->setGeometry(QRect(380, 250, 61, 61));
        pushButton_pov->setFont(font2);
        pushButton_pov->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(310, 250, 61, 61));
        pushButton_sqrt->setFont(font2);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(310, 320, 61, 61));
        pushButton_mod->setFont(font2);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        data_x = new QLabel(centralwidget);
        data_x->setObjectName(QString::fromUtf8("data_x"));
        data_x->setEnabled(true);
        data_x->setGeometry(QRect(1000, 360, 71, 61));
        data_x->setFont(font);
        data_x->setStyleSheet(QString::fromUtf8("QLabel {\n"
"qproperty-alignment: 'AlignRight';\n"
"background-color: white;\n"
"border: 1px solid grey;\n"
"border-radius: 8px;\n"
"  margin: 0px;\n"
"  font-size: 23px;\n"
"}\n"
"\n"
"background-color: white;"));
        data_x->setScaledContents(false);
        data_x->setAlignment(Qt::AlignCenter);
        err_c = new QLabel(centralwidget);
        err_c->setObjectName(QString::fromUtf8("err_c"));
        err_c->setEnabled(true);
        err_c->setGeometry(QRect(35, 38, 49, 49));
        err_c->setFont(font);
        err_c->setStyleSheet(QString::fromUtf8("QLabel {\n"
"qproperty-alignment: 'AlignRight';\n"
"color: red;\n"
"\n"
"border-radius: 8px;\n"
"  margin: 0px;\n"
"  font-size: 23px;\n"
"}\n"
"\n"
"background-color: white;"));
        err_c->setAlignment(Qt::AlignCenter);
        err_x = new QLabel(centralwidget);
        err_x->setObjectName(QString::fromUtf8("err_x"));
        err_x->setEnabled(true);
        err_x->setGeometry(QRect(35, 38, 49, 49));
        err_x->setFont(font);
        err_x->setStyleSheet(QString::fromUtf8("QLabel {\n"
"qproperty-alignment: 'AlignRight';\n"
"color: green;\n"
"\n"
"\n"
"border-radius: 8px;\n"
"  margin: 0px;\n"
"  font-size: 23px;\n"
"}\n"
"\n"
"background-color: white;"));
        err_x->setAlignment(Qt::AlignCenter);
        doubleSpinBox_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        doubleSpinBox_x->setGeometry(QRect(500, 330, 71, 41));
        QFont font4;
        font4.setPointSize(18);
        font4.setKerning(true);
        doubleSpinBox_x->setFont(font4);
        doubleSpinBox_x->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        doubleSpinBox_x->setAlignment(Qt::AlignCenter);
        doubleSpinBox_x->setDecimals(2);
        doubleSpinBox_x->setMinimum(-1000000.000000000000000);
        doubleSpinBox_x->setMaximum(10000000.000000000000000);
        doubleSpinBox_x->setValue(1.000000000000000);
        pushButton_graph = new QPushButton(centralwidget);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(30, 390, 271, 61));
        pushButton_graph->setFont(font2);
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #F8F8FF;\n"
"border: 1px solid gray;\n"
"border-radius: 8px; \n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #FFFAFA);\n"
"}"));
        result_show_2 = new QLabel(centralwidget);
        result_show_2->setObjectName(QString::fromUtf8("result_show_2"));
        result_show_2->setEnabled(true);
        result_show_2->setGeometry(QRect(450, 320, 131, 61));
        QFont font5;
        font5.setPointSize(18);
        font5.setItalic(false);
        result_show_2->setFont(font5);
        result_show_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
""));
        result_show_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_credit = new QPushButton(centralwidget);
        pushButton_credit->setObjectName(QString::fromUtf8("pushButton_credit"));
        pushButton_credit->setGeometry(QRect(30, 460, 551, 51));
        pushButton_credit->setFont(font2);
        pushButton_credit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF0F5;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_E = new QPushButton(centralwidget);
        pushButton_E->setObjectName(QString::fromUtf8("pushButton_E"));
        pushButton_E->setGeometry(QRect(380, 320, 61, 61));
        pushButton_E->setFont(font2);
        pushButton_E->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #FFF5EE;\n"
"border: 1px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"								stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        result_show->raise();
        result_show_2->raise();
        pushButton_clear->raise();
        pushButton_bin->raise();
        pushButton_div->raise();
        pushButton_proc->raise();
        pushButton_9->raise();
        pushButton_8->raise();
        pushButton_7->raise();
        pushButton_mult->raise();
        pushButton_5->raise();
        pushButton_minus->raise();
        pushButton_dot->raise();
        pushButton_eq->raise();
        pushButton_0->raise();
        pushButton_6->raise();
        pushButton_4->raise();
        pushButton_3->raise();
        pushButton_plus->raise();
        pushButton_2->raise();
        pushButton_1->raise();
        pushButton_x->raise();
        pushButton_del->raise();
        pushButton_lb->raise();
        pushButton_log->raise();
        pushButton_rb->raise();
        pushButton_ln->raise();
        pushButton_atag->raise();
        pushButton_acos->raise();
        pushButton_asin->raise();
        pushButton_sin->raise();
        pushButton_cos->raise();
        pushButton_tan->raise();
        pushButton_pov->raise();
        pushButton_sqrt->raise();
        pushButton_mod->raise();
        data_x->raise();
        err_c->raise();
        doubleSpinBox_x->raise();
        pushButton_graph->raise();
        err_x->raise();
        pushButton_credit->raise();
        pushButton_E->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_bin->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_proc->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "<--", nullptr));
        pushButton_lb->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_rb->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_atag->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_pov->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        data_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        err_c->setText(QString());
        err_x->setText(QString());
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        result_show_2->setText(QString());
        pushButton_credit->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pushButton_E->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
