/**
 * @file      s21_calc.c
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
#include <stack> // удалить

using namespace s21;
// #include <string>
// #include <cstring>



/**
 * @brief          Основная функция калькулятора
 *
 * @param str      - Строка с арифметическим выражением
 * @param str_x    - Принимает значение X
 * @param result   - Возвращает итоговый результат арифмитического выражения
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

// Сделать обработку пробела
// if (str.empty()) {
//     return INFINITY;
//   }


int Model::SmartCalc(std::string str, std::string str_x, double &result) {
  // Stack_t stack[STACK_MAX_SIZE] = {0};
  // Stack_t polish[STACK_MAX_SIZE] = {0};
  std::list<Stack_t2_> stac2;
  std::list<Stack_t2_> polis2;
  // stack->size = 0;
  int err = -1;
  result = 999.0;
  std::cout << str_x << std::endl;
    if (!str.empty() && !str_x.empty() && result != 0) { 
      // stack->g = str_x;
      err = Parser(str, stac2, str_x);
      Printstack(stac2);
      if (err == TRUE) {
        err = PolishNotation(stac2, polis2);
        std::cout << "CTECK POLISH   " <<  std::endl;
        Printstack(polis2);
        std::cout << "PO___________ " << err << std::endl;
        std::cout << std::endl;
        if (err == TRUE) {
          err = Mathematics(polis2, result);
        }
        printf("%f\n", result);
      }
    } else {
        err = -1; 
    }
  return err;
}

// // /**
// //  * @brief          Парсим строчку арифмитеческого выражения
// //  *
// //  * @param str      - Строка с арифметическим выражением
// //  * @param stack    - Принимает значение X
// //  * @return         - Вернет 0, если число поданно корректно и 1, если есть
// //  * ошибки
// //  */

  int Model::Parser(std::string str, std::list<Stack_t2_> &stac2, std::string str_x) {
  int err = TRUE;
  std::string val = {0};
  int tmp = -1;
  // char data_before[SIZE] = {0};
  // char data_after[SIZE] = {0};
  // std::string data_befor2 = {0};
  // std::string data_afte2 = {0};
  // int symbol_after = 0;
  // int symbol_before = 0;
  int brackets = 0;
  // int err_2 = 0;
  RemovesSpaces(str);

  int len = str.length();
  for (int symbol = 0; symbol < len && err == TRUE; symbol++) {
    err = -1;  
    
    tmp = Types(str, symbol, val);
    std::cout << "Порядковый символ_  " << symbol << " Значение_" << val << std::endl;
    if (val == "x") {
      val = str_x;    
      tmp = 9;
      err = TRUE;
    }
    std::cout<< "Test 2 _" << tmp <<   std::endl;
    if (tmp != -1 && brackets >= 0) {
      err = CheckParser(str, str_x, tmp, symbol, val, brackets); // bascet ссылкой
      Stack_t2_ current;
      
      if (err == TRUE) {
        // push(stack, val, tmp);
        // if (tmp != 0 ) {);}
        // if (tmp == 9){
        //  Number(val, current.numbe2); // возможно сделать конкретно для числа, когда пушу.
        // }
        if (tmp == 6){
          std::list<Stack_t2_>::iterator it = --stac2.end();
          val = it->dat2 + val;
          std::cout << " 66666 _ value2_   " << val  << std::endl;
          stac2.pop_back();
        }
        current.dat2 = val;
        current.type = tmp;
        stac2.push_back(current);
        //  std::cout << val <<  "  !!!!!!!!!!___ current.numbe2 " << current.numbe2 << std::endl;
        //   std::cout  << err <<  "  !!!!!!!!!!___ current.numbe2 "  << std::endl;
      }
    } else 
      err = -1;
      // std::cout << "___ bascets " << err << std::endl;      
  }
  if (/*types(str, &symbol, &val) == -1 || */brackets != 0) err = -1; // возможно оставить только скобки
  return err;
}

// /**
//  * @brief          Создаем польскую анотацию из арифмитического выражения
//  *
//  * @param stack    - Стек из операторов и операндов в арифмитической
//  * последовательности
//  * @param polish   - Стек из операторов и операндов в польской натации
//  * @return         - Вернет 0, если число поданно корректно и 1, если есть
//  * ошибки
//  */

  int Model::PolishNotation(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &polis2) {
    printf("\nPOLISH \n");
    int err = TRUE;
    std::list<Stack_t2_> znak;
    // int len = stac2.size();
    // char doub[SIZE];  // Временная переменная для стека знак
    // std::string dou2 = {0};
    std::list<Stack_t2_>::iterator it;
    int count = 0;
    Printstack(znak);
    for (it = stac2.begin(); it != stac2.end(); /*count*/it++) { // возможно end - 1
    std::cout << "pri _  " << it->dat2  << " Type_ " << it->type<< std::endl;
    if (it->type == 9 || it->type == 6) {
      printf("number ---- \n");
      polis2.push_back(*it);
    } else if (it->dat2 == "(" || it->type == 4) {
      znak.push_back(*it);
    } else if (it->dat2 == ")") {
      std::list<Stack_t2_>::iterator it_z1 = --znak.end();
      // std::cout << "Нашли ) " << it->dat2  << std::endl;      
      for (; it_z1->dat2 != "(" && it_z1->type != 4 && err == TRUE && --it_z1 != znak.begin(); ) {
        // std::cout << "Пред цикл  " << it_z1->dat2  << std::endl;
        // it_z1 = --znak.end();  // возможно не надо
        // Printstack(znak);
        // std::cout << "for__________it_z1->dat2  " << it_z1->dat2  << std::endl;
        PopPush(znak, polis2, it_z1);
        // if (len == 0) {err = -1;} //  удалила, возможно надо
        // std::cout << "После цикл_  " << it_z1->dat2  << std::endl;
        // ++it_z1;
        it_z1 = --znak.end(); 
      }
      // Printstack(polis2);
      it_z1 = --znak.end();// Почему-то в поп не переходит на позицию назад, поэтому делаем так
      // std::cout << "После цикл 2 " << it_z1->dat2  << std::endl;
      if (it_z1->dat2 == "(" || it_z1->type == 4) {
        // std::cout << "for__у  " << it_z1->dat2  << std::endl;
        // pop(znak);
          // std::cout << "CTECK_ZNAK __ (( " <<  std::endl;
            Printstack(znak);
          // std::cout << std::endl; 
          std::cout << "IIIIII " <<  std::endl;
          polis2.push_back(*it_z1);
          znak.pop_back();
        // }
      }
    } else if (it->type) {
      std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!for__у22 " << it->dat2  << std::endl;
      CheckPolish(znak, polis2, stac2, count);
    }
    std::cout << "IIIIII_22 " <<  std::endl;
    if (it == --stac2.end()) {
      Printstack(znak);
      std::cout << "UUUU2 " << std::endl;      
      int len_znak = znak.size();
      // std::cout << "eee " <<  len_znak << std::endl;
      // std::list<Stack_t2_>::iterator it_z = --znak.end();
        for ( ; len_znak > 0; len_znak--) {
        // it_z--;
        std::list<Stack_t2_>::iterator it_z = --znak.end();
        
          
          PopPush(znak, polis2, it_z);
          err = TRUE;   
          std::cout << "eee 55_ " <<  len_znak << std::endl;
          // std::cout << "eee " <<  len_znak <<  " Значение Знак " << --(it_z->dat2)  << std::endl;
                 
        }
      std::cout << "555_IIIIII " <<  std::endl;
    }
    count++;
  }
  return err;
}

// /**
//  * @brief          Создаем польскую анотацию из арифмитического выражения
//  *
//  * @param polish   - Стек из операторов и операндов в польской натации
//  * @param result   - Возвращает итоговый результат арифмитического выражения
//  * @return         - Вернет 0, если число поданно корректно и 1, если есть
//  * ошибки
//  */

int Model::Mathematics(std::list<Stack_t2_> &polis2, double &result) {
  printf("Matematika\n");
  int err = TRUE;
  result = -0;
  double numbe2 = -0;
  std::stack<double> nu2;
  // Stack_t  num = {0};
  std::list<Stack_t2_>::iterator it = polis2.begin();
    for (; it != polis2.end() && err == TRUE; it++) {
      std::cout << "__ " << it->dat2 << " Type_  " << it->type << std::endl;
      std::cout << std::endl;
    if (it->dat2 == "u" || it->dat2 == "p") { //можно вывести унарную функцию
      printf(" Unar \n");
      if (it->dat2 == "u") {
        nu2.top() *= (-1);
      }
        std::cout << "Промежуточнв=ый рез-т_un " << nu2.top() << std::endl;
    } else if (it->type == 9 || it->type == 6) {
        std::cout << "Нашли число " << it->dat2 << std::endl;
        std::cout << "Нашли число ex " << numbe2 << std::endl;
        if (it->type == 6) {numbe2 = -1;}
        Number(it->dat2, numbe2);
        nu2.push(numbe2);
        // std::cout << "Нашли число " << it->dat2 << " Размер стека nu2 " << nu2.size() << std::endl;
    } else if (it->type == 4) {
        // std::cout << "Нашли func " << it->dat2 << " Размер стека nu2 " << nu2.size() << std::endl;
        err = MathFunction(it, nu2, result);
    } else if (it->type == 1 || it->type == 2 || it->type == 5) {
        err = MathSimple(it, nu2, result);
        // std::cout << "Промежуточнв=ый рез-т_5 " << res << std::endl;    
    }
    // std::cout << "Промежуточнв=ый рез-т_res " << res << std::endl;
   
  }
  if (err == TRUE){
    // std::cout << "UUUUUU " << std::endl;
    result = nu2.top();
    // result = res;
  }
  printf("%f\n", result);
  return err;
}

