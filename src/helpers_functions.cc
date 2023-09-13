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
// #include <string>



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


/**
 * @brief           Определяет тип, приоритет операндов и операторов
 *
 * @param str      - Строка с арифметическим выражением
 * @param count    - Порядковый номер элементов в подаваемой строчке, с 0
 * @param value    - Строуовое значение элемента
 * @return         - Тип элемента
 */

// Returning the current value
int types(std::string str, int &count, std::string &valu) {
  // cout << "TYPES " <<  endl;
  int type = 0;
  // int vr = count;
  int len = 0;
  if (str[count] == 's' || str[count] == 'c' || str[count] == 't' || str[count] == 'a' ||
      str[count] == 'l') {
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
  } else if (str[count] == '(' || str[count] == ')') {
    len = 1;
    type = 3;
    
  } else if (str[count] == 'x' || str[count] == '^') {
    len = 1;
    type = 5;
  } else if (strncmp(&str[count], "mod", 3) == 0) {
    len = 3;
    type = 5;
  } else if ((str[count] > 47 && str[count] <= 57) || (str[count] == 46)) {
    len = 0;
    int n = count, m = 0;
    for (; (str[n] > 47 && str[n] <= 57) || str[n] == '.'; n++, m++) {
      len++;
    }
    type = 9;
  } else if (str[count] == '+' || str[count] == '-') {
    len = 1;
    type = 1;
  } else if (str[count] == '*' || str[count] == '/') {
    len = 1;
    type = 2;
  } else if (str[count] == '\0') {
    type = -1;
  } else {
    type = -1;
  }
  valu = str.substr(count, len);
  // vr += len;
  // count = vr - 1;
  count += len -1;
  return type;
}

/**
 * @brief           Индивицирует унарный минус
 * @param val     - Принимает значение строки
 * @param tmp     - Тип  элемента
 * @return        - Вернет 0
 */

int unar_znak(std::string &val, int &tmp) {
  if (val == "-") {
    val = "u";
  } else {
    val = "p";
  }
  tmp = 6;
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

int number(std::string str, double &number) {
  int err = -1;
  // printf("\n%d ~~~~~FUNCTION NUMBER~~~~~\n\n", check_number(str));
  if (check_number(str) == 0) {
    double num; 
    try {
        num = std::stod(str); // Преобразование строки в double
        err = TRUE;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: Неверный аргумент. " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: Выход за пределы диапазона. " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Неизвестная ошибка." << std::endl;
    }
    number = num;
    cout << &number << " and " << num << endl;
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

  int check_number(std::string str) {
  // printf("\n~~~~~CHECK NUMBER~~~~~\n\n");
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
  return err;
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

int check_parser(string str, int type, int symbol, string &value, int &brackets) {
int err = -1;
// printf("\n ~~~~~Check_parser~~~~~\n\n");
  int symbol_afte2 = 0;
  int symbol_befor2 = 0;
  int len = str.length();

  std::string data_befor2 = {0};
  std::string data_afte2 = {0};
  if (symbol >= 0 && symbol + 1 < len ) {
    symbol_afte2 = prev_next_ch(str, symbol + 1, data_afte2); // возможно сразу создавать и присваивать и использовать typeы func
    
    // cout << "data_befor2_ " << data_befor2 << endl;
    // cout << "data_after_ " << data_afte2 << endl;
  }
  symbol_befor2 = prev_next_ch(str, symbol - 1, data_befor2);
  if (type != -1 && brackets >= 0) { //type нужен,  проверка на тайп сделать перед запуском чек парсер, тут оставить только скобки
      if (type == 9 && check_number(value) == 0) {
        // cout<< "parser_N " << "\"" << data_afte2 << "\"" << endl;
        // cout<< "parser_a " << symbol_after <<endl;
        if (data_afte2 == ")" || symbol_afte2 == 1 || symbol_afte2 == 2 ||
            data_afte2 == "^" || data_afte2 == "mod" || symbol == (len - 1) /*|| data_afte2 == " " *//*возможно не надо*/) {
          err = TRUE;
          //  cout<< "parser_N_Good " << value <<endl;
        }  

       } else if (symbol == len - 1) {
        //  cout<< "last_simlol" << value <<endl;
        if (value == ")" || (type == 9 && check_number(value) == 0) ||
            value == "x") {
              // cout<< "last_simlol_good " << value <<endl;
          err = TRUE;
          if (value == ")") {
            brackets -= 1;
          }
        }
      } else if (symbol == 0 &&
                 (value == ")" || type == 2 || value == "mod" || value == "^")) { 
                  cout << "Nothing" << endl; // ничего нен проиходит
      } else if ((symbol == 0 && type == 1 &&
                  (symbol_afte2 == 4 || data_afte2 == "(" ||
                   data_afte2 == "x" || symbol_afte2 == 9)) ||
                 (type == 1 && (data_befor2 == ("(") /*|| data_befor2 == "^"*/) &&
                  (symbol_afte2 == 9 || symbol_afte2 == 4 ||
                   data_afte2 == "(" || data_afte2 == "x"))) {
        err = TRUE;
        
        unar_znak(value, type);
        //  cout << "UnarZnak_ " << value << endl; 
      } else if (type == 1 || (type== 2 && symbol != 0)) {
        if (symbol_afte2 != 1 && symbol_afte2 != 2 && data_afte2 != ")" && data_befor2 != "^") {
          err = TRUE;
          // cout << "Znak +/-/*" << endl; 
        }
      } else if (value == ")") {
        // cout << "Brackets )" << endl; 
        if (data_afte2 == "\0" || data_afte2 == "^" || data_afte2 == ")" ||
            data_afte2 == "mod" || symbol_afte2 == 1 || symbol_afte2 == 2) {
          brackets -= 1;
          err = TRUE;
          // cout << "Brackets ) Good" << endl; 
        }
      } else if ((type == 4 && value != "mod") || value == "(") {
        brackets += 1;
        // cout << "Brackets (" << endl; 
        err = TRUE;
        if (data_afte2 == ")" || data_afte2 == "^" || symbol_afte2 == 2) {
          err = -1;
        }
      } else if (value == "mod") {
        // cout << "VAL m" << endl; 
        int symbol_tmp = symbol - 2;
        // cout << "VAL m22 tmp  " << symbol_tmp <<  endl; 
        symbol_befor2 = prev_next_ch(str, symbol_tmp - 1, data_befor2);  
        // cout << "VAL m22b " << symbol_befor2 <<  endl;    // надо
        if (symbol_befor2 == 9 || data_befor2 == ")" || data_befor2 == "x") {
          symbol_afte2= prev_next_ch(str, symbol + 1, data_afte2); // надо
          // cout << "VAL m _ current" << endl; 
          if (symbol_afte2 == 9 || data_afte2 == "(" || data_afte2 == "x") {
            err = TRUE;
            // cout << "VAL m _ GOOD" << endl; 
          }
        }
      } else if (type == 5) {
        err = TRUE;
        // cout << "TMP = 5" << endl; 
      } else if (type < 6 && type > 0) {
        err = -1;
      }
    } else { err = -1;}

  // symbol_before = type;
  // data_befor2 = value;
  // cout << "___ bascets_ " << brackets << " Code err_  "<< err << endl;

  return err;
}

int check_polish(list<Stack_t2> &znak, list<Stack_t2> &polish, list<Stack_t2> &stac2, int vr) { // можен сразу принимать интератор
  // char doub[SIZE];
  cout  << endl;
  // cout << "Check_polish1" << endl;
  // std::string doub = {0};
  // int count = vr;
  std::list<Stack_t2>::iterator it = stac2.begin(); // Начинаем с начала списка
  // cout << "Check_polish2" << endl;
  std::advance(it, vr);
  // cout << "Check_polish3" << endl;
  // if ()
  std::list<Stack_t2>::iterator it_z = --znak.end();
  // cout << "Check_polish4" << endl;

  // cout << it->type << " == " << endl;
  // cout << "Check_polish5" << endl;
  cout << it_z->type << endl; // что то с этим элементом, если удалить стык_т в основной функции, все падает

  if (znak.size() == 0) {
    znak.push_back(*it); // 
    // cout << "znak_ = 0" << endl;
  } else if (it->type == it_z->type) {
    // cout << "znak_ = znak_str_" << endl;
    // doub = it_z->dat2;
    pop_push(znak, polish, it_z);

    // push(znak, stack->data[count], stack->pri[count]);
    znak.push_back(*it);
  } else if (it->type <= it_z->type) {
    // cout << "1 <<<<<<<<<<<<<<<_" << it_z->dat2 << endl;
    if (it_z->type != 3 && it_z->type != 4) {
      printstack(znak);
      // doub = it_z->dat2;
      pop_push(znak, polish, it_z);
      // cout << "1 <<<<<<<<<<<<<<<_2" << it_z->dat2 << endl;
      // cout << "TEST___0 " << (it_z--)->dat2  << it_z->dat2 << (it_z++)->dat2  << endl; 
    }
    it_z = --znak.end();
    if (znak.size() > 0 && it->type <= it_z->type &&
      it_z->type < 3) {
          printstack(znak);
      it_z = --znak.end();
      // cout << "2 <<<<<<<<<<<<<<<_" << it_z->dat2 << endl;
      int tmp = it_z->type;
      // doub = it_z->dat2;
      pop_push(znak, polish, it_z); // хз в чем разниц а с предыдущим
    }
    znak.push_back(*it);
  } else if (it->type >= it_z->type) {
    znak.push_back(*it);
    // cout << ">>>>>>>>>>>>>>>>>_" << it_z->dat2 << endl;
  }
  cout << "CTECK_ZNAK00  " <<  endl;
  printstack(znak);
  cout << endl;
  printstack(polish);
  return 0;
}

/**
 * @brief          Проверяет функции на корректность
 *
 * @param str      - Строка с арифметическим выражением
 * @param count    - Порядковый номер, проверяемого символа
 * @return         - Вернет значение в зависимости от вида функции
 */

int check_funcs(std::string str, int &count) {
  int res = -1;
  // int vr = count;
  if ((strncmp(&str[count], "sin(", 4) == 0 || strncmp(&str[count], "cos(", 4) == 0 ||
       strncmp(&str[count], "tan(", 4) == 0)) {
    res = 1;
  } else if (strncmp(&str[count], "asin(", 5) == 0 ||
             strncmp(&str[count], "acos(", 5) == 0 ||
             strncmp(&str[count], "atan(", 5) == 0) {
    res = 2;
  } else if (strncmp(&str[count], "log(", 4) == 0) {
    res = 3;
  } else if (strncmp(&str[count], "ln(", 3) == 0) {
    res = 4;
  } else if (strncmp(&str[count], "sqrt(", 5) == 0) {
    res = 5;
  }
  return res;
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

int prev_next_ch(std::string str, int symbol, std::string &value) { // Переписать без флагов
  int err = -1;
  int len = str.length();
  // cout << "UUUU " << len << " symbol " << symbol << endl;
  char *value_c;
  if (symbol < len && symbol >= 0) {
    err = types(str, symbol, value);
  }
  return err;
}

/**
 * @brief           Кладет в стек оператор
 * @param stack     - Принимает стек с операндами и операторами
 * @param value     - Указатель на строковое значение
 * @param pri = Приоритет операнда и операторов
 */


/**
 * @brief           Кладет в стек число
 * @param stack     - Принимает стек с операндами и операторами
 * @param value     - Указатель на число в дабл
 * @param pri = Приоритет операнда и операторов
 */



/**
 * @brief           Забирает верхний элемент из стека
 *
 * @param stack     - Принимает стек с операндами и операторами
 */

// void pop(Stack_t *stack) {
//   if (stack->size == 0) {
//     exit(STACK_OVERFLOW);
//   }
//   stack->size--;
// }

/**
 * @brief           Забирает верхний элемент из стека и пушит в друго стек
 *
 * @param stack     - Принимает стек с операндами и операторами
 */

// void pop_push(Stack_t *stack, Stack_t *stack2, char *val, int tmp) {
//   pop(stack);
//   push(stack2, val, tmp);
// }

void pop_push(list<Stack_t2> &stac2, list<Stack_t2> &stac2_2, std::list<Stack_t2>::iterator &it) {
  std::list<Stack_t2>::iterator it2 = --stac2.end(); // времено для принта
  cout << "pop_push____ :   " << "Забрали_ " << it2->dat2 << " Отправили_ "<< it->dat2 << endl;
  stac2.pop_back();
  stac2_2.push_back(*it2);
  it = it2;
  cout << "finish pop push " << endl;
}

/**
 * @brief             Считает и пушит результат
 *
 * @param numbers     - Стек с числами
 * @param tmp         - Сколько убираем чисел из стека
 */
int math_simple(list<Stack_t2>::iterator &it, stack<double> &st_num, double &res)
{
  int err = TRUE;  // сделать другое
  double a, b;
  if (st_num.empty()) {
    throw std::runtime_error("Stack Error");
  }
  b = st_num.top();
  st_num.pop();
  if (st_num.empty()) {
    throw std::runtime_error("Stack Error");
  }
  a = st_num.top(); // можно сразу забирать строку и stod ее преобразовывать
  st_num.pop();
  if (it->dat2 == "+") {
      res = a + b;
  } else if (it->dat2 == "-") {
  res = a - b;
  //     // cout << "Промежуточнв=ый рез-т_6 " <<  << endl;
  } else if (it->dat2 == "*") {
  // //     res = num.number[num.size] * num.number[num.size - 1];
      res = a * b;
  } else if (it->dat2 == "/") {
    cout << "Деление_ " << b << endl;
    if (b != 0) {
      cout << "Деление_не 0 " << b << endl;
      res = a / b;
    } else {
      err = ZERO;
      cout << "Деление_== 0 " << b << endl;
    }
  } else if (it->dat2 == "^") {
      res = pow(a, b); // вохможно надо std
  } else if (it->dat2 == "mod") {
    if (b != 0) {
      res = fmod(a, b);
      // matemat_res(&num, &res, 2); // вроде как не надо, так как уже забрала 2 элемента и результат запушила
    } else {
      err = ZERO;
    }
  }
  if (err == TRUE) {
    // cout << "Згыр " << res << endl;

    // cout << "Size_  " << st_num.size() << endl;
      //  for (int i = 0; i < st_num.size(); i++){
      //     cout << it->numbe2 << " x ";          
      //   }
      //   cout << endl;

    st_num.push(res);
    // cout << "_________________" << endl;
  }
  return err;
}

int math_function(list<Stack_t2>::iterator &it, stack<double> &st_num, double &res) {
  int err = TRUE;  // сделать другое
  double a;
  if (st_num.empty()) {
    throw std::runtime_error("Stack Error");
  }
  a = st_num.top();
  st_num.pop();

  if (it->dat2 == "cos(") {
    res = cos(a);
  } else if (it->dat2 == "sin(") {
    res = sin(a);
  } else if (it->dat2 == "tan(") {
    res = tan(a);
  } else if (it->dat2 == "acos(") {
    if (a >= -1 && a <= 1) {
      res = acos(a);
    } else {
      err = EFUC;
    }
  } else if (it->dat2 == "asin(") {
    if (a >= -1 && a <= 1) {
      res = asin(a);
    } else {
      err = EFUC;
    }
  } else if (it->dat2 == "atan(") {
    res = atan(a);
  } else if (it->dat2 == "log(") {
    if (a > 0) {
      res = log10(a);
    } else {
      err = EFUC;
    }
  } else if (it->dat2 == "ln(") {
    if (a > 0) {
      res = log(a);
    } else {
      err = EFUC;
    }
  } else if (it->dat2 == "sqrt(") {
    if (a >= 0) {
      res = sqrt(a);
    } else {
      err = EFUC;
    }
  }

  if (err == TRUE) {
    st_num.push(res);
  }

  return err;
}




// void matemat_res(Stack_t *numbers, double *res, int tmp) {
//   numbers->size = numbers->size - tmp;
//   push_num(numbers, res, 9);
// }

// /**
//  * @brief           Распечатываем значение в стеке
//  * @param value     - Указатель на строковое значение
//  */

// void printvalue_stack(char *value) { cout << value << endl;}


// void printstack(Stack_t *stack) {
//   cout << "stack size > " << stack->size << endl;;
//   for (size_t i = 0; i < stack->size; i++) { 
//     cout << stack->datea[i] << " | ";
//   }
//   cout << endl;
// }

void printstack(std::list<Stack_t2> &stac2) {

  cout << "Stack_Size > " << stac2.size() << endl;
  for (const Stack_t2& item : stac2) {
        std::cout << item.dat2 << " | ";
  }
  cout << endl;
}

// /**
//  * @brief           Распечатываем значение в стеке
//  * @param value     - Указатель на число (дабл)
//  */

// void printstack_num(Stack_t *stack) {
//   int i;
//   int len = stack->size;
//   // printf("stack %d > ", stack->size);
//   for (i = 1; i < len + 1; i++) {
//     printf("%f", (stack->number[i]));
//     printf(" | ");
//   }
//   if (stack->size != 0) {
//     printf("%f", (stack->number[i]));
//   }
//   printf("\n");
// }