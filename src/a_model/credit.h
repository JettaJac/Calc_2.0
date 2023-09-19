#ifndef MY_CREDIT_H
#define MY_CREDIT_H

#pragma once  // контролирует один вход в систему, подключение

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_calc.h"

namespace s21 {

class CreditM {
 public:
  /**
   * @brief                   Сруктура вводных данных и результатов для
   * кредитного калькулятора
   *
   * @param type              - Тип платежа Аунитетный или Дифференцированный
   * @param total_credit      - Общая сумма кредита
   * @param period            - Количестко периодов (месяцев или лет)
   * @param period_uom        - Какой период, в месяцах или в годах
   * @param month_min         - Минимальная сумма ежемесячного платежа
   * @param month_max         - Максимальная сумма ежемесячного платежа
   * @param percent_rate      - Процент в год
   *
   * @param overpayment       - Переплата (только проценты)
   * @param total_overpayment - Общая сумма выплат с учетом тела кредита
   */

  struct Credit_t {
    int type;  // Payment type Annuity or Differentiated
    int total_credit;
    double period;    // Loan period
    char period_uom;  // Period: months or years
    double month_min;
    double month_max;
    double percent_rate;
    double overpayment;  // Loan repayment (interest)
    double total_overpayment;
  };

  int CalcCredit(Credit_t &data);
};
}  // namespace s21

#endif  //  MY_CREDIT_H