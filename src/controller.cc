
#include "controller.h"
#include  "s21_calc.cc"
/**
 * @brief Методы данного файла передают и информацию из view в model 
 * 
 */

using namespace s21;
int Controller::SmartCalc(std::string const str, std::string const str_x, double &result){
    int err = -1;
    // double result;
    s21::Model s21_calc;
    err = s21_calc.SmartCalc_m(str, str_x, result);
    return err;
}




