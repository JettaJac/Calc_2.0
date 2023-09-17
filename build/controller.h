#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// #include "../model/credit_calc.h"
// #include "../model/smart_calc.h"

// #include
#include "s21_calc.h"

namespace s21 {

class Controller {
 public:
  int SmartCalc(std::string const str, std::string const str_x, double &result);

  //   static ResultCreditData
  //   credit_calculate(const struct InputCreditData &input_values);
};
}  // namespace s21

#endif  // CONTROLLER_H_