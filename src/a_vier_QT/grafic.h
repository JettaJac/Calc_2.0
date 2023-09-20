#ifndef GRAFIC_H
#define GRAFIC_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <iostream>
#include <string>

#include "../a_controller/controller.h"

namespace Ui {
class Grafic;
}

class Grafic : public QMainWindow {
  Q_OBJECT

 public:
  explicit Grafic(QWidget *parent, QString str_out);
  ~Grafic();
  QString str;

 private:
  Ui::Grafic *ui;
  s21::Controller *controller_;


  double xBegin, xEnd, h, X;
  double yBegin, yEnd, Y;
  int err3 = 0;
  int N = 0;

  QVector<double> x, y;
  QTimer *timer;
  int time;
  void ChangeFunc();
  void StaticFunc();

 private slots:
  void TimerSlot();
  void on_pushButton_gr_clicked();
};

#endif  // GRAFIC_H
