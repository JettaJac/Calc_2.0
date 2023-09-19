#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#pragma once  // контролирует один вход в систему, подключение

#include "../a_model/credit.h"
#include "../a_model/s21_calc.h"

// #include <iostream>
// #include <string>

namespace s21 {

class Controller {
 public:
  int SmartCalc(std::string const str, std::string const str_x, double &result);
  int CalcCreditC(s21::CreditM::Credit_t &data);

 private:
  Model model_smart_;
  CreditM model_credit_;
};
}  // namespace s21

#endif  // CONTROLLER_H_