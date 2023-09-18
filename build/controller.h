#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// #include "../model/credit_calc.h"
// #include "../model/smart_calc.h"
#pragma once

#include "s21_calc.h"
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
  // void Test(std::string str);
  //   credit_calculate(const struct InputCreditData &input_values);
 private:
  s21::Model model;
};
}  // namespace s21

#endif  // CONTROLLER_H_