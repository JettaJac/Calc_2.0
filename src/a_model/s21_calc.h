/// \file

/**
 * @file s21_calc.h
 * @author jettajac
 * @brief
 * @version 0.1
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef S21_CALC_H
#define S21_CALC_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Libraries
#pragma once  // контролирует один вход в систему, подключение
#include <errno.h>
#include <math.h>

#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <string>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//// Error code
// #define TRUE 0
// #define FAIL -1
// #define ZERO -2
// #define EFUC -3  // неправильно введены значения в функциях
// #define ERC 0.00000001

// using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Prioritet
// 9: number
// 1: + and -
// 2: * and /
// 3: ()
// 4: sin, cos, tg, ctg, log, square root,
// 5:  x, ^, mod
// 6:  unar, e

namespace s21 {

class Model {
 public:
  int SmartCalc(std::string const str, std::string const str_g, double &result);
  // using int TRU  TRUE;
  enum {
    TRUE = 0,
    FAIL = -1,
    ZERO = -2,
    EFUC = -3,
    //  ERC = 0.00000001
  };

  //  private:
  // protected:
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

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  ////Main functions
  int Parser(std::string str, std::list<Stack_t2_> &stac2, std::string const x);
  int PolishNotation(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &polis2);
  int Mathematics(std::list<Stack_t2_> &polis2, double &result);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Parsing
  int RemovesSpaces(std::string &str) noexcept;
  int Types(std::string const str, int &lent, std::string &value) noexcept;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Check functions
  int CheckParser(std::string const str, std::string x, int type, int &symbol,
                  std::string &value, int &brackets) noexcept;
  int CheckNumber(std::string const str) const noexcept;
  int CheckFuncs(std::string const str, int &count) noexcept;
  int CheckPolish(std::list<Stack_t2_> &znak, std::list<Stack_t2_> &polish,
                  std::list<Stack_t2_>::iterator it);
  int CheckExp(std::string const str, std::string x, int &symbol,
               std::string &value) noexcept;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Arithmetic
  int MathSimple(std::list<Stack_t2_>::iterator &it, std::stack<double> &number,
                 double &res);
  int MathFunction(std::list<Stack_t2_>::iterator &it,
                   std::stack<double> &st_num, double &res);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Secondary functions
  void PopPush(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &stac2_2,
               std::list<Stack_t2_>::iterator &it) noexcept;
  int Number(std::string const str, double &number);
  int UnarZnak(std::string &val) noexcept;
  void CharPrevAfter(std::string const str, int &symbol, std::string &prev,
                     std::string &after, int &p, int &a) noexcept;
  void Printstack(std::list<Stack_t2_> &stac2);

  // friend class MyTest;
};

}  // namespace s21
#endif  // MODEL_H
