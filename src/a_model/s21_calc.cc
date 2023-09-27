/// \file
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

int Model::SmartCalc(std::string const str, std::string const str_x,
                     double &result) {
  std::list<Stack_t2_> stack;
  std::list<Stack_t2_> polish;
  int err = -1;
  result = 999.0;
  if (!str.empty() && !str_x.empty() && result != 0) {
    err = Parser(str, stack, str_x);
    Printstack(stack);
    if (err == TRUE) {
      err = PolishNotation(stack, polish);
      Printstack(polish);
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
 * @return         - Вернет 0, если арифмитическоевыражение поданно корректно и
 * 1, если есть ошибки
 */

int Model::Parser(std::string str, std::list<Stack_t2_> &stack,
                  std::string const str_x) {
  int err = TRUE;
  std::string val = {0};
  int tmp = -1;
  int brackets = 0;

  RemovesSpaces(str);  // Чистим от пробелов

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
      err = CheckParser(str, str_x, tmp, symbol, val, brackets);
      // std::cout << val << " @@and!! " << tmp << std::endl;
      Stack_t2_ current;
      if (err == TRUE) {
        if (tmp == 6) {
          std::list<Stack_t2_>::iterator it = --stack.end();
          val = it->dat2 + val;
          stack.pop_back();
        }
        current.dat2 = val;
        current.type = tmp;
        stack.push_back(current);
        // std::cout << val << " and!! " << tmp << std::endl;
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

int Model::PolishNotation(std::list<Stack_t2_> &stack,
                          std::list<Stack_t2_> &polish) {
  // cout  << "\nPOLISH \n";
  int err = TRUE;
  std::list<Stack_t2_> znak;
  std::list<Stack_t2_>::iterator it;
  int symbol = 0;
  for (it = stack.begin(); it != stack.end(); it++) {
    std::cout << it->type << " and " << it->dat2 << std::endl;
    if (it->type == 9 || it->type == 6) {
      polish.push_back(*it);
    } else if (it->dat2 == "(" || it->type == 4) {
      znak.push_back(*it);
    } else if (it->dat2 == ")") {
      std::list<Stack_t2_>::iterator it_z1 = --znak.end();
      for (; it_z1->dat2 != "(" && it_z1->type != 4 && err == TRUE &&
             --it_z1 != znak.begin();) {
        PopPush(znak, polish, it_z1);
        it_z1 = --znak.end();
      }
      it_z1 = --znak.end();
      if (it_z1->dat2 == "(" || it_z1->type == 4) {
        polish.push_back(*it_z1);
        znak.pop_back();
      }
    } else if (it->type) {
      CheckPolish(znak, polish, it);
    }
    if (it == --stack.end()) {
      int len_znak = znak.size();
      std::list<Stack_t2_>::iterator it_z;
      for (; len_znak > 0; len_znak--) {
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
    // std::cout << "**********************  " << it->type << std::endl;
    if (it->dat2 == "u" || it->dat2 == "p") {
      if (it->dat2 == "u") {
        nu2.top() *= (-1);
      }
    } else if (it->type == 9 || it->type == 6) {
      if (it->type == 6) {
        numbe2 = -1;
      }
      err = Number(it->dat2, numbe2);
      // std::cout << "^^^^^^^^ " << err << std::endl;
      nu2.push(numbe2);
    } else if (it->type == 4) {
      err = MathFunction(it, nu2, result);
    } else if (it->type == 1 || it->type == 2 || it->type == 5) {
      err = MathSimple(it, nu2, result);
    }
  }
  if (err == TRUE) {
    result = nu2.top();
  }
  return err;
}

// ________________________ Second func

/**
 * @brief           Удаление всех пробелов из строки
 *
 * @param str      - Строка с арифметическим выражением
 * @return         - Тип элемента
 */

int Model::RemovesSpaces(std::string &str) noexcept {
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

int Model::Types(std::string const str, int &symbol,
                 std::string &valu) noexcept {
  // std::cout << "TYPES " <<  std::endl;
  int type = -1;
  int len = str.length();
  if (symbol < len && symbol >= 0) {
    if (str[symbol] == 's' || str[symbol] == 'c' || str[symbol] == 't' ||
        str[symbol] == 'a' || str[symbol] == 'l') {
      int res = CheckFuncs(str, symbol);
      if (res == 1) {
        len = 4;
        type = 4;
      } else if (res == 2) {
        len = 5;
        type = 4;
      } else if (res == 3) {
        len = 3;
        type = 4;
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
    }
    valu = str.substr(symbol, len);

    if (type == 9) {
      CheckNumber(valu);
    }
    symbol += len - 1;
  }
  return type;
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
 * @param brackets - Принимает ссылку на текущее количество скобок в
 * арифмитической строчке
 * @param polish   - Стек из операторов и операндов в польской натации
 * @return         - Вернет 0
 */

int Model::CheckParser(std::string const str, std::string const str_x,
                       int &type, int &symbol, std::string &value,
                       int &brackets) noexcept {
  int err = -1;

  int s_prev = 0;
  int s_after = 0;
  int len = str.length();

  std::string d_prev = {0};
  std::string d_after = {0};
  CharPrevAfter(str, symbol, d_prev, d_after, s_prev, s_after);
  if (type == 9) {
    if (d_after == ")" || s_after == 1 || s_after == 2 || d_after == "^" ||
        d_after == "mod" || symbol == (len - 1) || s_after == 6) {
      err = TRUE;
    }
  } else if (symbol == len - 1) {
    if (value == ")" || (type == 9) || value == "x") {
      err = TRUE;
      if (value == ")") {
        brackets -= 1;
      }
    }
  } else if (symbol == 0 &&
             (value == ")" || type == 2 || value == "mod" || value == "^")) {
    err = -1;
  } else if ((symbol == 0 && type == 1 &&
              (s_after == 4 || d_after == "(" || d_after == "x" ||
               s_after == 9)) ||
             (type == 1 && (d_prev == ("(")) &&
              (s_after == 9 || s_after == 4 || d_after == "(" ||
               d_after == "x"))) {
    err = TRUE;
    UnarZnak(value, type);
    std::cout << value << "   !!!!!!!!!!!!!!!!!!!!!!!!!!!   " << type
              << std::endl;
  } else if (type == 1 || (type == 2 && symbol != 0)) {
    if (s_after != 1 && s_after != 2 && d_after != ")" && d_prev != "^") {
      err = TRUE;
    }
  } else if (value == ")") {
    if (d_after == "\0" || d_after == "^" || d_after == ")" ||
        d_after[2] == 'd' || s_after == 1 || s_after == 2 || s_after == 6) {
      brackets -= 1;
      err = TRUE;
    }
  } else if ((type == 4 && value != "mod") || value == "(") {
    brackets += 1;
    err = TRUE;
    if (d_after == ")" || d_after == "^" || s_after == 2) {
      err = -1;
    }
  } else if (value == "mod") {
    int symbol_tmp = symbol - 3;
    s_prev = Types(str, symbol_tmp, d_prev);
    if (s_prev == 9 || d_prev == ")" || d_prev == "x") {
      symbol_tmp = symbol + 1;
      s_after = Types(str, symbol_tmp, d_after);
      if (s_after == 9 || d_after == "(" || d_after == "x") {
        err = TRUE;
      }
    }
  } else if (value == "^") {
    err = TRUE;
  } else if (type == 6) {
    err = CheckExp(str, str_x, symbol, value);
  } else if (type < 6 && type > 0) {
    err = -1;
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

int Model::CheckNumber(std::string const str) const noexcept {
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
 * @brief          Проверяет функции на корректность
 *
 * @param str      - Строка с арифметическим выражением
 * @param symbol   - Порядковый номер, проверяемого символа
 * @return         - Вернет значение в зависимости от вида функции
 */

int Model::CheckFuncs(std::string const str, int &symbol) noexcept {
  int res = -1;
  if (strncmp(&str[symbol], "sin(", 4) == 0 ||
      strncmp(&str[symbol], "cos(", 4) == 0 ||
      strncmp(&str[symbol], "tan(", 4) == 0 ||
      strncmp(&str[symbol], "log(", 4) == 0) {
    res = 1;
  } else if (strncmp(&str[symbol], "asin(", 5) == 0 ||
             strncmp(&str[symbol], "acos(", 5) == 0 ||
             strncmp(&str[symbol], "atan(", 5) == 0 ||
             strncmp(&str[symbol], "sqrt(", 5) == 0) {
    res = 2;
  } else if (strncmp(&str[symbol], "ln(", 3) == 0) {
    res = 3;
  }
  return res;
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

int Model::CheckPolish(std::list<Stack_t2_> &znak, std::list<Stack_t2_> &polish,
                       std::list<Stack_t2_>::iterator it) {
  std::list<Stack_t2_>::iterator it_z = --znak.end();
  if (znak.size() == 0) {
    znak.push_back(*it);
  } else if (it->type == it_z->type) {
    PopPush(znak, polish, it_z);
    znak.push_back(*it);
  } else if (it->type <= it_z->type) {
    if (it_z->type != 3 && it_z->type != 4) {
      PopPush(znak, polish, it_z);
    }
    if (znak.size() > 0 && it->type <= it_z->type && it_z->type < 3) {
      PopPush(znak, polish, it_z);
    }
    znak.push_back(*it);
  } else if (it->type >= it_z->type) {
    znak.push_back(*it);
  }
  return 0;
}

/**
 * @brief             Проверяет корректность ввода кспоненциальной записи
 *
 * @param str         - Строка с арифметическим выражением
 * @param str_x    - Принимает значение X
 * @param symbol      - Порядковый номер текущего элемента
 * @param value       - Принимает ссылку на значение текущего элемента
 */

int Model::CheckExp(std::string const str, std::string const str_x, int &symbol,
                    std::string &value) noexcept {
  int err = -1;
  int s_prev = 0;
  int s_after = 0;
  std::string d_prev = {0};
  std::string d_after = {0};
  CharPrevAfter(str, symbol, d_prev, d_after, s_prev, s_after);
  if ((s_prev == 9 || d_prev == "x") && s_after == 1) {
    value += d_after;
    symbol += 2;
    s_after = Types(str, symbol, d_after);

    if (s_after == 9 || d_after == "x") {
      if (d_after == "x") {
        d_after = str_x;
      }
      value += d_after;
      err = TRUE;
    }
  }
  return err;
}

/**
 * @brief             Считает простые арифмитические действия и пушит результат
 *
 * @param numbers     - Стек с числами
 * @param tmp         - Сколько убираем чисел из стека
 */

int Model::MathSimple(std::list<Stack_t2_>::iterator &it,
                      std::stack<double> &st_num, double &res) {
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

int Model::MathFunction(std::list<Stack_t2_>::iterator &it,
                        std::stack<double> &st_num, double &res) {
  int err = TRUE;
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
 * @brief           Забирает верхний элемент из стека и пушит в друго стек
 *
 * @param stack     - Принимает стек с операндами и операторами
 * @param stack2    - Принимает стек с операндами и операторами
 * @param it        - Итератор последнего элемента stac2
 */

void Model::PopPush(std::list<Stack_t2_> &stac2, std::list<Stack_t2_> &stac22,
                    std::list<Stack_t2_>::iterator &it) noexcept {
  // std::cout << "POP_PUSH_FUNC "  << std::endl;
  std::list<Stack_t2_>::iterator it2 = --stac2.end();
  stac22.push_back(*it2);
  stac2.pop_back();
  it = --stac2.end();
}

/**
 * @brief          Проверяет и преобразует строчку  в дабл
 *
 * @param str      - Строка с арифметическим выражением
 * @param number   - Преобразованное число (дабл) из строки
 * @return         - Вернет 0, если число поданно корректно и 1, если есть
 * ошибки
 */

int Model::Number(std::string const str, double &number) {
  int err = -1;
  // cout <<  "~~~~~FUNCTION NUMBER~~~~~\n\n";
  if (CheckNumber(str) == 0 || number == -1) {
    double num;
    try {
      num = std::stod(str);  // Преобразование строки в double
      err = TRUE;
    } catch (const std::invalid_argument &e) {
      err = FAIL;
      std::cerr << "Ошибка: Неверный аргумент. " << e.what() << std::endl;
    } catch (const std::out_of_range &e) {
      err = -1;
      // std::cout << "$$$$$$$$$$$$$$$ " << err << std::endl;
      std::cerr << "Ошибка: Выход за пределы диапазона. " << e.what()
                << std::endl;

    } catch (...) {
      err = FAIL;
      std::cerr << "Неизвестная ошибка." << std::endl;
    }
    number = num;
  }
  // std::cout << "$$$$$$$$$$$$$$$ " << err << std::endl;
  return err;
}

/**
 * @brief           Индивицирует унарный минус
 *
 * @param val     - Принимает значение строки
 * @return        - Вернет 0
 */

int Model::UnarZnak(std::string &val, int &tmp) noexcept {
  if (val == "-") {
    val = "u";
  } else if (val == "+") {
    val = "p";
  }
  tmp = 7;
  return 0;
}

/**
 * @brief             Отображает значение и тип элемента до и после текущего
 *
 * @param str         - Строка с арифметическим выражением
 * @param symbol      - Порядковый номер текущего элемента
 * @param prev        - Значение предыдушего символа от текущего
 * @param after       - Значение последушего символа от текущего
 * @param p           - Тип предыдушего символа от текущего
 * @param a           - Тип последушего символа от текущего
 */

void Model::CharPrevAfter(std::string const str, int &symbol, std::string &prev,
                          std::string &after, int &p, int &a) noexcept {
  int count;
  int len = str.length();
  if (symbol >= 0 && symbol + 1 < len) {
    count = symbol + 1;
    a = Types(str, count, after);
  }
  count = symbol - 1;
  p = Types(str, count, prev);
}

/**
 * @brief             Отображает элементы структуры
 *
 * @param stac2     - Стек с данными
 */

void Model::Printstack(std::list<Stack_t2_> &stac2) {
  std::cout << "Stack_Size > " << stac2.size() << std::endl;
  for (const Stack_t2_ &item : stac2) {
    std::cout << item.dat2 << " | ";
  }
  std::cout << std::endl;
}
