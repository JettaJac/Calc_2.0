
#include "controller.h"
// #include "s21_calc.h"

#include <string> // врееменно
#include <iostream>
/**
 * @brief Методы данного файла передают и информацию из view в model 
 * 
 */
using namespace std;

using namespace s21;
int s21::Controller::SmartCalc(std::string const str, std::string const str_x, double &result){
    int err = -1;
    // double result2;
    s21::Model model2;
    err = model2.SmartCalc(str, str_x, result);
    std::cout << "All GOOD!! " << std::endl;
    return err;
}

// void s21::Controller::Test(std::string str) {
//     cout << str << endl;
// }
