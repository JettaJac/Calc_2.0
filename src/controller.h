#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// #include "../model/credit_calc.h"
// #include "../model/smart_calc.h"
#pragma once

#include "s21_calc.h"
#include "credit.h"
// #include "controller.cc"

#include <iostream>
#include <string>  // врееменно

using namespace std;

namespace s21 {

class Model;
//
class Controller {
 public:
  int SmartCalc(std::string const str, std::string const str_x, double &result);
  int calc_credit(credit_t *data);

//  private:
  s21::Model model_;

  typedef struct credit { // возможно не надо
  
  int type;  // Payment type Annuity or Differentiated
  int total_credit;
  double period;    // Loan period
  char period_uom;  // Period: months or years
  double month_min;
  double month_max;
  double percent_rate;
  double overpayment;  // Loan repayment (interest)
  double total_overpayment;
} credit_t;
};
}  // namespace s21

#endif  // CONTROLLER_H_