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

using namespace std;
// #include <string>
// #include <cstring>
#include <stack>


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


int s21_calc(std::string str, std::string str_x, double &result) {
  Stack_t stack[STACK_MAX_SIZE] = {0};
  // Stack_t polish[STACK_MAX_SIZE] = {0};
  std::list<Stack_t2> stac2;
  std::list<Stack_t2> polis2;
  // stack->size = 0;
  int err = -1;
  result = 999.0;
  cout << str_x << endl;
    if (!str.empty() && !str_x.empty() && result != 0) { 
      // stack->g = str_x;
      err = parser(str, stac2, str_x);
      if (err == TRUE) {
        err = polish_notation(stac2, polis2);
        cout << "CTECK POLISH   " <<  endl;
        printstack(polis2);
        cout << "PO___________ " << err << endl;
        cout << endl;
        if (err == TRUE) {
          err = mathematics(polis2, result);
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

  int parser(std::string str, std::list<Stack_t2> &stac2, std::string str_x) {
  int err = TRUE;
  std::string val = {0};
  int tmp = -1;
  // char data_before[SIZE] = {0};
  // char data_after[SIZE] = {0};
  // std::string data_befor2 = {0};
  // std::string data_afte2 = {0};
  // int symbol_after = 0;
  // int symbol_before = 0;
  int symbol = 0;
  int brackets = 0;
  // int err_2 = 0;
  removes_spaces(str);

  int len = str.length();
  for (int symbol = 0; symbol < len && err == TRUE; symbol++) {
    err = -1;  
    tmp = types(str, symbol, val);
    
    if (val == "x") {
      val = str_x;
      tmp = 9;
      err = TRUE;
    }
    // cout<< "Test 2 _" << val << "stack_g_ " << stack->g <<endl;
    if (tmp != -1 && brackets >= 0) {
      err =  check_parser(str, tmp, symbol, val, brackets); // bascet ссылкой
      Stack_t2 current;
      current.dat2 = val;
      current.type = tmp;
      if (err == TRUE) {
        // push(stack, val, tmp);
        // if (tmp != 0 ) {);}
         number(val, current.numbe2); // возможно сделать конкретно для числа, когда пушу.
         stac2.push_back(current);
        //  cout << val <<  "  !!!!!!!!!!___ current.numbe2 " << current.numbe2 << endl;
        //   cout  << err <<  "  !!!!!!!!!!___ current.numbe2 "  << endl;
      }
    } else 
      err = -1;
      // cout << "___ bascets " << err << endl;      
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

  int polish_notation(list<Stack_t2> &stac2, list<Stack_t2> &polis2) {
    printf("\nPOLISH \n");
    int err = TRUE;
    std::list<Stack_t2> znak;
    // int len = stac2.size();
    char doub[SIZE];  // Временная переменная для стека знак
    // std::string dou2 = {0};
    std::list<Stack_t2>::iterator it;
    int count = 0;
    printstack(znak);
    for (it = stac2.begin(); it != stac2.end(); /*count*/it++) { // возможно end - 1
    cout << "pri _  " << it->dat2  << endl;
    if (it->type == 9) {
      // printf("number ---- \n");
      polis2.push_back(*it);
    } else if (it->dat2 == "(" || it->type == 4) {
      znak.push_back(*it);
    } else if (it->dat2 == ")") {
      std::list<Stack_t2>::iterator it_z1 = --znak.end();
      // cout << "Нашли ) " << it->dat2  << endl;      
      for (; it_z1->dat2 != "(" && it_z1->type != 4 && err == TRUE && --it_z1 != znak.begin(); ) {
        // cout << "Пред цикл  " << it_z1->dat2  << endl;
        // it_z1 = --znak.end();  // возможно не надо
        // printstack(znak);
        // cout << "for__________it_z1->dat2  " << it_z1->dat2  << endl;
        pop_push(znak, polis2, it_z1);
        // if (len == 0) {err = -1;} //  удалила, возможно надо
        // cout << "После цикл_  " << it_z1->dat2  << endl;
        // ++it_z1;
        it_z1 = --znak.end(); 
      }
      // printstack(polis2);
      it_z1 = --znak.end();// Почему-то в поп не переходит на позицию назад, поэтому делаем так
      // cout << "После цикл 2 " << it_z1->dat2  << endl;
      if (it_z1->dat2 == "(" || it_z1->type == 4) {
        // cout << "for__у  " << it_z1->dat2  << endl;
        // pop(znak);
          // cout << "CTECK_ZNAK __ (( " <<  endl;
            printstack(znak);
          // cout << endl; 
          // cout << "IIIIII " <<  endl;
          polis2.push_back(*it_z1);
          znak.pop_back();
        // }
      }
    } else if (it->type) {
      // cout << "for__у22 " << it->dat2  << endl;
      check_polish(znak, polis2, stac2, count);
    }
    if (it == --stac2.end()) {
      // cout << "UUUU2 " << endl;      
      int len_znak = znak.size();
      // cout << "eee " <<  len_znak << endl;
      std::list<Stack_t2>::iterator it_z = --znak.end();
        for ( ; len_znak != 0; len_znak--) {
        // cout << "eee " <<  len_znak << endl;
        pop_push(znak, polis2, it_z);
        err = TRUE;
        it_z--;
      }
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

int mathematics(list<Stack_t2> &polis2, double &result) {
  printf("Matematika\n");
  int err = TRUE;
  result = -0;
  // double re2 = -0;
  std::stack<double> nu2;
  Stack_t  num = {0};
  std::list<Stack_t2>::iterator it = polis2.begin();
    for (; it != polis2.end() && err == TRUE; it++) {
      cout << "__ " << it->dat2 << endl;
      cout << endl;
    if (it->dat2 == "u" || it->dat2 == "p") { //можно вывести унарную функцию
      printf(" Unar \n");
      if (it->dat2 == "u") {
        nu2.top() *= (-1);
      }
        cout << "Промежуточнв=ый рез-т_un " << nu2.top() << endl;
    } else if (it->type == 9) {
        // cout << "Нашли число " << it->dat2 << endl;
        nu2.push(it->numbe2);
        // cout << "Нашли число " << it->dat2 << " Размер стека nu2 " << nu2.size() << endl;
    } else if (it->type == 4) {
        // cout << "Нашли func " << it->dat2 << " Размер стека nu2 " << nu2.size() << endl;
        err = math_function(it, nu2, result);
    } else if (it->type == 1 || it->type == 2 || it->type == 5) {
        err = math_simple(it, nu2, result);
        // cout << "Промежуточнв=ый рез-т_5 " << res << endl;    
    }
    // cout << "Промежуточнв=ый рез-т_res " << res << endl;
   
  }
  if (err == TRUE){
    // cout << "UUUUUU " << endl;
    result = nu2.top();
    // result = res;
  }
  printf("%f\n", result);
  return err;
}

