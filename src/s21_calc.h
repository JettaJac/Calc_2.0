/**
 * @file s21__calc.h
 * @author jettajac
 * @brief
 * @version 0.1
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MODEL_H
#define MODEL_H

// 9: number
// 1: + and -
// 2: * and /
// 3: ()
// 4: sin, cos, tg, ctg, log, square root,
// 5:  x, ^, mod
// 6:  unar, e

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Libraries and files used
#include <errno.h>
#include <math.h>
#include <cstring>
#include <iostream>
#include <string>
#include <list>
#include <stack>
// #include <algorithm>


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Error code
#define TRUE 0
// #define FAIL -1
#define ZERO -2
#define EFUC -3  // неправильно введены значения в функциях

#define ERC 0.00000001

// #define size_t
// #define STACK_OVERFLOW 10
// #define STACK_MAX_SIZE 100
// #define INIT_SIZE 10

// #define STACK_OVERFLOW -100
// #define STACK_UNDERFLOW -101
// #define OUT_OF_MEMORY -102
// typedef double T;

// #define SIZE 300
// #define SIZE_N 100

using namespace std;

namespace s21 {

class Model {
 public:
  int SmartCalc(std::string str, std::string str_g, double &result);

  // private:

  /**
   * @brief           Структура стека для записи чисел и операторов
   *
   * @param data       - Cтэк чисел в строковом эквиваленте
   * @param number     - Cтэк чисел в числовом эквиваленте
   * @param pri  - Приоритет стека
   * @param x          - Значение Х
   *@param size       - Количество элементов в стеке
   */

  struct Stack_t2_ {
    std::string dat2;
    int type = 0;
  };

  // private:  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  ////Main functions
  int Parser(std::string str, std::list<Stack_t2_> &stac2, std::string x);
  int PolishNotation(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &polis2);
  int Mathematics(std::list<Stack_t2_> &polis2, double &result);
  

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Parsing
  int RemovesSpaces(std::string &str);
  int Types(std::string str, int &lent, std::string &value);


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Arithmetic
  int MathSimple(std::list<Stack_t2_>::iterator &it, std::stack<double> &number,
                  double &res);
  int MathFunction(std::list<Stack_t2_>::iterator &it,
                    std::stack<double> &st_num, double &res);


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Check functions
  int CheckParser(std::string str, std::string x,  int type, int &symbol, std::string &value,
                   int &brackets);
  int CheckNumber(std::string str);
  int CheckFuncs(std::string str, int &count);
  int CheckPolish(std::list<Stack_t2_> &znak, std::list<Stack_t2_> &polish,
                   std::list<Stack_t2_> &stack, int vr);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Secondary functions
  void PopPush(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &stac2_2,
                std::list<Stack_t2_>::iterator &it);
  int Number(std::string str, double &number);
  int UnarZnak(std::string &val);
  void Printstack(std::list<Stack_t2_> &stac2);                 
  
  friend class MyTest;
};
}  // namespace s21
#endif  // MODEL_H
