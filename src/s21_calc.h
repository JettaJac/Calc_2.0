
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

#ifndef SRC_S21_calc_H
#define SRC_S21_calc_H

// 9: number
// 1: + and -
// 2: * and /
// 3: ()
// 4: sin, cos, tg, ctg, log, square root,
// 5:  x, ^. mod
// 6:  unar

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Libraries and files used
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
// #include <ostream>

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

// #define size_t
// #define STACK_OVERFLOW 10
#define STACK_MAX_SIZE 100
#define INIT_SIZE 10

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102
// typedef double T;

#define SIZE 300
#define SIZE_N 100

using namespace std;

/**
 * @brief           Структура стека для записи чисел и операторов
 *
 * @param data       - Cтэк чисел в строковом эквиваленте
 * @param number     - Cтэк чисел в числовом эквиваленте
 * @param pri  - Приоритет стека
 * @param x          - Значение Х
 *@param size       - Количество элементов в стеке
 */

typedef struct stack_tag {
  char data[STACK_MAX_SIZE][SIZE];
  std::vector<std::string> datea; // не надо вектор, так как будет реализовано через лист структур
  std::string curr = {0};
  int type = 0;
  double number[STACK_MAX_SIZE];
  int pri[STACK_MAX_SIZE];  // prioritet
  char x[SIZE];
  std::string g; //x
  size_t size;
  // double *x;
  // size_t top;
} Stack_t;

 struct Stack_t2 {
  char data[STACK_MAX_SIZE][SIZE];
  std::vector<std::string> datea; // не надо вектор, так как будет реализовано через лист структур
  // std::string data_befor2 = {0};
  std::string dat2;
  int type = 0;
  double number[STACK_MAX_SIZE];
  int pri[STACK_MAX_SIZE];  // prioritet
  char x[SIZE];
  std::string g; //x
  size_t size;
  // double *x;
  // size_t top;
};

typedef struct {
  char str[SIZE];
  char val[SIZE];
  int tmp;
  char data_before[SIZE];
  char data_after[SIZE];
  int symbol_after;
  int symbol_before;
  int symbol;
  int brackets;
} flags;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Stack functions
void push(Stack_t *stack, std::string value, int prioritet);
void push_num(Stack_t *stack, double *value, int prioritet);
void pop(Stack_t *stack);
void pop_push(Stack_t *stack, Stack_t *stack2, char *val, int tmp);
void printvalue_stack(char *value);
void printstack(Stack_t *stack);
void printstack(std::list<Stack_t2> &stac2);

int prev_next_ch(int flag, std::string str, int symbol, std::string *value);
// int prev_next_ch(int flag, char *str, int symbol, char *value);
int number(std::string str, double *number);
// int number(char *str, double *number);

int s21_calc(std::string str /*char *str*/, std::string str_g, double *result);
// int s21_calc(/*std::string */ char *str, char *str_x, double *result);
// int s21_calc_o(std::string str);

// int parser(/*char *str*/, Stack_t *stack);
int parser(std::string str, std::list<Stack_t2> &stac2);
int polish_notation(list<Stack_t2> &stac2, list<Stack_t2> &polis2);
// int polish_notation(Stack_t *stack, Stack_t *polish);
int matematika(Stack_t *polish, double *result);
void matemat_res(Stack_t *number, double *res, int tmp);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Check functions
int check_number(std::string str);
// int check_number(char *str);
int check_funcs(std::string str, int *count);
// int check_funcs(char *str, int *count);
int check_parser(string str, int type, int symbol, string value, int *brackets);
int check_polish(Stack_t *znak, Stack_t *polish, Stack_t *stack, int count);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//// Parsing
int types(std::string str, int *lent, std::string *value);
// int types(char *str, int *lent, char *value);
int pars_baskets(char *val, int tmp, int symbol);
int unar_znak(std::string val, int *tmp);

// int parser_conditions(int *symbol, flags *fl);
// int parser_check (flags *fl);
// bool operator!=(const string &other){return (*this) != other;}/*const
// noexcept*/; // {return compare(other) != 0;}

#endif  // SRC_S21_calc_H
