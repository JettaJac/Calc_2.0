/*!
 * @file      credit.cpp
 * @author    jettajac
 * @brief
 * @version   0.1
 * @date      2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "credit.h"

#include "ui_credit.h"
using namespace s21;

Credit::Credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

void Credit::on_pushButton_clicked() {
  int err = -1;

  s21::CreditM::Credit_t *credit_N = new CreditM::Credit_t;

  credit_N->total_credit = ui->spinBox_totalcredit->value();

  if (ui->checkBox_diff->isChecked()) {
    credit_N->type = 1;
    err = 0;
  } else if (ui->checkBox_aunt->isChecked()) {
    credit_N->type = 2;
    err = 0;
  } else {
    err = 1;
  }
  if (err == 0) {
    credit_N->period = ui->doubleSpinBox_period->value();

    if (ui->checkBox_year->isChecked()) {
      credit_N->period_uom = 'y';
      err = 0;
    } else if (ui->checkBox_month->isChecked()) {
      credit_N->period_uom = 'm';
      err = 0;
    } else {
      err = 1;
    }
  }
  credit_N->percent_rate = ui->doubleSpinBox_precent_rate->value();

  int err2 = controller_->CalcCreditC(*credit_N);

  if (err == 0 && err2 == 0) {
    std::cout << credit_N->month_min << std::endl;
    QString m_min =
        QString("%1").arg(QString::number(credit_N->month_min, 'f', 0));
    ui->month_min->setText(m_min);

    //    QString m_max =
    //    QString::fromStdString(std::to_string(credit_N->month_max));;
    QString m_max =
        QString("%1").arg(QString::number(credit_N->month_max, 'f', 0));
    ui->month_max->setText(m_max);

    //    QString tmp =
    //    QString::fromStdString(std::to_string(credit_N->overpayment));;
    QString over_m = QString("%1").arg(QString::number(
        credit_N->overpayment, 'f', 0));  // Выводим только целое число
    ui->overpayment->setText(over_m);

    //    QString t_over_m =
    //    QString::fromStdString(std::to_string(credit_N->total_overpayment));;
    QString t_over_m =
        QString("%1").arg(credit_N->total_overpayment, 0, 'f',
                          0);  // Выводим только целое число альтернатива
    ui->total_overpayment->setText(t_over_m);
  } else {
    ui->month_min->setText("0");
    ui->month_max->setText("0");
    ui->overpayment->setText("0");
    ui->total_overpayment->setText("0");
  }
}

void Credit::on_checkBox_aunt_stateChanged(int arg1) {
  ui->checkBox_diff->setChecked(false);
}

void Credit::on_checkBox_diff_stateChanged(int arg1) {
  ui->checkBox_aunt->setChecked(false);
}

void Credit::on_checkBox_month_stateChanged(int arg1) {
  ui->checkBox_year->setChecked(false);
}

void Credit::on_checkBox_year_stateChanged(int arg1) {
  ui->checkBox_month->setChecked(false);
}
