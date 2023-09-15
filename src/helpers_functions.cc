/**
 * @file      helpers_functions.cc
 * @author    jettajac
 * @brief
 * @version   0.1
 * @date      2023-03-16VALU 22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_calc.h"

using namespace std;
using namespace s21;


/**
 * @brief           Удаление всех пробелов из строки
 *
 * @param str      - Строка с арифметическим выражением
 * @return         - Тип элемента
 */

int Model::RemovesSpaces(std::string &str) { 
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
 * @param symbol   - Порядковый номер элементов в подаваемой строчке, с 0
 * @param value    - Строуовое значение элемента
 * @return         - Тип элемента
 */

int Model::Types(std::string str, int &symbol, std::string &valu) {
  // std::cout << "TYPES " <<  std::endl;
  int type = -1;
  int len = str.length();
  if (symbol < len && symbol >= 0) {
  if (str[symbol] == 's' || str[symbol] == 'c' || str[symbol] == 't' || str[symbol] == 'a' ||
      str[symbol] == 'l') {
    int res = CheckFuncs(str, symbol);
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
  } else if (str[symbol] == '(' || str[symbol] == ')') {
    len = 1;
    type = 3;
    
  } else if (str[symbol] == 'x' || str[symbol] == '^') {
    len = 1;
    type = 5;
  } else if (strncmp(&str[symbol], "mod", 3) == 0) {
    len = 3;
    type = 5;
  } else if ((str[symbol] > 47 && str[symbol] <= 57) || (str[symbol] == 46)) {
    len = 0;
    int n = symbol, m = 0;
    for (; (str[n] > 47 && str[n] <= 57) || str[n] == '.'; n++, m++) {
      len++;
    }
    type = 9;
  } else if (str[symbol] == '+' || str[symbol] == '-') {
    len = 1;
    type = 1;
  } else if (str[symbol] == '*' || str[symbol] == '/') {
    len = 1;
    type = 2;
  } else if (str[symbol] == 'e' || str[symbol] == 'E') {
    len = 1;
    type = 6;
  } else if (str[symbol] == '\0') {
    type = -1;
  } else {
    type = -1;
  }
  valu = str.substr(symbol, len);

  if (type == 9){
    CheckNumber(valu);
  }
  symbol += len -1;
  }
  return type;
}


/**
 * @brief           Индивицирует унарный минус
 * @param val     - Принимает значение строки
 * @return        - Вернет 0
 */

int Model::UnarZnak(std::string &val) { 
  if (val == "-") {
    val = "u";
  } else if (val == "+"){
    val = "p";
  }
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

int Model::Number(std::string str, double &number) {
  int err = -1;
  // cout <<  "~~~~~FUNCTION NUMBER~~~~~\n\n";
  if (CheckNumber(str) == 0 || number == -1) {
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

  int Model::CheckNumber(std::string str) {
  // cout  << "\n~~~~~CHECK NUMBER~~~~~\n\n";
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
 * @brief          Проверяет парсер на корректность ввода
 *
 * @param str      - Строка с арифметическим выражением
 * @param str_x    - Принимает значение X
 * последовательности
 * @param type     - Принимает тип текущего элемента
 * @param symbol   - Принимает ссылку на порядковый номер текущего элемента
 * @param value    - Принимает ссылку на значение текущего элемента
 * @param brackets - Принимает ссылку на текущее количество скобок в арифмитической строчке
 * @param polish   - Стек из операторов и операндов в польской натации
 * @return         - Вернет 0
 */

int Model::CheckParser(std::string str, std::string str_x, int type, int &symbol, std::string &value, int &brackets) { 
int err = -1;
  int symbol_afte2 = 0;
  int symbol_befor2 = 0;
  int len = str.length();
  int count;

  std::string data_befor2 = {0};
  std::string data_afte2 = {0};
  if (symbol >= 0 && symbol + 1 < len ) {
    count = symbol + 1;
    symbol_afte2 = Types(str, count, data_afte2); // возможно сразу создавать и присваивать и использовать typeы func
  }
  count = symbol - 1;
  symbol_befor2 = Types(str, count, data_befor2);
 
      if (type == 9) {
        if (data_afte2 == ")" || symbol_afte2 == 1 || symbol_afte2 == 2 ||
            data_afte2 == "^" || data_afte2 == "mod" || symbol == (len - 1) || symbol_afte2 == 6) {
          err = TRUE;
        }
      } else if (symbol == len - 1) {
        if (value == ")" || (type == 9 ) ||
            value == "x") {
          err = TRUE;
          if (value == ")") {brackets -= 1;}
        }
      } else if (symbol == 0 &&
                 (value == ")" || type == 2 || value == "mod" || value == "^")) { 
                  err = -1;
      } else if ((symbol == 0 && type == 1 &&
                  (symbol_afte2 == 4 || data_afte2 == "(" ||
                   data_afte2 == "x" || symbol_afte2 == 9)) ||
                 (type == 1 && (data_befor2 == ("(")) &&
                  (symbol_afte2 == 9 || symbol_afte2 == 4 ||
                   data_afte2 == "(" || data_afte2 == "x"))) {
        err = TRUE;        
        UnarZnak(value);
      } else if (type == 1 || (type == 2 && symbol != 0)) {
        if (symbol_afte2 != 1 && symbol_afte2 != 2 && data_afte2 != ")" && data_befor2 != "^") {
          err = TRUE;
        }
      } else if (value == ")") {
        if (data_afte2 == "\0" || data_afte2 == "^" || data_afte2 == ")" ||
            data_afte2[2] == 'd' || symbol_afte2 == 1 || symbol_afte2 == 2 || symbol_afte2 == 6) {
          brackets -= 1;
          err = TRUE;
        }
      } else if ((type == 4 && value != "mod") || value == "(") {
        brackets += 1;
        err = TRUE;
        if (data_afte2 == ")" || data_afte2 == "^" || symbol_afte2 == 2) {
          err = -1;
        }
      } else if (value == "mod") {
        int symbol_tmp = symbol - 3;
        symbol_befor2 = Types(str, symbol_tmp, data_befor2);  
        if (symbol_befor2 == 9 || data_befor2 == ")" || data_befor2 == "x") {
          symbol_tmp = symbol + 1;
          symbol_afte2= Types(str, symbol_tmp, data_afte2); 
          if (symbol_afte2 == 9 || data_afte2 == "(" || data_afte2 == "x") {
            err = TRUE;
          }
        }
      } else if (value == "^") {
        err = TRUE;
      } else if (type == 6) { // можно вывести в отдельную функцию
        if ((symbol_befor2 == 9 || data_befor2 == "x") && symbol_afte2 == 1) {
          value += data_afte2;
          symbol += 2;
          symbol_afte2 = Types(str, symbol, data_afte2);
        
          if (symbol_afte2 == 9 || data_afte2 == "x" ) {
            if (data_afte2 == "x" ) {
              data_afte2 = str_x;
            }
            value += data_afte2;
            err = TRUE;
          }          
        }  
      } else if (type < 6 && type > 0) {
        err = -1;
      }

  return err;
}


/**
 * @brief          Проверяет польскую нотацию
 *
 * @param znak     - Стек из операторов
 * @param polish   - Стек из операторов и операндов в польской натации
 * @param stack    - Стек из операторов и операндов в арифмитической
 * последовательности
 * @param symbol   - Порядковый номер текущего элемента
 * @return         - Вернет 0
 */

int Model::CheckPolish(std::list<Stack_t2_> &znak, std::list<Stack_t2_> &polish, std::list<Stack_t2_> &stac2, int symbol) { // можен сразу принимать интератор
  std::list<Stack_t2_>::iterator it = stac2.begin(); // Начинаем с начала списка
  std::advance(it, symbol);
  std::list<Stack_t2_>::iterator it_z = --znak.end();
  if (znak.size() == 0) {
    znak.push_back(*it); // 
  } else if (it->type == it_z->type) {
    PopPush(znak, polish, it_z);
    znak.push_back(*it);
  } else if (it->type <= it_z->type) {
    if (it_z->type != 3 && it_z->type != 4) {
      PopPush(znak, polish, it_z);
    }
    if (znak.size() > 0 && it->type <= it_z->type &&
      it_z->type < 3) {
      PopPush(znak, polish, it_z); 
    }
    znak.push_back(*it);
  } else if (it->type >= it_z->type) {
    znak.push_back(*it);
  }
  return 0;
}

/**
 * @brief          Проверяет функции на корректность
 *
 * @param str      - Строка с арифметическим выражением
 * @param symbol   - Порядковый номер, проверяемого символа
 * @return         - Вернет значение в зависимости от вида функции
 */

int Model::CheckFuncs(std::string str, int &symbol) { // млжно объеединить некоторые позиции
  int res = -1;
  if ((strncmp(&str[symbol], "sin(", 4) == 0 || strncmp(&str[symbol], "cos(", 4) == 0 ||
       strncmp(&str[symbol], "tan(", 4) == 0)) {
    res = 1;
  } else if (strncmp(&str[symbol], "asin(", 5) == 0 ||
             strncmp(&str[symbol], "acos(", 5) == 0 ||
             strncmp(&str[symbol], "atan(", 5) == 0) {
    res = 2;
  } else if (strncmp(&str[symbol], "log(", 4) == 0) {
    res = 3;
  } else if (strncmp(&str[symbol], "ln(", 3) == 0) {
    res = 4;
  } else if (strncmp(&str[symbol], "sqrt(", 5) == 0) {
    res = 5;
  }
  return res;
}

/**
 * @brief           Забирает верхний элемент из стека и пушит в друго стек
 *
 * @param stack     - Принимает стек с операндами и операторами
 * @param stack2    - Принимает стек с операндами и операторами
 * @param it        - Итератор последнего элемента stac2
 */

void Model::PopPush(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &stac22, std::list<Stack_t2_>::iterator &it) {
  // std::cout << "POP_PUSH_FUNC "  << std::endl;
  std::list<Stack_t2_>::iterator it2 = --stac2.end();
  stac22.push_back(*it2);
  stac2.pop_back();
  it = --stac2.end();
}


/**
 * @brief             Считает простые арифмитические действия и пушит результат
 *
 * @param numbers     - Стек с числами
 * @param tmp         - Сколько убираем чисел из стека
 */

int Model::MathSimple(std::list<Stack_t2_>::iterator &it, std::stack<double> &st_num, double &res)
{
  int err = TRUE;  
  double a, b;
  if (st_num.empty()) {
    throw std::runtime_error("Stack Error");
  }
  b = st_num.top();
  st_num.pop();

  if (st_num.empty()) {
    throw std::runtime_error("Stack Error");
  }
  a = st_num.top(); 
  st_num.pop();

  if (it->dat2 == "+") {
      res = a + b;
  } else if (it->dat2 == "-") {
    res = a - b;
  } else if (it->dat2 == "*") {
      res = a * b;
  } else if (it->dat2 == "/") {
    if (b != 0) {
      res = a / b;
    } else {
      err = ZERO;
    }
  } else if (it->dat2 == "^") {
      res = pow(a, b); 
  } else if (it->dat2 == "mod") {
    if (b != 0) {
      res = fmod(a, b);
    } else {
      err = ZERO;
    }
  }

  if (err == TRUE) {
     st_num.push(res);
  }
  return err;
}


/**
 * @brief             Считает значение функций и пушит их результат
 *
 * @param it          - Итератор, указывающий на текущую функцию
 * @param st_num      - Стек с числами
 * @param res         - Выводит результат функции
 */

int Model::MathFunction(std::list<Stack_t2_>::iterator &it, std::stack<double> &st_num, double &res) {
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


/**
 * @brief             Отображает элементы структуры
 *
 * @param stac2     - Стек с данными
 */

void Model::Printstack(std::list<Stack_t2_> &stac2) {

  std::cout << "Stack_Size > " << stac2.size() << std::endl;
  for (const Stack_t2_& item : stac2) {
        std::cout << item.dat2 << " | ";
  }
  std::cout << std::endl;
}
