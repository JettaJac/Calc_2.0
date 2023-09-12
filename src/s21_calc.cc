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

int removes_spaces(std::string &str) { // пока не задействована
 
    // Удаление всех пробелов из строки
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            --i; 
        }
    }
    return 0;
} 

int s21_calc(std::string str, std::string str_x, double *result) {
  // int s21_calc(/*std::string */char * str, char *str_x, double *result) {
  Stack_t stack[STACK_MAX_SIZE] = {0};
  Stack_t polish[STACK_MAX_SIZE] = {0};
  std::list<Stack_t2> stac2;
  std::list<Stack_t2> polis2;
  stack->size = 0;
  int err = -1;
  *result = 999.0;
  cout << str_x << endl;
    if (!str.empty() && !str_x.empty() && result != 0) { // тут должно быть не не пустой, а выделна память
  // if (str != NULL && !str_x.empty() && result != 0) {
  //   // strcpy(stack->x, str_x);
      stack->g = str_x;
      // removes_spaces(str);
      err = parser(str, stac2, str_x);
      // printstack(stack);
      printstack(stac2);
      cout << "PR___________ " << err << endl;
      // cout << endl;
      if (err == TRUE) {
        err = polish_notation(stac2, polis2);
        cout << "CTECK POLISH   " <<  endl;
        printstack(polis2);
        cout << "PO___________ " << err << endl;
        cout << endl;
        if (err == TRUE) {
          err = matematika(polis2, result);
          // err = matematika(polish, result);
        }
        printf("%f\n", *result);
      }
      // err = 10001; // временно
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

// int parser(char *str, Stack_t *stack) {
  int parser(std::string str, std::list<Stack_t2> &stac2, std::string str_x) {
    // int parser(std::string str, Stack_t *stack) {
  // printf("JJJJ\n");
  // flags fl = {0};
  int err = TRUE;
  // char val[SIZE] = {0};
  std::string val = {0};
  int tmp = -1;
  char data_before[SIZE] = {0};
  char data_after[SIZE] = {0};
  std::string data_befor2 = {0};
  std::string data_afte2 = {0};
  int symbol_after = 0;
  int symbol_before = 0;
  int symbol = 0;
  int brackets = 0;
  int err_2 = 0;
  // int len = strlen(str);
  removes_spaces(str);
  int len = str.length();
  // cout<< "LEN " << len <<endl;
  for (int symbol = 0; symbol < len && err == TRUE; symbol++) {
    // cout << "Parser_begin " << symbol << " Длина  " << len << endl;
    err = -1;  
    
    
    // if(str[symbol] == ' ') {
    //   err = TRUE;
    //   str.erase(symbol, 1);
    //   len -= 1;
    //     // cout << "Parser_1 " << err << endl;
    //     // continue;
    //     // cout << "Parser_2 " << err << endl;   
    // }
    // if(str[symbol + 1] && str[symbol + 1] == ' ') {
    //   err = TRUE;
    //   str.erase(symbol + 1, 1);
    //   len -= 1;
    //     // cout << "Parser_1 " << err << endl;
    //     // continue;
    //     // cout << "Parser_2 " << err << endl;   
    // }

    
    tmp = types(str, &symbol, &val);
    // err =  check_parser(str, tmp, symbol, val);
    // cout << "Parser_val " << val << " TMP " << tmp << endl;
    // cout << "Parser_)) " << err << endl;

    // cout << "Types_ " << val << endl;
    // if (symbol != 0) {
    //   cout << "Test_val " << val <<endl;
    //   // symbol_before = prev_next_ch(-1, str, symbol, data_before);     
    //   symbol_before = prev_next_ch(-1, str, symbol - 1, &data_befor2); 
    // }
    // symbol_after = prev_next_ch(1, str, symbol, data_after);
    // symbol_after = prev_next_ch(1, str, symbol + 1, &data_afte2);
    // cout << "data_befor2_ " << data_befor2 << endl;
    // data_befor2 = "75";
    // cout << "data_befor2_ " << data_befor2 << endl;
    // cout << "data_after_ " << data_afte2 << endl;


    if (val == "x") {
      // strcpy(val, stack->x);
      // cout<< "Test _ X" << val <<endl;
      val = str_x;
      tmp = 9;
      err = TRUE;
      // cout<< "Test 3 _" << val << "stack_g_ " << stack->g <<endl;
    }
    // cout<< "Test 2 _" << val << "stack_g_ " << stack->g <<endl;
    if (tmp != -1 && brackets >= 0) {
      err =  check_parser(str, tmp, symbol, val, &brackets); // bascet ссылкой
      Stack_t2 current;
      current.dat2 = val;
      current.type = tmp;
      // std::list<Stack_t2>::iterator it;
      // it = stac2.begin(); // Начинаем с начала списка
      // std::advance(it, symbol - 1);
      // symbol_befor2 = it->type;
      // data_befor2 = it->dat2;

      // cout << "Parser_ " << err << endl;
      // // !!! сюда б закинуть чек парсинг, а скобки в уже в него проверку кинуть, тип не передавать совсем
      // int res = parser_conditions(&fl);//
  //     if (val == " ") { // не раюотает
  //       symbol++;
  //       cout<< "Out " << val <<endl;
  // // continue; // возможно не надо
  //     } else if (tmp == 9 && check_number(val) == 0) {
  //       cout<< "parser_N " << val <<endl;
  //       cout<< "parser_a " << symbol_after <<endl;
  //       if (data_afte2 == ")" || symbol_after == 1 || symbol_after == 2 ||
  //           data_afte2 == "^" || data_afte2 == "m" || symbol == (len - 1)) {
  //         err = TRUE;
  //          cout<< "parser_N_Good " << val <<endl;
  //       }
  //     } else if (symbol == len - 1) {
  //        cout<< "last_simlol" << val <<endl;
  //       if (val == ")" || (tmp == 9 && check_number(val) == 0) ||
  //           val == "x") {
  //             cout<< "last_simlol_good " << val <<endl;
  //         err = TRUE;
  //         if (val == ")") {
  //           brackets--;
  //         }
  //       }
  //     } else if (symbol == 0 &&
  //                (val == ")" || tmp == 2 || val == "m" || val == "^")) { 
  //                 cout << "Nothing" << endl; // ничего нен проиходит
  //     } else if ((symbol == 0 && tmp == 1 &&
  //                 (symbol_after == 4 || *data_after == '(' ||
  //                  *data_after == 'x' || symbol_after == 9)) ||
  //                (tmp == 1 && (*data_before == '(' || *data_before == '^') &&
  //                 (symbol_after == 9 || symbol_after == 4 ||
  //                  *data_after == '(' || *data_after == 'x'))) {
  //       err = TRUE;
  //       cout << "UnarZnak" << endl; 
  //       intunar_znak(val, &tmp);
  //     } else if (tmp == 1 || (tmp == 2 && symbol != 0)) {
  //       if (symbol_after != 1 && symbol_after != 2 && *data_after != ')') {
  //         err = TRUE;
  //         cout << "Znak +/-/*" << endl; 
  //       }
  //     } else if (val == ")") {
  //       cout << "Brackets )" << endl; 
  //       if (*data_after == '\0' || *data_after == '^' || *data_after == ')' ||
  //           *data_after == 'm' || symbol_after == 1 || symbol_after == 2) {
  //         brackets--;
  //         err = TRUE;
  //         cout << "Brackets ) Good" << endl; 
  //       }
  //     } else if ((tmp == 4 && val != "m") || val == "(") {
  //       brackets++;
  //       cout << "Brackets (" << endl; 
  //       err = TRUE;
  //       if (*data_after == ')' || *data_after == '^' || symbol_after == 2) {
  //         err = -1;
  //       }
  //     } else if (val == "m") {
  //       cout << "VAL m" << endl; 
  //       int symbol_tmp = symbol - 2;
  //       // symbol_before = prev_next_ch(-1, str, symbol_tmp, data_before);     // надо
  //       if (symbol_before == 9 || data_befor2 == ")" || data_befor2 == "x") {
  //         // symbol_after = prev_next_ch(1, str, symbol, data_after); // надо
  //         if (symbol_after == 9 || data_afte2 == "(" || data_afte2 == "x") {
  //           err = TRUE;
  //         }
  //       }
  //     } else if (tmp == 5) {
  //       err = TRUE;
  //       cout << "TMP = 5" << endl; 
  //     } else if (tmp < 6 && tmp > 0) {
  //       err = -1;
  //     }



      
      if (err == TRUE) {
        // push(stack, val, tmp);
        // if (tmp != 0 ) {);}
         number(val, &current.numbe2); // возможно сделать конкретно для числа, когда пушу.
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

// int polish_notation(list<Stack_t2> &stac2, list<Stack_t2> &polish) { return 0; }

// /**
//  * @brief          Создаем польскую анотацию из арифмитического выражения
//  *
//  * @param stack    - Стек из операторов и операндов в арифмитической
//  * последовательности
//  * @param polish   - Стек из операторов и операндов в польской натации
//  * @return         - Вернет 0, если число поданно корректно и 1, если есть
//  * ошибки
//  */

// int polish_notation(Stack_t *stack, Stack_t *polish) {
  int polish_notation(list<Stack_t2> &stac2, list<Stack_t2> &polis2) {
  printf("\nPOLISH \n");
  int err = TRUE;
  std::list<Stack_t2> znak;
  // int len = stac2.size();
  char doub[SIZE];  // Временная переменная для стека знак
  std::string dou2 = {0};
  std::list<Stack_t2>::iterator it;
  int count = 0;
  printstack(znak);
  for (it = stac2.begin(); it != stac2.end(); /*count*/it++) { // возможно end - 1
    // Stack_t2 current;
    cout << "pri _  " << it->dat2  << endl;
    // if (it->dat2 == " ") { // попробовать пробелы убирать на уровне польско нотации
    //     stac2.pop_back();
    // }
    if (it->type == 9) {
      // if (*it->pri == 9) {
      // push(polish, stack->data[count], stack->pri[count]);
      printf("number ---- \n");
      // push(polish, stack->datea[count], stack->pri[count]); // добавила -1
        polis2.push_back(*it);

    } else if (it->dat2 == "(" || it->type == 4) {
    //   // push(&znak, stack->data[count], stack->pri[count]);
    //   // printf(" ************* ");
      // push(&znak, stack->datea[count], stack->pri[count]);
      znak.push_back(*it);
    } else if (it->dat2 == ")") {
      std::list<Stack_t2>::iterator it_z1 = --znak.end();
      cout << "Нашли ) " << it->dat2  << endl;
      
      for (; it_z1->dat2 != "(" && it_z1->type != 4 && err == TRUE && --it_z1 != znak.begin(); ) {
          //  znak.datea[len] != "(" && znak.pri[len] != 4 && err == TRUE; len--) {
        // strcpy(doub, znak.data[znak.size]);
        // doub = znak.datea[znak.size];
        cout << "Пред цикл  " << it_z1->dat2  << endl;
        // it_z1 = --znak.end();  // возможно не надо
        printstack(znak);
        // dou2 = it_z1->dat2;
        // pop_push(&znak, polish, doub, znak.pri[znak.size + 1]);
        cout << "for__________it_z1->dat2  " << it_z1->dat2  << endl;
        pop_push(znak, polis2, doub, it_z1->type, it_z1);
        // if (len == 0) {err = -1;} //  удалила, возможно надо
        cout << "После цикл_  " << it_z1->dat2  << endl;
        // ++it_z1;
        it_z1 = --znak.end(); 
      }
      printstack(polis2);
      it_z1 = --znak.end();// Почему-то в поп не переходит на позицию назад, поэтому делаем так
      cout << "После цикл 2 " << it_z1->dat2  << endl;
      if (it_z1->dat2 == "(" || it_z1->type == 4) {
        cout << "for__у  " << it_z1->dat2  << endl;
        // pop(znak);
          cout << "CTECK_ZNAK __ (( " <<  endl;
            printstack(znak);
          cout << endl; 
        // dou2 = it_z1->dat2;
        // znak.pop_back(); // убрала возможно надо для функций
        // cout << "CTECK_ZNAK __ (( " <<  endl;
        //     printstack(znak);
        //   cout << endl; 
        // strcpy(doub, znak.data[znak.size + 1]);
        
        // if (it_z1->type == 4) {
          // push(polis2, doub, znak.pri[znak.size + 1]);
          cout << "IIIIII " <<  endl;
          polis2.push_back(*it_z1);
          znak.pop_back();
        // }
      }
    } else if (it->type) {
      cout << "for__у22 " << it->dat2  << endl;
      check_polish(znak, polis2, stac2, count);
      
    }
    if (it == --stac2.end()) {
      cout << "UUUU2 " << endl;
      
      int len_znak = znak.size();
      // cout << "eee " <<  len_znak << endl;
      std::list<Stack_t2>::iterator it_z = --znak.end();
      // for (; it_z != --znak.end(); it_z--) {
        for ( ; len_znak != 0; len_znak--) {
        // cout << "eee " <<  len_znak << endl;
        // strcpy(doub, znak.data[znak.size]);
        // std::string  doub = it_z->dat2; // yt yflj 
        pop_push(znak, polis2, doub, it_z->type, it_z);
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

int 





matematika(list<Stack_t2> &polis2, double *result) {
  // int matematika(Stack_t *polish, double *result) {
  printf("Matematika\n");
  int err = TRUE;
  double res = -0;
  double re2 = -0;
  std::stack<double> nu2;
  Stack_t  num = {0};
  // int size_v = polish->size;
  std::list<Stack_t2>::iterator it = polis2.begin();
  // for (size_t len = 1; len <= polis2.size(); len++) {


     //    if (num_stack.empty()) {
      //   throw std::runtime_error("Task Error");
      // }
      // b = std::stod(num_stack.top().token);
      // num_stack.pop();
      // if (num_stack.empty()) {
      //   throw std::runtime_error("Task Error");
      // }
      // a = std::stod(num_stack.top().token);
      // num_stack.pop();

      

    for (; it != polis2.end() && err == TRUE; it++) {
      cout << "__ " << it->dat2 << endl;
      cout << endl;
    if (it->dat2 == "u" || it->dat2 == "p") { //можно вывести унарную функцию
    // if (*polish->data[len] == 'u' || *polish->data[len] == 'p') { //можно вывести унарную функцию
      printf(" Unar \n");

 


      if (it->dat2 == "u") {
      // // if (*polish->data[len] == 'u') {
        // res = -num.number[num.size];
        
        // res = -it->numbe2;
        nu2.top() *= (-1);
      // } else { // не надо скорее всего
      //   // res = num.number[num.size];
      //   res = it->numbe2;
      }
        // num.size--;
        // push_num(&num, &res, 9);
        cout << "Промежуточнв=ый рез-т_un " << nu2.top() << endl;
    } else if (it->type == 9) {
        // cout << "Нашли число " << it->dat2 << endl;
        // push(&num, it->dat2, it->type);
        nu2.push(it->numbe2);

        cout << "Нашли число " << it->dat2 << " Размер стека nu2 " << nu2.size() << endl;
        for (int i = 0; i < nu2.size(); i++){
          cout << it->dat2 << " x ";          
        }
        cout << endl;
        // re2 = 
        // res = num.number[num.size]; // добавила -1, но не понятно почему, возможно копиться ошибки будут
        // cout << "Промежуточнв=ый рез-т_1_ " << num.size << " || " << num.number[num.size - 1] << endl;
    } else if (it->type == 4) {
        cout << "Нашли func " << it->dat2 << " Размер стека nu2 " << nu2.size() << endl;
        err = math_function(it, nu2, res);
    } else if (it->type == 1 || it->type == 2 || it->type == 5) {
        // // res = num.number[num.size - 1] + num.number[num.size - 2];
        // res = nu2.top();
        // nu2.pop();
        // res += nu2.top();
        // nu2.pop();
        // // num.size = num.size - 2;

        // nu2.push(res);
        // // push_num(&num, &res, 9);
        err = math_simple(it, nu2, res);
        cout << "Промежуточнв=ый рез-т_5 " << res << endl;
    // } else if (it->dat2 == "-") {
    //   cout << "Промежуточнв=ый рез-т_00 " << res << endl;
        // res = num.number[num.size - 1] - num.number[num.size];
        // num.size = num.size - 2;
        // res = nu2.top();
        // nu2.pop();
        // res -= nu2.top();
        // nu2.pop();
        // push_num(&num, &res, 9);
        // math_simple(it, nu2, res);
        // cout << "Промежуточнв=ый рез-т_6 " <<  << endl;
    // } else if (it->dat2 == "*") {
    //     res = num.number[num.size] * num.number[num.size - 1];
    //     num.size = num.size - 2;
    //     push_num(&num, &res, 9);
    // } else if (it->dat2 == "/") {
    //   math_simple(it, nu2, res);
    //   if (num.number[num.size] != 0) {
    //     res = num.number[num.size - 1] / num.number[num.size];
    //     num.size = num.size - 2;
    //     push_num(&num, &res, 9);
    //   } else {
    //     err = ZERO;
    //   }
    // } else if (*polish->data[len] == '^') {
    //   res = pow(num.number[num.size - 1], num.number[num.size]);
    //   num.size = num.size - 2;
    //   push_num(&num, &res, 9);
    // } else if (strncmp(polish->data[len], "cos(", 4) == 0) {
    //   res = cos(num.number[num.size]);
    //   matemat_res(&num, &res, 1);
    // } else if (strncmp(polish->data[len], "sin(", 4) == 0) {
    //   res = sin(num.number[num.size]);
    //   matemat_res(&num, &res, 1);
    // } else if (strncmp(polish->data[len], "tan(", 4) == 0) {
    //   res = tan(num.number[num.size]);
    //   matemat_res(&num, &res, 1);
    // } else if (strncmp(polish->data[len], "acos(", 5) == 0) {
    //   if (num.number[num.size] >= -1 && num.number[num.size] <= 1) {
    //     res = acos(num.number[num.size]);
    //     matemat_res(&num, &res, 1);
    //   } else {
    //     err = EFUC;
    //   }
    // } else if (strncmp(polish->data[len], "asin(", 5) == 0) {
    //   if (num.number[num.size] >= -1 && num.number[num.size] <= 1) {
    //     res = asin(num.number[num.size]);
    //     matemat_res(&num, &res, 1);
    //   } else {
    //     err = EFUC;
    //   }
    // } else if (strncmp(polish->data[len], "atan(", 5) == 0) {
    //   res = atan(num.number[num.size]);
    //   matemat_res(&num, &res, 1);
    // } else if (strncmp(polish->data[len], "log(", 4) == 0) {
    //   if (num.number[num.size] > 0) {
    //     res = log10(num.number[num.size]);
    //     matemat_res(&num, &res, 1);
    //   } else {
    //     err = EFUC;
    //   }
    // } else if (strncmp(polish->data[len], "ln(", 3) == 0) {
    //   if (num.number[num.size] > 0) {
    //     res = log(num.number[num.size]);
    //     matemat_res(&num, &res, 1);
    //   } else {
    //     err = EFUC;
    //   }
    // } else if (strncmp(polish->data[len], "sqrt(", 5) == 0) {
    //   if (num.number[num.size] >= 0) {
    //     res = sqrt(num.number[num.size]);
    //     matemat_res(&num, &res, 1);
    //   } else {
    //     err = EFUC;
    //   }
    // } else if (strncmp(polish->data[len], "mod", 3) == 0) {
    //   if (num.number[num.size] != 0) {
    //     res = fmod(num.number[num.size - 1], num.number[num.size]);
    //     matemat_res(&num, &res, 2);
    //   } else {
    //     err = ZERO;
    //   }
    }
    cout << "Промежуточнв=ый рез-т_res " << res << endl;
   
  }
  if (err == TRUE){
    // cout << "UUUUUU " << endl;
    res = nu2.top();
    *result = res;
  }
  printf("%f\n", *result);
  return err;
}

// int s21_calc_o(std::string str)
// {
//   str = "ppp";
//     return 0;
// }
