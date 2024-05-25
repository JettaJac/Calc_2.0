// #include "credit.h"
// #include "s21_calc.h"
// #include "controller.h"
// #include "controller.cc"
// #include "check_function.c"

#include <cstring>
#include <iostream>
#include <ostream>
#include <string>

#include "./a_controller/controller.h"

using namespace std;

int main() {
  s21::Controller model1;

  std::string str = "sin(x)";
  std::string str2 = "5e+4";
  std::string str_ch = "I";
  std::string str_g = "2";

  double res;

  int fun_res2 = model1.SmartCalc(str, str_g, res);
}