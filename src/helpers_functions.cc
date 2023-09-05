/**
 * @file      helpers_functions.c
 * @author    jettajac
 * @brief
 * @version   0.1
 * @date      2023-03-16VALU 22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_calc.h"
#include <algorithm>


/**
 * @brief           Определяет тип, приоритет операндов и операторов
 *
 * @param str      - Строка с арифметическим выражением
 * @param count    - Порядковый номер элементов в подаваемой строчке, с 0
 * @param value    - Строуовое значение элемента
 * @return         - Тип элемента
 */

// Returning the current value
int types(std::string str, int *count, std::string *valu) {
  // cout << "TYPES" << endl;
  // int types(char *str, int *count, char *valu) {
  int type = -1;
  int vr = *count;
  int len = 0;
  if (str[vr] == 's' || str[vr] == 'c' || str[vr] == 't' || str[vr] == 'a' ||
      str[vr] == 'l') {
    int res = check_funcs(str, count);
    if (res == 1) {
      len = 4;
      type = 4;
    } else if (res == 2) {
      len = 5;
      type = 4;
    } else if (res == 3) {
      len = 4;
      type = 4;
    } else if (res == 4) {
      len = 3;
      type = 4;
    } else if (res == 5) {
      len = 5;
      type = 4;
    } else {
      type = -1;
    }
  } else if (str[vr] == '(' || str[vr] == ')') {
    len = 1;
    type = 3;
  } else if (str[vr] == 'x' || str[vr] == '^') {
    len = 1;
    type = 5;
  } else if (strncmp(&str[vr], "mod", 3) == 0) {
    len = 3;
    type = 5;
  } else if ((str[vr] > 47 && str[vr] <= 57) || (str[vr] == 46)) {
    len = 0;
    int n = vr, m = 0;
    for (; (str[n] > 47 && str[n] <= 57) || str[n] == '.'; n++, m++) {
      len++;
    }
    type = 9;
  } else if (str[vr] == '+' || str[vr] == '-') {
    len = 1;
    type = 1;
  } else if (str[vr] == '*' || str[vr] == '/') {
    len = 1;
    type = 2;
  } else if (str[vr] == '\0') {
    type = -1;
  } else {
    type = -1;
  }
  // strncpy(valu, &str[vr], len);
  // std::copy(str[vr], +len, valu.begin());
  *valu = str.substr(vr, len);
  // cout<< "VALU 22 = " << *valu <<endl;
  // std::copy(source.begin(), source.end(), destination.begin());
  // valu[len] = '\0';
  
  vr += len;
  *count = vr - 1;
  return type;
}

/**
 * @brief           Индивицирует унарный минус
 * @param val     - Принимает значение строки
 * @param tmp     - Тип  элемента
 * @return        - Вернет 0
 */

int intunar_znak(std::string val, int *tmp) {
  if (val == "-") {
    val = "u";
  } else {
    val = "p";
  }
  *tmp = 6;
  return 0;
}

/**
 * @brief          Проверяет и преобразует строчку  в дабл
 *
 * @param str      - Строка с арифметическим выражением
 * @param number   - Преобразованное число (дабл) из строки
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

int number(std::string str, double *number) {
  // int number(char *str, double *number) {
  int err = -1;
  // printf("\n%d ~~~~~FUNCTION NUMBER~~~~~\n\n", check_number(str));
  if (check_number(str) == 0) {
    double num; 
    try {
        num = std::stod(str); // Преобразование строки в double
        std::cout << "Число: " << num << " STR = " << str << endl;
        err = TRUE;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: Неверный аргумент. " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: Выход за пределы диапазона. " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Неизвестная ошибка." << std::endl;
    }
    *number = num;
    // printf("!!!!!!!!!!!Number_func - %.8lf - %.8lf - {%s}\n", atof(str),
    //        *number, str);
  }
  return err;
}

/**
 * @brief           Проверка числа на корректность ввода
 *
 * @param str      - Строка с арифметическим выражением
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

// int check_number(char *str) {
  int check_number(std::string str) {
  printf("\n~~~~~CHECK NUMBER~~~~~\n\n");
  int err = TRUE;
  int count_p = 0;
  int count_0 = 0;
  int count_n = 0;
  for (int count = 0; str[count] != '\0' && err == TRUE; count++) {
    if (str[count] == 48) {
      if ((str[1] != 46 && str[1] != '\0' && str[0] == 48) ||
          (count_n == 0 && count > 1 && !count_p)) {
        err = -1;
      }
      count_0++;
    } else if (str[count] == 45 && count == 0) {
      err = TRUE;
    } else if (str[count] == 48 && count_0 > 0 && count > 1 && count_p == 0) {
      err = -1;
    } else if (str[count] > 48 && str[count] <= 57) {
      count_n++;
      err = TRUE;
    } else if (str[count] == 46) {
      count_p++;
      if (count_p > 1 || str[count + 1] == '\0') {
        err = -1;
      }
    } else if (str[count] == 48 && count_0 > 0 && count_p == 1 && count > 1) {
      err = TRUE;
    } else {
      err = -1;
    };
  }
  cout<< "check_N " << endl;
  return err;
}

/**
 * @brief          Проверяет функции на корректность
 *
 * @param str      - Строка с арифметическим выражением
 * @param count    - Порядковый номер, проверяемого символа
 * @return         - Вернет значение в зависимости от вида функции
 */

int check_funcs(std::string str, int *count) {
  // int check_funcs(char *str, int *count) {
  int res = -1;
  int vr = *count;
  if ((strncmp(&str[vr], "sin(", 4) == 0 || strncmp(&str[vr], "cos(", 4) == 0 ||
       strncmp(&str[vr], "tan(", 4) == 0)) {
    res = 1;
  } else if (strncmp(&str[vr], "asin(", 5) == 0 ||
             strncmp(&str[vr], "acos(", 5) == 0 ||
             strncmp(&str[vr], "atan(", 5) == 0) {
    res = 2;
  } else if (strncmp(&str[vr], "log(", 4) == 0) {
    res = 3;
  } else if (strncmp(&str[vr], "ln(", 3) == 0) {
    res = 4;
  } else if (strncmp(&str[vr], "sqrt(", 5) == 0) {
    res = 5;
  }
  return res;
}

/**
 * @brief          Обрабатывает польскую нотацию
 *
 * @param znak    - Стек из операторов
 * @param stack    - Стек из операторов и операндов в арифмитической
 * последовательности
 * @param polish   - Стек из операторов и операндов в польской натации
 * @return         - Вернет 0
 */

int check_parser(string str, int type, int symbol, string value, int *brackets) {
int err = -1;
  int symbol_after = 0;
  int symbol_before = 0;

  // int brackets = 0;
  int len = str.length();

  std::string data_befor2 = {0};
  std::string data_afte2 = {0};
  if (symbol >= 0 && symbol + 1 < len ) {
    symbol_after = prev_next_ch(1, str, symbol + 1, &data_afte2); // возможно сразу создавать и присваивать и использовать typeы func
    cout << "data_befor2_ " << data_befor2 << endl;
    cout << "data_after_ " << data_afte2 << endl;
  }

  if (type != -1 && brackets >= 0) { //type нужен,  проверка на тайп сделать перед запуском чек парсер, тут оставить только скобки
      if (value == " ") { // не раюотает
        symbol++;
        cout<< "Out " << value <<endl;
    // continue; // возможно не надо
      } else if (type == 9 && check_number(value) == 0) {
        // cout<< "parser_N " << value <<endl;
        // cout<< "parser_a " << symbol_after <<endl;
        if (data_afte2 == ")" || symbol_after == 1 || symbol_after == 2 ||
            data_afte2 == "^" || data_afte2 == "m" || symbol == (len - 1)) {
          err = TRUE;
           cout<< "parser_N_Good " << value <<endl;
        }  

       } else if (symbol == len - 1) {
         cout<< "last_simlol" << value <<endl;
        if (value == ")" || (type == 9 && check_number(value) == 0) ||
            value == "x") {
              cout<< "last_simlol_good " << value <<endl;
          err = TRUE;
          if (value == ")") {
            *brackets -= 1;
          }
        }
      } else if (symbol == 0 &&
                 (value == ")" || type == 2 || value == "m" || value == "^")) { 
                  cout << "Nothing" << endl; // ничего нен проиходит
      } else if ((symbol == 0 && type == 1 &&
                  (symbol_after == 4 || data_afte2 == "(" ||
                   data_afte2 == "x" || symbol_after == 9)) ||
                 (type == 1 && (data_befor2 == ("(") || data_befor2 == "^") &&
                  (symbol_after == 9 || symbol_after == 4 ||
                   data_afte2 == "(" || data_afte2 == "x"))) {
        err = TRUE;
        cout << "UnarZnak" << endl; 
        intunar_znak(value, &type);
      } else if (type == 1 || (type== 2 && symbol != 0)) {
        if (symbol_after != 1 && symbol_after != 2 && data_afte2 != ")") {
          err = TRUE;
          cout << "Znak +/-/*" << endl; 
        }
      } else if (value == ")") {
        cout << "Brackets )" << endl; 
        if (data_afte2 == "\0" || data_afte2 == "^" || data_afte2 == ")" ||
            data_afte2 == "m" || symbol_after == 1 || symbol_after == 2) {
          *brackets -= 1;
          err = TRUE;
          cout << "Brackets ) Good" << endl; 
        }
      } else if ((type == 4 && value != "m") || value == "(") {
        *brackets += 1;
        cout << "Brackets (" << endl; 
        err = TRUE;
        if (data_afte2 == ")" || data_afte2 == "^" || symbol_after == 2) {
          err = -1;
        }
      } else if (value == "m") {
        cout << "VAL m" << endl; 
        int symbol_tmp = symbol - 2;
        symbol_before = prev_next_ch(-1, str, symbol_tmp - 1, &data_befor2);     // надо
        if (symbol_before == 9 || data_befor2 == ")" || data_befor2 == "x") {
          symbol_after = prev_next_ch(1, str, symbol + 1, &data_afte2); // надо
          if (symbol_after == 9 || data_afte2 == "(" || data_afte2 == "x") {
            err = TRUE;
          }
        }
      } else if (type == 5) {
        err = TRUE;
        cout << "TMP = 5" << endl; 
      } else if (type < 6 && type > 0) {
        err = -1;
      }
    } else { err = -1;}

  // symbol_before = type;
  // data_befor2 = value;
  cout << "___ bascets_ " << *brackets << " Code err_  "<< err << endl;

  return err;
}

int check_polish(Stack_t *znak, Stack_t *polish, Stack_t *stack, int vr) {
  char doub[SIZE];
  int count = vr;
  if (znak->size == 0) {
    // push(znak, stack->data[count], stack->pri[count]);
  // } else if (stack->pri[count] == znak->pri[znak->size]) {
  //   strcpy(doub, znak->data[znak->size]);
  //   pop_push(znak, polish, doub, znak->pri[znak->size + 1]);
  //   push(znak, stack->data[count], stack->pri[count]);
  // } else if (stack->pri[count] <= znak->pri[znak->size]) {
  //   if (znak->pri[znak->size] != 3 && znak->pri[znak->size] != 4) {
  //     strcpy(doub, znak->data[znak->size]);
  //     pop_push(znak, polish, doub, znak->pri[znak->size + 1]);
  //   }
  //   if (znak->size > 0 && stack->pri[count] <= znak->pri[znak->size] &&
  //       znak->pri[znak->size] < 3) {
  //     int tmp = znak->pri[znak->size];
  //     strcpy(doub, znak->data[znak->size]);
  //     pop_push(znak, polish, doub, tmp);
  //   }
  //   push(znak, stack->data[count], stack->pri[count]);
  // } else if (stack->pri[count] >= znak->pri[znak->size]) {
  //   push(znak, stack->data[count], stack->pri[count]);
  }
  return 0;
}

/**
 * @brief          Смотрит какой символ до или после  текущего
 *
 * @param flag     - Обозначает какой символ проеряем, "-1" - предыдущий и "1"
 * следующий за текущим
 * @param str      - Строка с арифметическим выражением
 * @param symbol   - Номер символа, которого проверяем в строке
 * @param value    - Строуовое значение элемента
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

int prev_next_ch(int flag, std::string str, int symbol, std::string *value) { // Переписать без флагов
  // int prev_next_ch(int flag, char *str, int symbol, char *value) {
  int err = -1;
  int len = str.length();
  // if (flag == 1 && symbol < len) {
    // symbol = symbol + 1;
    
    err = types(str, &symbol, value);
    // *value = "9";
   cout << "UUUU " << *value << endl;
    // value[1] = '\0'; // скорее всего не надо, точнее можно по другому реализовать    
    
  // }

  // if (flag == -1 && symbol > 0) {
  //   symbol = symbol - 1;
  //   err = types(str, &symbol, value);
  //   cout << "GGGG " << *value << endl;
  //   // value[1] = '\0';
  // }
  // printf("До после символа_2:  {{%s}}: %c, count: %d, value: '%s'\n", str,
  // err, symbol, value);

  return err;
}

/**
 * @brief           Кладет в стек оператор
 * @param stack     - Принимает стек с операндами и операторами
 * @param value     - Указатель на строковое значение
 * @param pri = Приоритет операнда и операторов
 */

void push(Stack_t *stack, std::string value, int pri) {
  // printf("\n~~~~~FUNCTION PUSH~~~~~\n\n");
  // int err = -1;
  int len = value.length();
  if (stack->size >= STACK_MAX_SIZE) {
    exit(STACK_OVERFLOW);
    // printf("OOOPs\n");
  }
  
  
  // strcpy(stack->data[stack->size], value);
  stack->datea.push_back(value);
  // stack->data[stack->size][len] = '\0';
  // stack->number[stack->size]
  // pri = 97;
  // cout << "TERST " << value << endl;
   
  
  number(value, &stack->number[stack->size]);
  // if (err == TRUE){
  stack->pri[stack->size] = pri;
 
  // printf("STACK->DATA[%d]: %s = %s, приоритет - %d = %d, число:  %f\n",
  //        stack->size, stack->data[stack->size], value,
  //        stack->pri[stack->size], pri,
  //        stack->number[stack->size]);
  // printf("|\n");
  // }
  stack->size++;
  // return err;
}

/**
 * @brief           Кладет в стек число
 * @param stack     - Принимает стек с операндами и операторами
 * @param value     - Указатель на число в дабл
 * @param pri = Приоритет операнда и операторов
 */

void push_num(Stack_t *stack, double *value, int pri) {
  // printf("\n~~~~~FUNCTION PUSH NUMBER~~~~~\n\n");
  // int len=strlen(value);
  if (stack->size >= STACK_MAX_SIZE) {
    exit(STACK_OVERFLOW);
    // printf("OOOPs\n");
  }
  stack->size++;

  stack->number[stack->size] = *value;
  // pri = 97;
  // number(value, &stack->number[stack->size]);
  stack->pri[stack->size] = pri;
  // printf("Value = %s\n", value);
  // printf("STACK->DATA[%d]: %s = %s, приоритет - %d = %d, число:  %f\n",
  //        stack->size, stack->data[stack->size], value,
  //        stack->pri[stack->size], pri,
  //        stack->number[stack->size]);
  // printf("|\n");
}

/**
 * @brief           Забирает верхний элемент из стека
 *
 * @param stack     - Принимает стек с операндами и операторами
 */

// Returns an element from the top and moves on to the next
void pop(Stack_t *stack) {
  if (stack->size == 0) {
    exit(STACK_OVERFLOW);
  }
  // printf("POP1: номер стека_0: %d, DATA: %s \n", stack->size,
  //        stack->data[stack->size]);
  stack->size--;
  // printf("POP1_1: номер стека: %d, DATA: %s \n", stack->size,
  //        stack->data[stack->size]);
  // *stack->data[stack->size+1];
}

/**
 * @brief           Забирает верхний элемент из стека и пушит в друго стек
 *
 * @param stack     - Принимает стек с операндами и операторами
 */

void pop_push(Stack_t *stack, Stack_t *stack2, char *val, int tmp) {
  pop(stack);
  push(stack2, val, tmp);
}

/**
 * @brief             Считает и пушит результат
 *
 * @param numbers     - Стек с числами
 * @param tmp         - Сколько убираем чисел из стека
 */

void matemat_res(Stack_t *numbers, double *res, int tmp) {
  // int vr = *tmp;
  numbers->size = numbers->size - tmp;
  push_num(numbers, res, 9);
}

// int parser_conditions(int *symbol, flags *fl) {
//   int res = 0;
//   int len = strlen(fl->str);

//   fl->symbol = *symbol;
//   if (fl->symbol != 0) {
//     fl->symbol_before = prev_next_ch(-1, fl->str, fl->symbol,
//     fl->data_before);
//   }
//   fl->symbol_after = prev_next_ch(1, fl->str, fl->symbol, fl->data_after);

//   if (*fl->data_after == ')' || fl->symbol_after == 1 ||
//       fl->symbol_after == 2 || *fl->data_after == '^' ||
//       *fl->data_after == 'm' || fl->symbol == (len - 1)) {
//     res = 1;
//   } else if ((symbol == 0 && fl->tmp == 1 &&
//               (fl->symbol_after == 4 || *fl->data_after == '(' ||
//                *fl->data_after == 'x' || fl->symbol_after == 9)) ||
//              (fl->tmp == 1 &&
//               (*fl->data_before == '(' || *fl->data_before == '^') &&
//               (fl->symbol_after == 9 || fl->symbol_after == 4 ||
//                *fl->data_after == '(' || *fl->data_after == 'x'))) {
//     res = 2;
//   } else if (fl->symbol_after != 1 && fl->symbol_after != 2 &&
//              *fl->data_after != ')') {
//     res = 3;
//   } else if (*fl->data_after == '\0' || *fl->data_after == '^' ||
//              *fl->data_after == ')' || *fl->data_after == 'm' ||
//              fl->symbol_after == 1 || fl->symbol_after == 2) {
//     res = 4;

//   } else if (*fl->data_after == ')' || *fl->data_after == '^' ||
//              fl->symbol_after == 2) {
//     res = 5;
//   }
//   return res;
// }

// int parser_check (flags *fl) {
//   int err = -1;
//   int len = strlen(fl->str);
//   if (*fl->val == ' ') {
//         fl->symbol++;
//       } else if (fl->tmp == 9 && check_number(fl->val) == 0) {
//         if (*fl->data_after == ')' || fl->symbol_after == 1 ||
//         fl->symbol_after == 2 ||
//             *fl->data_after == '^' || *fl->data_after == 'm' || fl->symbol ==
//             (len - 1)) {
//           err = TRUE;
//         }
//       } else if (fl->symbol == len - 1) {
//         if (*fl->val == ')' || (fl->tmp == 9 && check_number(fl->val) == 0)
//         ||
//             *fl->val == 'x') {
//           err = TRUE;
//           if (*fl->val == ')') {
//             fl->brackets--;
//           }
//         }
//       } else if (fl->symbol == 0 &&
//                  (*fl->val == ')' || fl->tmp == 2 || *fl->val == 'm' ||
//                  *fl->val == '^')) {
//       } else if ((fl->symbol == 0 && fl->tmp == 1 &&
//                   (fl->symbol_after == 4 || *fl->data_after == '(' ||
//                    *fl->data_after == 'x' || fl->symbol_after == 9)) ||
//                  (fl->tmp == 1 && (*fl->data_before == '(' ||
//                  *fl->data_before == '^') &&
//                   (fl->symbol_after == 9 || fl->symbol_after == 4 ||
//                    *fl->data_after == '(' || *fl->data_after == 'x'))) {
//         err = TRUE;
//         if (*fl->val == '-') {
//           *fl->val = 'u';
//           fl->tmp = 6;
//         } else {
//           *fl->val = 'p';
//           fl->tmp = 6;
//         }
//       } else if (fl->tmp == 1 || (fl->tmp == 2 && fl->symbol != 0)) {
//         if (fl->symbol_after != 1 && fl->symbol_after != 2 && *fl->data_after
//         != ')') {
//           err = TRUE;
//         }
//       } else if (*fl->val == ')') {
//         if (*fl->data_after == '\0' || *fl->data_after == '^' ||
//         *fl->data_after == ')' ||
//             *fl->data_after == 'm' || fl->symbol_after == 1 ||
//             fl->symbol_after == 2) {
//           fl->brackets--;
//           err = TRUE;
//         }
//       } else if ((fl->tmp == 4 && *fl->val != 'm') || *fl->val == '(') {
//         fl->brackets++;
//         err = TRUE;
//         if (*fl->data_after == ')' || *fl->data_after == '^' ||
//         fl->symbol_after == 2) {
//           err = -1;
//         }
//       } else if (*fl->val == 'm') {
//         int symbol_tmp = fl->symbol - 2;
//         fl->symbol_before = prev_next_ch(-1, fl->str, symbol_tmp,
//         fl->data_before); if (fl->symbol_before == 9 || *fl->data_before ==
//         ')' || *fl->data_before == 'x') {
//           fl->symbol_after = prev_next_ch(1, fl->str, fl->symbol,
//           fl->data_after); if (fl->symbol_after == 9 || *fl->data_after ==
//           '(' || *fl->data_after == 'x') {
//             err = TRUE;
//           }
//         }
//       } else if (fl->tmp == 5) {
//         err = TRUE;
//       } else if (fl->tmp < 6 && fl->tmp > 0) {
//         err = -1;  // было TRUE
//       }
//       return err;
// }

// /**
//  * @brief           Распечатываем значение в стеке
//  * @param value     - Указатель на строковое значение
//  */

// void printvalue_stack(char *value) { printf("%s", value); }
void printvalue_stack(char *value) { cout << value << endl;}

// //// Распечатываем стек
void printstack(Stack_t *stack) {
  int i;
  int len = stack->size;
  printf("stack %d > ", stack->size);
  for (i = 0; i < len; i++) { // почему то только с -1
    // printvalue_stack(stack->data[i]);
    // stack->datea.pop_back();
    cout << stack->datea[i];
    printf(" | ");
  }
  // if (stack->size != 0) {
  //   // printvalue_stack(stack->data[i]);
  //   cout << stack->datea[i] << endl;
  //   // stack->datea.pop_back();
  // }
  printf("\n");
}

// /**
//  * @brief           Распечатываем значение в стеке
//  * @param value     - Указатель на число (дабл)
//  */

void printstack_num(Stack_t *stack) {
  int i;
  int len = stack->size;
  // printf("stack %d > ", stack->size);
  for (i = 1; i < len + 1; i++) {
    printf("%f", (stack->number[i]));
    printf(" | ");
  }
  if (stack->size != 0) {
    printf("%f", (stack->number[i]));
  }
  printf("\n");
}