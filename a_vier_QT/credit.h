#ifndef CREDIT_H
#define CREDIT_H

#include <QMainWindow>
#include <string>

#include "../a_controller/controller.h"

namespace Ui {
class Credit;
}

class Credit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:

  void on_pushButton_clicked();
  void on_checkBox_aunt_stateChanged(int arg1);
  void on_checkBox_diff_stateChanged(int arg1);
  void on_checkBox_month_stateChanged(int arg1);
  void on_checkBox_year_stateChanged(int arg1);

 private:
  Ui::Credit *ui;
  s21::Controller *controller_;
};

#endif  // CREDIT_H
