#include <gtest/gtest.h>

// #include "credit.c"
// #include "credit.h"
#include "s21_calc.h"
#include <array>
#include <vector>
// gcc -g -coverage mytest_calc.c SmartCalc.c -o test.out -I -l -lcheck

using namespace std;
using namespace s21;
Model *model1;


// _________________________________ BEGIN


//// Тест для double number
TEST(NumberTest, Double) {
  double num = {0};
  char str1[] = "1.345";
  model1->Number(str1,  num);
  EXPECT_EQ(num, 1.345);

  char str2[] = "0.345";
  model1->Number(str2,  num);
  EXPECT_EQ(num, 0.345);

  char str3[] = "1000.345";
  model1->Number(str3,  num);
  EXPECT_EQ(num, 1000.345);

  char str4[] = "234567890.34554569090984";
  model1->Number(str4,  num);
  EXPECT_EQ(num, 234567890.34554569090984);

  char str5[] = "10.3000405";
  model1->Number(str5,  num);
  EXPECT_EQ(num, 10.3000405);

  char str6[] = "0";
  model1->Number(str6,  num);
  EXPECT_EQ(num, 0);

  char str7[] = "1000";
  model1->Number(str7,  num);
  EXPECT_EQ(num, 1000);

  char str8[] = "0.0300";
  model1->Number(str8,  num);
  EXPECT_EQ(num, 0.0300);
}

// Тест для нормального ввода
TEST(NumberTest, ValidInput) {
    char validStr[] = "123.45";
    double result;
    int err = model1->Number(validStr, result);
    EXPECT_EQ(err, 0);
    EXPECT_DOUBLE_EQ(result, 123.45);
}

// Тест для некорректного ввода (не числовая строка)
TEST(NumberTest, InvalidInput) {
    char invalidStr[] = "abc";
    double result;
    int err = model1->Number(invalidStr, result);
    EXPECT_EQ(err, -1); // Ожидаем ошибку
}

// // Тест для крайнего значения (например, DBL_MAX)
// TEST(NumberTest, MaxDoubleValue) {
//     char maxStr[] = "1.7976931348623157e+308"; // Максимальное значение для double
//     double result;
//     int err = model1->Number(maxStr, result);
//     EXPECT_EQ(err, 0);
//     EXPECT_DOUBLE_EQ(result, DBL_MAX);
// }


TEST(NumberTest, NumberErr) {
  double num = {0};

  EXPECT_EQ(model1->Number("02.345",  num), -1);
  EXPECT_EQ(model1->Number("1.34.5",  num), -1);
  EXPECT_EQ(model1->Number("1,345",  num), -1);
  EXPECT_EQ(model1->Number("s1,345",  num), -1);
  EXPECT_EQ(model1->Number("1,h345",  num), -1);
  EXPECT_EQ(model1->Number("1,-345",  num), -1);
  EXPECT_EQ(model1->Number("(0,3459587474736",  num), -1);
  EXPECT_EQ(model1->Number("0,34595874747.36",  num), -1);
  EXPECT_EQ(model1->Number("0,34595874747+36",  num), -1);
  EXPECT_EQ(model1->Number("0.34595874747+36",  num), -1);
  EXPECT_EQ(model1->Number("0.34595874747sin36",  num), -1);
  EXPECT_EQ(model1->Number("sin0.34595874747",  num), -1);
  EXPECT_EQ(model1->Number("00.34595874747",  num), -1);
  EXPECT_EQ(model1->Number("00..34595874747",  num), -1);
  EXPECT_EQ(model1->Number("..34595874747",  num), -1);
  EXPECT_EQ(model1->Number(".34595874747",  num), 0);
  EXPECT_EQ(model1->Number("00",  num), -1);
  EXPECT_EQ(model1->Number("l8",  num), -1);
  EXPECT_EQ(model1->Number("0200",  num), -1);
  EXPECT_EQ(model1->Number("09",  num), -1);
  EXPECT_EQ(model1->Number("9.",  num), -1);
  EXPECT_EQ(model1->Number(".2",  num), 0);
  EXPECT_EQ(model1->Number("-3",  num), 0);
}

TEST(CheckNumber, Err) {
  // std::list<Model::Stack_t2_> stack_N;
  // // Stack_t stack_N[1] = {0};
  // double value[3] = {0.7};

  // push_num(stack_N, value, 1);
  // push_num(stack_N, value, 1);

  EXPECT_EQ(model1->CheckNumber("10"), 0);
  EXPECT_EQ(model1->CheckNumber("01"), -1);
  EXPECT_EQ(model1->CheckNumber("01."), -1);
  EXPECT_EQ(model1->CheckNumber("00."), -1);
  EXPECT_EQ(model1->CheckNumber("0.001"), 0);
  EXPECT_EQ(model1->CheckNumber("001"), -1);
  EXPECT_EQ(model1->CheckNumber("100000.00001"), 0);
  EXPECT_EQ(model1->CheckNumber("0.0000000001"), 0);
  EXPECT_EQ(model1->CheckNumber("00"), -1);
  EXPECT_EQ(model1->CheckNumber("00.."), -1);
  EXPECT_EQ(model1->CheckNumber("0.0.1"), -1);
  EXPECT_EQ(model1->CheckNumber("00.1"), -1);
  EXPECT_EQ(model1->CheckNumber("0.1"), 0);
  EXPECT_EQ(model1->CheckNumber("-0.1"), 0);
  EXPECT_EQ(model1->CheckNumber("-3"), 0);
  EXPECT_EQ(model1->CheckNumber("-0.0001"), 0);
  EXPECT_EQ(model1->CheckNumber("-0.000000"), 0);
  EXPECT_EQ(model1->CheckNumber("0.000000"), 0);
}

TEST(Calc, ParserSin) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  EXPECT_EQ(model1->Parser("*5+12", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("^5+12", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("5+12s", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin(", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin()", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin(5/)", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin(4.5)+cos(5", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin(4.5)+cos(5+4", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("/sin(5)", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("sin4", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("4sin(45)", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("1+sib(4)", stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser("1+sin(4)", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("-cos(4*2)+sin(4)", stack_N, str_x), 0);
}


TEST(Calc, ParserCos) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "=cos";
  char str2[] = "cos(";
  char str3[] = "cos()";
  char str4[] = "cos(5/)";
  char str5[] = "cos(4.5)+cos(5";
  char str6[] = "*cos(5)";
  char str7[] = "cosn4";
  char str8[] = "4cos(45)";
  char str9[] = "1+ces(5)";
  char str10[] = "1+cos(4)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
}


TEST(Calc, ParserTan) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";


  char str1[] = "=tan";
  char str2[] = "tan(";
  char str3[] = "tan()";
  char str4[] = "tan(5/)";
  char str5[] = "tan(4.5)+tan(5";
  char str6[] = "*tan(5)";
  char str7[] = "tann4";
  char str8[] = "4tan(45)";
  char str9[] = "1+tas(8)";
  char str10[] = "1+tan(4)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
}


TEST(Calc, ParserAsin) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "5+12s";
  char str2[] = "asin(";
  char str3[] = "asin()";
  char str4[] = "asin(5/)";
  char str5[] = "asin(4.5)+cos(5";
  char str6[] = "*asin(5)";
  char str7[] = "asin4";
  char str8[] = "4asin(45)";
  char str9[] = "1+asik(4)";
  char str10[] = "1+asin(4)";
  char str11[] = "asin(0.2)";
  char str12[] = "asin(8)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(str11, stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(str12, stack_N, str_x), 0);
}


TEST(Calc, ParserAcos) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "=acos";
  char str2[] = "acos(";
  char str3[] = "acos()";
  char str4[] = "acos(5/)";
  char str5[] = "acos(4.5)+acos(5";
  char str6[] = "/acos(5)";
  char str7[] = "acosn4";
  char str8[] = "4acos(45)";
  char str9[] = "1+aces(5)";
  char str10[] = "acos(8)";
  char str11[] = "acos(8)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(str11, stack_N, str_x), 0);
}


TEST(Calc, ParserAtan) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "=atan";
  char str2[] = "atan(";
  char str3[] = "atan()";
  char str4[] = "atan(5/)";
  char str5[] = "atan(4.5)+atan(5";
  char str6[] = "+atan(5x)";
  char str7[] = "atann4";
  char str8[] = "4atan(45)";
  char str9[] = "1+atas(8)";
  char str10[] = "atan(8)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
}


TEST(Calc, ParserSqrt) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "+sqrt";
  char str2[] = "sqrt(";
  char str3[] = "sqrt()";
  char str4[] = "sqrt(5/)";
  char str5[] = "sqrtn(4.5)";
  char str6[] = "*sqrt(5)";
  char str7[] = "sqrt4";
  char str8[] = "4sqrt(45)";
  char str9[] = "1+sqrt(8)";
  char str10[] = "1+(-sqrt(8))";
  char str11[] = "sqrt(-4)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(str11, stack_N, str_x), 0);
}


TEST(Calc, ParserLog) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "+log";
  char str2[] = "log(";
  char str3[] = "log()";
  char str4[] = "log(5/)";
  char str5[] = "logn(4.5)";
  char str6[] = "/log(5)";
  char str7[] = "log4";
  char str8[] = "4log(45)";
  char str9[] = "1+logt(8)";
  char str10[] = "log(5)";
  char str11[] = "ln(34)+log(5)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser(str11, stack_N, str_x),  0);
}


TEST(Calc, ParserLn) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";
  char str1[] = "+ln";
  char str2[] = "ln(";
  char str3[] = "ln()";
  char str4[] = "ln(5/)";
  char str5[] = "lnn(4.5)";
  char str6[] = "+ln(5i)";
  char str7[] = "ln4";
  char str8[] = "4ln(45)";
  char str9[] = "1+lnt(8)";
  char str10[] = "ln(5)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), 0);
}


TEST(Calc, ParserMod) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  EXPECT_EQ(model1->Parser("+mod", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("mod(", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5mod()", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("mod(5/)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("modn4", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("+mod5)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("mod4", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("4mod(45)", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("1+modt(8)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("1mod3", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("(3+4)mod(3+1)", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("7mod3", stack_N, str_x),  0);
}


TEST(Calc, ParserX) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  EXPECT_EQ(model1->Parser("+x^", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("x(", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("mx*5", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5x()", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("sinx", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("x+", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5+x", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("5*x", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("5x", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5(-x)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5*(-x)", stack_N, str_x),  0);
}


TEST(Calc, ParserPow) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  EXPECT_EQ(model1->Parser("x^)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5^", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("^", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("^5", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("sin(^5)", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("^+", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5^2", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("5^(2+1)", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("2^2^2^2", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("5^+4", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5^-4", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("5^(-4+cos(5))", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("2^(-1+1*3)", stack_N, str_x),  0);
}

TEST(Calc, ParserExpErr) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  EXPECT_EQ(model1->Parser("0.5e+x", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("xe+6", stack_N, str_x),  0);  
  EXPECT_EQ(model1->Parser("(1+2)e+6", stack_N, str_x),  -1); // потом обработать
  EXPECT_EQ(model1->Parser("(-2)e+6", stack_N, str_x),  -1); // потом обработать
  EXPECT_EQ(model1->Parser("-0.5e+6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("+0.5e+6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5e-6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5E+6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5E-6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5k+6", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("0.5e+6e", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("0.5e+6E", stack_N, str_x),  -1);
  EXPECT_EQ(model1->Parser("0.5 e+6", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5e+6+2", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5e+6*4", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5e-3*4", stack_N, str_x),  0);
  EXPECT_EQ(model1->Parser("0.5ee-3*4", stack_N, str_x),  -1);
}


TEST(Calc, ParserSpace2) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";
  EXPECT_EQ(model1->Parser("( 5   )", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser(" 5 ", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("(cos(6 4))", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("(cos(6) + sin( 5 ))", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("sin( 5 )", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("4 + 3", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("(sin( 1 * 2 * 38 + 1))", stack_N, str_x), 0);
  EXPECT_EQ(model1->Parser("0.5 e + 6", stack_N, str_x), 0);  
}


TEST(Calc, Znak) {
  double num = 0;
  char x[10] = "2";
  model1->SmartCalc("-(5+6)", x, num);
  EXPECT_EQ(num,  -11);
}


TEST(Calc, ZnakErr) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "5+*6";
  char str2[] = "55+";
  char str3[] = "+-6";
  char str4[] = "+";
  char str5[] = "-";
  char str6[] = "*";
  char str7[] = "/";
  char str8[] = "-/8";
  char str9[] = "(sin(1*2*38+))";
  char str10[] = "/5";
  char str11[] = "+(*5)";
  char str12[] = "(5+-5)";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str9, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str10, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str11, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str12, stack_N, str_x), -1);
}


TEST(Calc, BracketsErr) {
  std::list<Model::Stack_t2_> stack_N;
  std::string str_x = "1";

  char str1[] = "sin(2*(2*2)";
  char str2[] = "()sin(1*2*3(8)";
  char str3[] = "((sin(1*2*3(8))";
  char str4[] = "(sin(1*2*38+))";
  char str5[] = "(/5)";
  char str6[] = "(*5)";
  char str7[] = "(5*)";
  char str8[] = "1+)*5-4(";

  EXPECT_EQ(model1->Parser(str1, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str2, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str3, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str4, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str5, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str6, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str7, stack_N, str_x), -1);
  EXPECT_EQ(model1->Parser(str8, stack_N, str_x), -1);
}


TEST(Calc, Types) { //работает
  int tmp = 0;
  string num;
  char str[] = "0.345";

  model1->Types( str, tmp, num);
  EXPECT_EQ(num[0] == '0', true);

  tmp = 1;
  model1->Types(str, tmp, num);
  EXPECT_EQ(num[0] == '.', true);

  tmp = 2;
  model1->Types(str, tmp, num);
  EXPECT_EQ(num[0] == '3', true);

  tmp = -2;
  tmp = model1->Types( str, tmp, num);
  EXPECT_EQ(tmp == -1, true);

  tmp = 5;
  tmp = model1->Types(str, tmp, num);
  EXPECT_EQ(tmp == -1, true);
}


TEST(Calc, MatematikaSimple) {
  double res = 0;
  int tmp = 1;
  char x[3] = "1";
  string str;

  model1->SmartCalc("5", x, res);  
  EXPECT_EQ(res == 5, true);

  str = "0.345+5";
  model1->SmartCalc(str, x, res);
  EXPECT_EQ(res == 5.345, true);

  model1->SmartCalc("5+7-3-2", x, res);
  EXPECT_EQ(res == 7, true);

  model1->SmartCalc("5+7-3*2", x, res);
  EXPECT_EQ(res == 6, true);

  model1->SmartCalc("5+7*3-3*2", x, res);
  EXPECT_EQ(res == 20, true);

  model1->SmartCalc("5+7-3/2", x, res);
  EXPECT_EQ(res == 10.5, true);

  model1->SmartCalc("3*(5+6)-2*4-(8*9/3-6)", x, res);
  EXPECT_EQ(res == 7, true);

  model1->SmartCalc("3*(5+6)-2*4-(8*9/3-6)/7", x, res);
  EXPECT_EQ(res - 22.4285714285714286 <= ERC, true);

  model1->SmartCalc("3*(5+6)-2*4-(8*9/3-6)/7-2*3", x, res);
  EXPECT_EQ(res - 16.4285714285714286 <= ERC, true);

  model1->SmartCalc("3-(5+6)*(2+4)-8*9-6/7-2*3", x, res);
  EXPECT_EQ(res -(-141.8571428571428571) <= ERC, true);

  tmp = model1->SmartCalc("(5+4-2*5)/(5-5)", x, res);
  EXPECT_EQ(tmp, -2);

  tmp = model1->SmartCalc("(4+10)/0*2+1", x, res);
  EXPECT_EQ(tmp, -2);

  model1->SmartCalc("80/2", x, res);
  EXPECT_EQ(res - 40 <= ERC, true);

  model1->SmartCalc("80/(2-10)", x, res);
  EXPECT_EQ(res - (-10) <= ERC, true);

  model1->SmartCalc("80/(-10)", x, res);
  EXPECT_EQ(res - (-8) <= ERC, true);

  model1->SmartCalc("-80/(-10)", x, res);
  EXPECT_EQ(res - 8 <= ERC, true);

  model1->SmartCalc("-(5+1)", x, res);
  EXPECT_EQ(res - (-6) <= ERC, true);

  model1->SmartCalc("-(-(5+2)*4)", x, res);
  EXPECT_EQ(res - 28 <= ERC, true);

  model1->SmartCalc("-(+(5+2)*4)", x, res);
  EXPECT_EQ(res - (-28) <= ERC, true);

  model1->SmartCalc("5", x, res);
  EXPECT_EQ(res - 5 <= ERC, true);

  model1->SmartCalc("-5", x, res);
  EXPECT_EQ(res - (-5) <= ERC, true);

  model1->SmartCalc("sin(cos(log(5^2)))", x, res);
  
  EXPECT_EQ(res - 0.17115002489 <= ERC, true);

  model1->SmartCalc("sin(cos(tan(acos(asin(atan(log(1*ln(sqrt(5mod3^(-2)+x)))))))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.742174 <= ERC, true);
  
  // 0.71188622115482
  model1->SmartCalc("sin(cos(tan(acos(1))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.8414709848 <= ERC, true);

  model1->SmartCalc("sin(2)", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.90929742682 <= ERC, true);

  model1->SmartCalc("sqrt((-2)*(-2))", x, res);
  EXPECT_EQ(res == 2, true);  
}


TEST(Calc, MatematikaTrig_1) {
  double res = 999;
  char x[3] = "46";

  model1->SmartCalc("sin(5)", x, res);
  res = res - (-0.95892427466);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("cos(5)", x, res);
  res = res - (0.28366218546);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("cos(45)", x, res);
  res = res - (0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("-cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("-cos(45)", x, res);
  res = res - (-0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("1-cos(45)", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("1-(-cos(45))", x, res);
  res = res - (1.52532198882);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("1-(-(-cos(45)))", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("acos(0.5)", x, res);
  res = res - (1.0471975511966);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("asin(0.5)", x, res);
  res = res - (0.523598775598299);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("atan(x)", x, res);
  res = res - (1.5490606199531);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("sin(x)", x, res);
  res = res - (0.90178834764881);
  EXPECT_EQ(res <= ERC, true);
  cout << "TEST_ " << res << endl;
}


TEST(Calc, MatematikaLog) {
  double res = 999;
  char x[3] = "1";

  model1->SmartCalc("log(5)", x, res);
  res = res - (0.6989700043360189);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("ln(5)", x, res);
  res = res - (1.6094379124341004);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("log(45)", x, res);
  res = res - (1.6532125137753437);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("ln(45)+log(67)", x, res);
  res = res - (5.6327372924711462);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("(-log(45)+sin(67))-(ln(10)+log(56))", x, res);
  res = res - (-6.55950561275);
  EXPECT_EQ(res <= ERC, true);

  model1->SmartCalc("-ln(45-20)", x, res);
  res = res - (-3.2188758248682007);
  EXPECT_EQ(res <= ERC, true);
}


TEST(Calc, MatematikaMod) {
  double res = 999;
  char x[3] = "1";

  model1->SmartCalc("45mod4", x, res);
  EXPECT_EQ(res == 1, true);

  model1->SmartCalc("(2+3*5)mod(3*2)", x, res);
  EXPECT_EQ(res == 5, true);

  model1->SmartCalc("(2^2^2)mod3", x, res);
  EXPECT_EQ(res == 1, true);

  model1->SmartCalc("5mod2+33mod6*6", x, res);
  EXPECT_EQ(res == 19, true);

  model1->SmartCalc("(-7)mod(7mod4)", x, res);
  EXPECT_EQ(res == -1, true);
 }


TEST(Calc, MatematikaPow) {
  double res = 999;
  char x[3] = "1";

  model1->SmartCalc("2^(-1+1*3)", x, res);
  EXPECT_EQ(res == 4, true);

  model1->SmartCalc("2^(-1+1*3)+5*4", x, res);
  EXPECT_EQ(res == 24, true);

  model1->SmartCalc("2^(-2)", x, res);
  EXPECT_EQ(res == 0.25, true);

  model1->SmartCalc("(-3^(-3))", x, res);
  res = res - (-0.037037037037037);
  EXPECT_EQ(res <= ERC, true);
}


TEST(Calc, MatematikaX) {
  double res = 999;
  char x[3] = "5";

  model1->SmartCalc("x^2+3*x", x, res);
  EXPECT_EQ(res == 40, true);

  model1->SmartCalc("3*x", x, res);
  EXPECT_EQ(res == 15, true);

  model1->SmartCalc("x*3", x, res);
  EXPECT_EQ(res == 15, true);

  model1->SmartCalc("3*x+2*x", x, res);
  EXPECT_EQ(res == 25, true);

  model1->SmartCalc("3*x+2+x", x, res);
  EXPECT_EQ(res == 22, true);

  model1->SmartCalc("-x", x, res);
  EXPECT_EQ(res == -5, true);

  char x2[3] = "-5";

  model1->SmartCalc("x^2+3*x", x2, res);
  EXPECT_EQ(res == 10, true);

  model1->SmartCalc("3*x", x2, res);
  EXPECT_EQ(res == -15, true);

  model1->SmartCalc("x*3", x2, res);
  EXPECT_EQ(res == -15, true);

  model1->SmartCalc("3*x+2*x", x2, res);
  EXPECT_EQ(res == -25, true);

  model1->SmartCalc("3*x+2+x", x2, res);
  EXPECT_EQ(res == -18, true);

  model1->SmartCalc("-x", x2, res);
  EXPECT_EQ(res == 5, true);
}


TEST(Calc, MatematikaErr) {
  double res = 999;
  char x[3] = "-1";

  EXPECT_EQ(model1->SmartCalc("-cos(45)sin(67)", x, res) == -1, true);
  EXPECT_EQ(model1->SmartCalc("1 - cos(45)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("-cos(45)+sin(-67)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("-cos(+45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("-ln(45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("5mod4+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("2^2^2", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("2^2^", x, res) == -1, true);
  EXPECT_EQ(model1->SmartCalc("2^(-1+1*3)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("2^(-1+1*3)+5*4", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("log(-45)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("6mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("(-5)mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("(-5)mod(6mod4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("(2+3*5)mod(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("atan(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("asin(5)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("asin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("acos(5)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("acos(0.5)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("atan(5)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("sin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("cos(5)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("tan(5)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("ln(-5)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("log(-5)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("10mod(5-5)", x, res) == -2, true);
  EXPECT_EQ(model1->SmartCalc("10mod(-x)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("10modx", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("xmod5", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("(-x)mod5", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("sqrt(x)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("sqrt(-1)", x, res) == -3, true);
  EXPECT_EQ(model1->SmartCalc("sqrt(4)", x, res) == 0, true);
  EXPECT_EQ(model1->SmartCalc("(5^-3)", x, res) == -1, true);
}

TEST(Calc, MatematikaExp) {
  std::string str_x = "1";
  double res = 999;
// "sin(x)e+2" // на будушее, что хотелось бы, чтоб обраьатывал
// "(1+2)e+6"
// 2e+(6+1)

  EXPECT_EQ(model1->SmartCalc("xe+4", str_x, res),  0);
  EXPECT_EQ(res == 10000, true);
  EXPECT_EQ(model1->SmartCalc("65e+x", str_x, res),  0);
  EXPECT_EQ(res == 650, true);
  EXPECT_EQ(model1->SmartCalc("65e+4", str_x, res),  0);
  EXPECT_EQ(res == 650000, true);
  EXPECT_EQ(model1->SmartCalc("0.5e+5", str_x, res),  0);
  EXPECT_EQ(res == 50000, true);
  EXPECT_EQ(model1->SmartCalc("-1.5e+5", str_x, res),  0);
  EXPECT_EQ(res == -150000, true);
  EXPECT_EQ(model1->SmartCalc("+0.5e+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->SmartCalc("0.5e-6", str_x, res),  0);
  EXPECT_EQ(res == 5e-07, true);
  EXPECT_EQ(model1->SmartCalc("0.5E+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->SmartCalc("0.5E-2", str_x, res),  0);
  EXPECT_EQ(res == 0.005, true);
  EXPECT_EQ(model1->SmartCalc("0.5 e+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->SmartCalc("0.5e+6+2", str_x, res),  0);
  EXPECT_EQ(res == 500002, true);
  EXPECT_EQ(model1->SmartCalc("0.5e+2*4", str_x, res),  0);
  EXPECT_EQ(res == 200, true);
  EXPECT_EQ(model1->SmartCalc("0.5e-3*4", str_x, res),  0);
  EXPECT_EQ(res == 0.002, true);
}


TEST(Calc, PrintStack) {
  std::list<Model::Stack_t2_> stack_N;
  Model::Stack_t2_ current;
  current.dat2 = "1";
  current.type = 9;
  stack_N.push_back(current);

  current.dat2 = "+";
  current.type = 1;
  stack_N.push_back(current);

  current.dat2 = "3";
  current.type = 9;
  stack_N.push_back(current);

  model1->Printstack(stack_N);  
}












// // // TEST(Calc, credit_calc) {
// // //   credit_t credit_N[10];
// // //   credit_N->type = 1;
// // //   credit_N->total_credit = 60000;
// // //   credit_N->period = 6;
// // //   credit_N->period_uom = 'm';  // y - year, m - month
// // //   credit_N->percent_rate = 24;
// // //   credit_N->overpayment = 0.0;
// // //   credit_N->month_min = 0.0;
// // //   credit_N->month_max = 0.0;

// // //   calc_credit(credit_N);
// // //   EXPECT_EQ(credit_N->overpayment == 4200, "FAILED credit_a_1");
// // //   EXPECT_EQ(credit_N->month_max == 11200, "FAILED credit_a_2");
// // //   EXPECT_EQ(credit_N->month_min == 10200, "FAILED credit_a_3");

// // //   credit_N->period_uom = 'y';
// // //   credit_N->period = 0.5;
// // //   calc_credit(credit_N);

// // //   credit_N->overpayment = credit_N->overpayment - 4200;
// // //   EXPECT_EQ(credit_N->overpayment <= 0, "FAILED credit_a_4");
// // //   credit_N->month_max = credit_N->month_max - 10120;
// // //   EXPECT_EQ(credit_N->month_max <= 0, "FAILED credit_a_5");

// // //   credit_N->type = 2;
// // //   calc_credit(credit_N);

// // //   credit_N->overpayment = credit_N->overpayment - 4400;
// // //   EXPECT_EQ(credit_N->overpayment <= 0, "FAILED credit_d_1");
// // //   credit_N->month_max = credit_N->month_max - 10740;
// // //   EXPECT_EQ(credit_N->month_max <= 0, "FAILED credit_d_2");
// // //   credit_N->month_min = credit_N->month_min - 10740;
// // //   EXPECT_EQ(credit_N->month_min <= 0, "FAILED credit_d_3");

// // //   credit_N->period_uom = 'm';
// // //   credit_N->period = 6;
// // //   calc_credit(credit_N);

// // //   credit_N->overpayment = credit_N->overpayment - 4269;
// // //   EXPECT_EQ(credit_N->overpayment <= 0, "FAILED credit_d_4");
// // //   credit_N->month_max = credit_N->month_max - 10711;
// // //   EXPECT_EQ(credit_N->month_max <= 0, "FAILED credit_d_5");
// // // }
// // // 



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}