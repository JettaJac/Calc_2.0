/**
 * @file      s21_calc.cc
 * @author    jettajac
 * @brief
 * @version   0.1
 * @date      2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_calc.h"

// #include "credit.c"
#include "helpers_functions.cc"

using namespace s21;


/**
 * @brief          Основная функция калькулятора
 *
 * @param str      - Строка с арифметическим выражением
 * @param str_x    - Принимает значение X
 * @param result   - Возвращает итоговый результат арифмитического выражения
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */


int Model::SmartCalc(std::string str, std::string str_x, double &result) {
  std::list<Stack_t2_> stack;
  std::list<Stack_t2_> polish;
  int err = -1;
  result = 999.0;
    if (!str.empty() && !str_x.empty() && result != 0) { 
      err = Parser(str, stack, str_x);
      if (err == TRUE) {
        err = PolishNotation(stack, polish);
        if (err == TRUE) {
          err = Mathematics(polish, result);
        }
      }
    } else {
        err = -1; 
    }
  return err;
}

/**
 * @brief          Парсим строчку арифмитеческого выражения
 *
 * @param str      - Строка с арифметическим выражением
 * @param stack    - Лист с используемой структурой данных
 * @param str_x    - Принимает значение X
 * @return         - Вернет 0, если арифмитическоевыражение поданно корректно и 1, если есть
 * ошибки
 */

  int Model::Parser(std::string str, std::list<Stack_t2_> &stack, std::string str_x) {
  int err = TRUE;
  std::string val = {0};
  int tmp = -1;
  int brackets = 0;

  RemovesSpaces(str); // Чистим от пробелов

  int len = str.length();
  for (int symbol = 0; symbol < len && err == TRUE; symbol++) {
    err = -1;  
        tmp = Types(str, symbol, val);
    if (val == "x") {
      val = str_x;    
      tmp = 9;
      err = TRUE;
    }
    if (tmp != -1 && brackets >= 0) {
      err = CheckParser(str, str_x, tmp, symbol, val, brackets); // bascet ссылкой
      Stack_t2_ current;      
      if (err == TRUE) {
        if (tmp == 6){
          std::list<Stack_t2_>::iterator it = --stack.end();
          val = it->dat2 + val;
          stack.pop_back();
        }
        current.dat2 = val;
        current.type = tmp;
        stack.push_back(current);
      }
    } else 
      err = -1;  
  }
  if (brackets != 0) err = -1; 
  return err;
}

/**
 * @brief          Создаем польскую анотацию из арифмитического выражения
 *
 * @param stack    - Стек из операторов и операндов в арифмитической
 * последовательности
 * @param polish   - Стек из операторов и операндов в польской натации
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

  int Model::PolishNotation(std::list<Stack_t2_> &stack, std::list<Stack_t2_> &polish) {
    // cout  << "\nPOLISH \n";
    int err = TRUE;
    std::list<Stack_t2_> znak;
    std::list<Stack_t2_>::iterator it;
    int symbol = 0;
    for (it = stack.begin(); it != stack.end(); it++) { // возможно end - 1
    if (it->type == 9 || it->type == 6) {
      polish.push_back(*it);
    } else if (it->dat2 == "(" || it->type == 4) {
      znak.push_back(*it);
    } else if (it->dat2 == ")") {
      std::list<Stack_t2_>::iterator it_z1 = --znak.end();
      for (; it_z1->dat2 != "(" && it_z1->type != 4 && err == TRUE && --it_z1 != znak.begin(); ) {
        PopPush(znak, polish, it_z1);
        it_z1 = --znak.end(); 
      }
      it_z1 = --znak.end();
      if (it_z1->dat2 == "(" || it_z1->type == 4) {
          polish.push_back(*it_z1);
          znak.pop_back();
      }
    } else if (it->type) {
      CheckPolish(znak, polish, stack, symbol);
    }
    if (it == --stack.end()) {
      int len_znak = znak.size();
      std::list<Stack_t2_>::iterator it_z;
        for ( ; len_znak > 0; len_znak--) {
        it_z = --znak.end();        
          PopPush(znak, polish, it_z);
          err = TRUE;                 
        }
    }
    symbol++;
  }
  return err;
}

/**
 * @brief          Считаем арифмитическое выражения
 *
 * @param polish   - Стек из операторов и операндов в польской натации
 * @param result   - Возвращает итоговый результат арифмитического выражения
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

int Model::Mathematics(std::list<Stack_t2_> &polish, double &result) {
  // cout  << "Matematika\n";
  int err = TRUE;
  result = -0;
  double numbe2 = -0;
  std::stack<double> nu2;
  std::list<Stack_t2_>::iterator it = polish.begin();
    for (; it != polish.end() && err == TRUE; it++) {
    if (it->dat2 == "u" || it->dat2 == "p") { 
      if (it->dat2 == "u") {
        nu2.top() *= (-1);
      }
    } else if (it->type == 9 || it->type == 6) {
        if (it->type == 6) {numbe2 = -1;}
        Number(it->dat2, numbe2);
        nu2.push(numbe2);
    } else if (it->type == 4) {
        err = MathFunction(it, nu2, result);
    } else if (it->type == 1 || it->type == 2 || it->type == 5) {
        err = MathSimple(it, nu2, result);        
    }
  }
  if (err == TRUE){
        result = nu2.top();
  }
  return err;
}

