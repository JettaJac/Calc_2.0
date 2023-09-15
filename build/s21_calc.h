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

// #include <cmath>
// #include <stdio.h>
// #include <stdlib.h>

#include <cstring>
// #include <ostream>
#include <iostream>
#include <string>
// #include <vector>
#include <list>
#include <stack>

// #include <credit.h>
// #include <unistd.h>
// #include <stdnoreturn.h>
// #include <stdbool.h>

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

// using namespace std;

namespace s21 {

class Model {
 public:
  // Model();
  int s21_calc(std::string str, std::string str_g, double &result);

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

  // typedef struct stack_tag {
  //   char data[STACK_MAX_SIZE][SIZE];
  //   std::vector<std::string> datea; // не надо вектор, так как будет
  //   реализовано через лист структур std::string curr = {0}; int type = 0;
  //   double number[STACK_MAX_SIZE];
  //   int pri[STACK_MAX_SIZE];  // prioritet
  //   char x[SIZE];
  //   std::string g; //x
  //   size_t size;
  //   // double *x;
  //   // size_t top;
  // } Stack_t;

  struct Stack_t2_ {
    std::string dat2;
    int type = 0;
  };

  // typedef struct {
  //   char str[SIZE];
  //   char val[SIZE];
  //   int tmp;
  //   char data_before[SIZE];
  //   char data_after[SIZE];
  //   int symbol_after;
  //   int symbol_before;
  //   int symbol;
  //   int brackets;
  // } flags;
  // protected:
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Stack functions
  // void push(Stack_t *stack, std::string value, int prioritet);
  // void push_num(Stack_t *stack, double *value, int prioritet);
  // void pop(Stack_t *stack);
  // void pop_push(Stack_t *stack, Stack_t *stack2, char *val, int tmp);
  void pop_push(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &stac2_2,
                std::list<Stack_t2_>::iterator &it);
  // void printvalue_stack(char *value);
  // void printstack(Stack_t *stack);
  void printstack(std::list<Stack_t2_> &stac2);

  int prev_next_ch(std::string str, int symbol, std::string &value);
  int number(std::string str, double &number);

  int Parser(std::string str, std::list<Stack_t2_> &stac2, std::string x);
  int polish_notation(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &polis2);
  int mathematics(std::list<Stack_t2_> &polis2, double &result);

  int math_simple(std::list<Stack_t2_>::iterator &it, std::stack<double> &number,
                  double &res);
  int math_function(std::list<Stack_t2_>::iterator &it,
                    std::stack<double> &st_num, double &res);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Check functions
  int check_number(std::string str);
  int check_funcs(std::string str, int &count);
  int CheckParser(std::string str, std::string x,  int type, int &symbol, std::string &value,
                   int &brackets);
  int check_polish(std::list<Stack_t2_> &znak, std::list<Stack_t2_> &polish,
                   std::list<Stack_t2_> &stack, int vr);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //// Parsing
  int types(std::string str, int &lent, std::string &value);
  int unar_znak(std::string &val);

  int RemovesSpaces(std::string &str);

  // friend class MyTest;
};
// class MyTest;

}  // namespace s21
#endif  // MODEL_H
