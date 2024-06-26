#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <credit.h>
#include <grafic.h>

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <string>

#include "../a_controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void keyPressEvent(QKeyEvent *e) override;

 private:
  Ui::MainWindow *ui;
  Grafic *grafic;
  Credit *credit;
  s21::Controller *controller_;

  double input_x;
  double num_first;
  int err = 0;
  void on_pushButton_clicked();

 private slots:
  void digits_functions();
  void digits_numbers();
  void digits_pov_mod();
  void on_pushButton_dot_clicked();
  void operations();
  void on_pushButton_eq_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_del_clicked();
  void on_doubleSpinBox_x_valueChanged(double arg1);
  void on_pushButton_plus_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_mult_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();

  void on_pushButton_E_clicked();

 signals:
  void signal();
};

#endif  // MAINWINDOW_H
