/// \file
#include "controller.h"

#include <iostream>

/**
 * @brief Методы данного файла передают и информацию из view в model
 *
 */
using namespace std;

using namespace s21;
int s21::Controller::SmartCalc(std::string const str, std::string const str_x,
                               double &result) {
  int err = -1;
  err = model_smart_.SmartCalc(str, str_x, result);
  return err;
}

int s21::Controller::CalcCreditC(CreditM::Credit_t &data2) {
  int err = model_credit_.CalcCredit(data2);
  return err;
}
