#include <gtest/gtest.h>

// #include "credit.c"
// #include "credit.h"
#include "s21_calc.h"
#include <array>
#include <vector>
// gcc -g -coverage mytest_calc.c s21_calc.c -o test.out -I -l -lcheck

using namespace std;
using namespace s21;
// Model model;
Model *model1;

// Test_t  test;
class MyTest : public ::testing::Test, private s21::Model {
  public:
  // void SetUp() override {
  //       // Инициализация объекта класса для тестирования
  //       model2 = new Model();
  //   }

  //   void TearDown() override {
  //       // Освобождение ресурсов
  //       delete model2;
  //   }
  Model *test;
  
  Model model2;

friend class Model;

};




// TEST(MyTest, matematika_mod55) {
//   Model  model;
//   double res = 999;
//   char x[3] = "1";
//   // model.s21_calc("45mod4", x, res);
//   // test.s21_calc("45mod4", x, res);
//   // model.s21_calc("45mod4", x, res);
//   EXPECT_EQ(res == 1, true);
// }



// TEST(MyTest, TestName0) {
//     // Здесь выполняются проверки и ассерты
//     std::cout << std::endl;
//     // s21::MyTest
//     double num = {0};
//     char str1[] = "1.345";
//     model.number(str1,  num);
//     model2.s21_calc;
//     // ->number(str1,  num);

//     // model.pop_push();
//     // s21::Model:;
//     ASSERT_EQ(2 + 2, 4);
// }

// MyTest test_2;
// class Test_t  : private Model 
// {
//   TEST(NumberTest, Double){
//     double num = {0};
//     char str1[] = "1.345";
//     number(str1,  num);
//     EXPECT_EQ(num, 1.345);
//   };

// };
// Test_t  test;






// _________________________________ BEGIN


// //// Тест для double number
// TEST_F(NumberTest, Double) {
//   double num = {0};
//   char str1[] = "1.345";
//   s21::Model::number(str1,  num);
//   EXPECT_EQ(num, 1.345);

//   char str2[] = "0.345";
//   number(str2,  num);
//   EXPECT_EQ(num, 0.345);

//   char str3[] = "1000.345";
//   number(str3,  num);
//   EXPECT_EQ(num, 1000.345);

//   char str4[] = "234567890.34554569090984";
//   number(str4,  num);
//   EXPECT_EQ(num, 234567890.34554569090984);

//   char str5[] = "10.3000405";
//   number(str5,  num);
//   EXPECT_EQ(num, 10.3000405);

//   char str6[] = "0";
//   number(str6,  num);
//   EXPECT_EQ(num, 0);

//   char str7[] = "1000";
//   number(str7,  num);
//   EXPECT_EQ(num, 1000);

//   char str8[] = "0.0300";
//   number(str8,  num);
//   EXPECT_EQ(num, 0.0300);
// }

// // Тест для нормального ввода
// TEST(NumberTest, ValidInput) {
//     char validStr[] = "123.45";
//     double result;
//     int err = number(validStr, result);
//     EXPECT_EQ(err, 0);
//     EXPECT_DOUBLE_EQ(result, 123.45);
// }

// // Тест для некорректного ввода (не числовая строка)
// TEST(NumberTest, InvalidInput) {
//     char invalidStr[] = "abc";
//     double result;
//     int err = number(invalidStr, result);
//     EXPECT_EQ(err, -1); // Ожидаем ошибку
// }

// // // Тест для крайнего значения (например, DBL_MAX)
// // TEST(NumberTest, MaxDoubleValue) {
// //     char maxStr[] = "1.7976931348623157e+308"; // Максимальное значение для double
// //     double result;
// //     int err = number(maxStr, result);
// //     EXPECT_EQ(err, 0);
// //     EXPECT_DOUBLE_EQ(result, DBL_MAX);
// // }


// TEST(NumberTest, NumberErr) {
//   double num = {0};

//   EXPECT_EQ(number("02.345",  num), -1);
//   EXPECT_EQ(number("1.34.5",  num), -1);
//   EXPECT_EQ(number("1,345",  num), -1);
//   EXPECT_EQ(number("s1,345",  num), -1);
//   EXPECT_EQ(number("1,h345",  num), -1);
//   EXPECT_EQ(number("1,-345",  num), -1);
//   EXPECT_EQ(number("(0,3459587474736",  num), -1);
//   EXPECT_EQ(number("0,34595874747.36",  num), -1);
//   EXPECT_EQ(number("0,34595874747+36",  num), -1);
//   EXPECT_EQ(number("0.34595874747+36",  num), -1);
//   EXPECT_EQ(number("0.34595874747sin36",  num), -1);
//   EXPECT_EQ(number("sin0.34595874747",  num), -1);
//   EXPECT_EQ(number("00.34595874747",  num), -1);
//   EXPECT_EQ(number("00..34595874747",  num), -1);
//   EXPECT_EQ(number("..34595874747",  num), -1);
//   EXPECT_EQ(number(".34595874747",  num), 0);
//   EXPECT_EQ(number("00",  num), -1);
//   EXPECT_EQ(number("l8",  num), -1);
//   EXPECT_EQ(number("0200",  num), -1);
//   EXPECT_EQ(number("09",  num), -1);
//   EXPECT_EQ(number("9.",  num), -1);
//   EXPECT_EQ(number(".2",  num), 0);
//   EXPECT_EQ(number("-3",  num), 0);
// }

// TEST(CheckNumber, Err) {
//   // std::list<Stack_t2> stack_N;
//   // // Stack_t stack_N[1] = {0};
//   // double value[3] = {0.7};

//   // push_num(stack_N, value, 1);
//   // push_num(stack_N, value, 1);

//   EXPECT_EQ(check_number("10"), 0);
//   EXPECT_EQ(check_number("01"), -1);
//   EXPECT_EQ(check_number("01."), -1);
//   EXPECT_EQ(check_number("00."), -1);
//   EXPECT_EQ(check_number("0.001"), 0);
//   EXPECT_EQ(check_number("001"), -1);
//   EXPECT_EQ(check_number("100000.00001"), 0);
//   EXPECT_EQ(check_number("0.0000000001"), 0);
//   EXPECT_EQ(check_number("00"), -1);
//   EXPECT_EQ(check_number("00.."), -1);
//   EXPECT_EQ(check_number("0.0.1"), -1);
//   EXPECT_EQ(check_number("00.1"), -1);
//   EXPECT_EQ(check_number("0.1"), 0);
//   EXPECT_EQ(check_number("-0.1"), 0);
//   EXPECT_EQ(check_number("-3"), 0);
//   EXPECT_EQ(check_number("-0.0001"), 0);
//   EXPECT_EQ(check_number("-0.000000"), 0);
//   EXPECT_EQ(check_number("0.000000"), 0);
// }

// TEST(Calc, parser_sin) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   EXPECT_EQ(parser("*5+12", stack_N, str_x), -1);
//   EXPECT_EQ(parser("^5+12", stack_N, str_x), -1);
//   EXPECT_EQ(parser("5+12s", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin(", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin()", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin(5/)", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin(4.5)+cos(5", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin(4.5)+cos(5+4", stack_N, str_x), -1);
//   EXPECT_EQ(parser("/sin(5)", stack_N, str_x), -1);
//   EXPECT_EQ(parser("sin4", stack_N, str_x), -1);
//   EXPECT_EQ(parser("4sin(45)", stack_N, str_x), -1);
//   EXPECT_EQ(parser("1+sib(4)", stack_N, str_x), -1);
//   EXPECT_EQ(parser("1+sin(4)", stack_N, str_x), 0);
//   EXPECT_EQ(parser("-cos(4*2)+sin(4)", stack_N, str_x), 0);
// }


// TEST(Calc, parser_cos) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "=cos";
//   char str2[] = "cos(";
//   char str3[] = "cos()";
//   char str4[] = "cos(5/)";
//   char str5[] = "cos(4.5)+cos(5";
//   char str6[] = "*cos(5)";
//   char str7[] = "cosn4";
//   char str8[] = "4cos(45)";
//   char str9[] = "1+ces(5)";
//   char str10[] = "1+cos(4)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
// }


// TEST(Calc, parser_tan) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";


//   char str1[] = "=tan";
//   char str2[] = "tan(";
//   char str3[] = "tan()";
//   char str4[] = "tan(5/)";
//   char str5[] = "tan(4.5)+tan(5";
//   char str6[] = "*tan(5)";
//   char str7[] = "tann4";
//   char str8[] = "4tan(45)";
//   char str9[] = "1+tas(8)";
//   char str10[] = "1+tan(4)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
// }


// TEST(Calc, parser_asin) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "5+12s";
//   char str2[] = "asin(";
//   char str3[] = "asin()";
//   char str4[] = "asin(5/)";
//   char str5[] = "asin(4.5)+cos(5";
//   char str6[] = "*asin(5)";
//   char str7[] = "asin4";
//   char str8[] = "4asin(45)";
//   char str9[] = "1+asik(4)";
//   char str10[] = "1+asin(4)";
//   char str11[] = "asin(0.2)";
//   char str12[] = "asin(8)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
//   EXPECT_EQ(parser(str11, stack_N, str_x), 0);
//   EXPECT_EQ(parser(str12, stack_N, str_x), 0);
// }


// TEST(Calc, parser_acos) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "=acos";
//   char str2[] = "acos(";
//   char str3[] = "acos()";
//   char str4[] = "acos(5/)";
//   char str5[] = "acos(4.5)+acos(5";
//   char str6[] = "/acos(5)";
//   char str7[] = "acosn4";
//   char str8[] = "4acos(45)";
//   char str9[] = "1+aces(5)";
//   char str10[] = "acos(8)";
//   char str11[] = "acos(8)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
//   EXPECT_EQ(parser(str11, stack_N, str_x), 0);
// }


// TEST(Calc, parser_atan) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "=atan";
//   char str2[] = "atan(";
//   char str3[] = "atan()";
//   char str4[] = "atan(5/)";
//   char str5[] = "atan(4.5)+atan(5";
//   char str6[] = "+atan(5x)";
//   char str7[] = "atann4";
//   char str8[] = "4atan(45)";
//   char str9[] = "1+atas(8)";
//   char str10[] = "atan(8)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
// }


// TEST(Calc, parser_sqrt) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "+sqrt";
//   char str2[] = "sqrt(";
//   char str3[] = "sqrt()";
//   char str4[] = "sqrt(5/)";
//   char str5[] = "sqrtn(4.5)";
//   char str6[] = "*sqrt(5)";
//   char str7[] = "sqrt4";
//   char str8[] = "4sqrt(45)";
//   char str9[] = "1+sqrt(8)";
//   char str10[] = "1+(-sqrt(8))";
//   char str11[] = "sqrt(-4)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), 0);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
//   EXPECT_EQ(parser(str11, stack_N, str_x), 0);
// }


// TEST(Calc, parser_log) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "+log";
//   char str2[] = "log(";
//   char str3[] = "log()";
//   char str4[] = "log(5/)";
//   char str5[] = "logn(4.5)";
//   char str6[] = "/log(5)";
//   char str7[] = "log4";
//   char str8[] = "4log(45)";
//   char str9[] = "1+logt(8)";
//   char str10[] = "log(5)";
//   char str11[] = "ln(34)+log(5)";

//   EXPECT_EQ(parser(str1, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x),  -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x),  0);
//   EXPECT_EQ(parser(str11, stack_N, str_x),  0);
// }


// TEST(Calc, parser_ln) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";
//   char str1[] = "+ln";
//   char str2[] = "ln(";
//   char str3[] = "ln()";
//   char str4[] = "ln(5/)";
//   char str5[] = "lnn(4.5)";
//   char str6[] = "+ln(5i)";
//   char str7[] = "ln4";
//   char str8[] = "4ln(45)";
//   char str9[] = "1+lnt(8)";
//   char str10[] = "ln(5)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), 0);
// }


// TEST(Calc, parser_mod) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   EXPECT_EQ(parser("+mod", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("mod(", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5mod()", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("mod(5/)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("modn4", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("+mod5)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("mod4", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("4mod(45)", stack_N, str_x),  0);
//   EXPECT_EQ(parser("1+modt(8)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("1mod3", stack_N, str_x),  0);
//   EXPECT_EQ(parser("(3+4)mod(3+1)", stack_N, str_x),  0);
//   EXPECT_EQ(parser("7mod3", stack_N, str_x),  0);
// }


// TEST(Calc, parser_x) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   EXPECT_EQ(parser("+x^", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("x(", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("mx*5", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5x()", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("sinx", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("x+", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5+x", stack_N, str_x),  0);
//   EXPECT_EQ(parser("5*x", stack_N, str_x),  0);
//   EXPECT_EQ(parser("5x", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5(-x)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5*(-x)", stack_N, str_x),  0);
// }


// TEST(Calc, parser_pow) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   EXPECT_EQ(parser("x^)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5^", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("^", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("^5", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("sin(^5)", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("^+", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5^2", stack_N, str_x),  0);
//   EXPECT_EQ(parser("5^(2+1)", stack_N, str_x),  0);
//   EXPECT_EQ(parser("2^2^2^2", stack_N, str_x),  0);
//   EXPECT_EQ(parser("5^+4", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5^-4", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("5^(-4+cos(5))", stack_N, str_x),  0);
//   EXPECT_EQ(parser("2^(-1+1*3)", stack_N, str_x),  0);
// }

// TEST(Calc, parser_exp_err) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   EXPECT_EQ(parser("0.5e+6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("-0.5e+6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("+0.5e+6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5e-6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5E+6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5E-6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5k+6", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("0.5e+6e", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("0.5e+6E", stack_N, str_x),  -1);
//   EXPECT_EQ(parser("0.5 e+6", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5e+6+2", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5e+6*4", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5e-3*4", stack_N, str_x),  0);
//   EXPECT_EQ(parser("0.5ee-3*4", stack_N, str_x),  -1);
// }


// TEST(Calc, parser_space2) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";
//   EXPECT_EQ(parser("( 5   )", stack_N, str_x), 0);
//   EXPECT_EQ(parser(" 5 ", stack_N, str_x), 0);
//   EXPECT_EQ(parser("(cos(6 4))", stack_N, str_x), 0);
//   EXPECT_EQ(parser("(cos(6) + sin( 5 ))", stack_N, str_x), 0);
//   EXPECT_EQ(parser("sin( 5 )", stack_N, str_x), 0);
//   EXPECT_EQ(parser("4 + 3", stack_N, str_x), 0);
//   EXPECT_EQ(parser("(sin( 1 * 2 * 38 + 1))", stack_N, str_x), 0);
//   EXPECT_EQ(parser("0.5 e + 6", stack_N, str_x), 0);  
// }


TEST(Calc, znak_1) {
  double num = 0;
  char x[10] = "2";
  // Model *model;
  // MyTest *test;
  // test->s21_calc->
  model1->s21_calc("-(5+6)", x, num);
  // model->s21_calc("-(5+6)", x, num);
  EXPECT_EQ(num,  -11);
}


// TEST(Calc, znak_err) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "5+*6";
//   char str2[] = "55+";
//   char str3[] = "+-6";
//   char str4[] = "+";
//   char str5[] = "-";
//   char str6[] = "*";
//   char str7[] = "/";
//   char str8[] = "-/8";
//   char str9[] = "(sin(1*2*38+))";
//   char str10[] = "/5";
//   char str11[] = "+(*5)";
//   char str12[] = "(5+-5)";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str9, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str10, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str11, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str12, stack_N, str_x), -1);
// }


// TEST(Calc, brackets_err) {
//   std::list<Stack_t2> stack_N;
//   std::string str_x = "1";

//   char str1[] = "sin(2*(2*2)";
//   char str2[] = "()sin(1*2*3(8)";
//   char str3[] = "((sin(1*2*3(8))";
//   char str4[] = "(sin(1*2*38+))";
//   char str5[] = "(/5)";
//   char str6[] = "(*5)";
//   char str7[] = "(5*)";
//   char str8[] = "1+)*5-4(";

//   EXPECT_EQ(parser(str1, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str2, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str3, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str4, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str5, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str6, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str7, stack_N, str_x), -1);
//   EXPECT_EQ(parser(str8, stack_N, str_x), -1);
// }


// // TEST(Calc, previous_next_ch) { //работает
// //   int tmp = 1;
// //   string num;
// //   char str[] = "0.345";

// //   prev_next_ch(1, str, 0, num);
// //   EXPECT_EQ(num[0] == "0", 0);

// //   prev_next_ch(1, str, 1, num);
// //   EXPECT_EQ(num[0] == ".", 0);

// //   tmp = prev_next_ch(1, str, -1, num);
// //   EXPECT_EQ(tmp, -1);

// //   tmp = prev_next_ch(1, str, 5, num);
// //   EXPECT_EQ(tmp, -1);
// // }


TEST(Calc, matematika_simple) {
  double res = 0;
  int tmp = 1;
  char x[3] = "1";
  string str;

  model1->s21_calc("5", x, res);  
  EXPECT_EQ(res == 5, true);

  str = "0.345+5";
  model1->s21_calc(str, x, res);
  EXPECT_EQ(res == 5.345, true);

  model1->s21_calc("5+7-3-2", x, res);
  EXPECT_EQ(res == 7, true);

  model1->s21_calc("5+7-3*2", x, res);
  EXPECT_EQ(res == 6, true);

  model1->s21_calc("5+7*3-3*2", x, res);
  EXPECT_EQ(res == 20, true);

  model1->s21_calc("5+7-3/2", x, res);
  EXPECT_EQ(res == 10.5, true);

  model1->s21_calc("3*(5+6)-2*4-(8*9/3-6)", x, res);
  EXPECT_EQ(res == 7, true);

  model1->s21_calc("3*(5+6)-2*4-(8*9/3-6)/7", x, res);
  EXPECT_EQ(res - 22.4285714285714286 <= ERC, true);

  model1->s21_calc("3*(5+6)-2*4-(8*9/3-6)/7-2*3", x, res);
  EXPECT_EQ(res - 16.4285714285714286 <= ERC, true);

  model1->s21_calc("3-(5+6)*(2+4)-8*9-6/7-2*3", x, res);
  EXPECT_EQ(res -(-141.8571428571428571) <= ERC, true);

  tmp = model1->s21_calc("(5+4-2*5)/(5-5)", x, res);
  EXPECT_EQ(tmp, -2);

  tmp = model1->s21_calc("(4+10)/0*2+1", x, res);
  EXPECT_EQ(tmp, -2);

  model1->s21_calc("80/2", x, res);
  EXPECT_EQ(res - 40 <= ERC, true);

  model1->s21_calc("80/(2-10)", x, res);
  EXPECT_EQ(res - (-10) <= ERC, true);

  model1->s21_calc("80/(-10)", x, res);
  EXPECT_EQ(res - (-8) <= ERC, true);

  model1->s21_calc("-80/(-10)", x, res);
  EXPECT_EQ(res - 8 <= ERC, true);

  model1->s21_calc("-(5+1)", x, res);
  EXPECT_EQ(res - (-6) <= ERC, true);

  model1->s21_calc("-(-(5+2)*4)", x, res);
  EXPECT_EQ(res - 28 <= ERC, true);

  model1->s21_calc("-(+(5+2)*4)", x, res);
  EXPECT_EQ(res - (-28) <= ERC, true);

  model1->s21_calc("5", x, res);
  EXPECT_EQ(res - 5 <= ERC, true);

  model1->s21_calc("-5", x, res);
  EXPECT_EQ(res - (-5) <= ERC, true);

  model1->s21_calc("sin(cos(log(5^2)))", x, res);
  
  EXPECT_EQ(res - 0.17115002489 <= ERC, true);

  model1->s21_calc("sin(cos(tan(acos(asin(atan(log(1*ln(sqrt(5mod3^(-2)+x)))))))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.742174 <= ERC, true);
  
  // 0.71188622115482
  model1->s21_calc("sin(cos(tan(acos(1))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.8414709848 <= ERC, true);

  model1->s21_calc("sin(2)", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.90929742682 <= ERC, true);

  model1->s21_calc("sqrt((-2)*(-2))", x, res);
  EXPECT_EQ(res == 2, true);  
}


TEST(Calc, matematika_trig_1) {
  double res = 999;
  char x[3] = "46";

  model1->s21_calc("sin(5)", x, res);
  res = res - (-0.95892427466);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("cos(5)", x, res);
  res = res - (0.28366218546);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("cos(45)", x, res);
  res = res - (0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("-cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("-cos(45)", x, res);
  res = res - (-0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("1-cos(45)", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("1-(-cos(45))", x, res);
  res = res - (1.52532198882);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("1-(-(-cos(45)))", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("acos(0.5)", x, res);
  res = res - (1.0471975511966);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("asin(0.5)", x, res);
  res = res - (0.523598775598299);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("atan(x)", x, res);
  res = res - (1.5490606199531);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("sin(x)", x, res);
  res = res - (0.90178834764881);
  EXPECT_EQ(res <= ERC, true);
  cout << "TEST_ " << res << endl;
}


TEST(Calc, matematika_log_1) {
  double res = 999;
  char x[3] = "1";

  model1->s21_calc("log(5)", x, res);
  res = res - (0.6989700043360189);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("ln(5)", x, res);
  res = res - (1.6094379124341004);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("log(45)", x, res);
  res = res - (1.6532125137753437);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("ln(45)+log(67)", x, res);
  res = res - (5.6327372924711462);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("(-log(45)+sin(67))-(ln(10)+log(56))", x, res);
  res = res - (-6.55950561275);
  EXPECT_EQ(res <= ERC, true);

  model1->s21_calc("-ln(45-20)", x, res);
  res = res - (-3.2188758248682007);
  EXPECT_EQ(res <= ERC, true);
}


TEST(Calc, matematika_mod) {
  double res = 999;
  char x[3] = "1";

  model1->s21_calc("45mod4", x, res);
  EXPECT_EQ(res == 1, true);

  model1->s21_calc("(2+3*5)mod(3*2)", x, res);
  EXPECT_EQ(res == 5, true);

  model1->s21_calc("(2^2^2)mod3", x, res);
  EXPECT_EQ(res == 1, true);

  model1->s21_calc("5mod2+33mod6*6", x, res);
  EXPECT_EQ(res == 19, true);

  model1->s21_calc("(-7)mod(7mod4)", x, res);
  EXPECT_EQ(res == -1, true);
 }


TEST(Calc, matematika_pow) {
  double res = 999;
  char x[3] = "1";

  model1->s21_calc("2^(-1+1*3)", x, res);
  EXPECT_EQ(res == 4, true);

  model1->s21_calc("2^(-1+1*3)+5*4", x, res);
  EXPECT_EQ(res == 24, true);

  model1->s21_calc("2^(-2)", x, res);
  EXPECT_EQ(res == 0.25, true);

  model1->s21_calc("(-3^(-3))", x, res);
  res = res - (-0.037037037037037);
  EXPECT_EQ(res <= ERC, true);
}


TEST(Calc, matematika_x) {
  double res = 999;
  char x[3] = "5";

  model1->s21_calc("x^2+3*x", x, res);
  EXPECT_EQ(res == 40, true);

  model1->s21_calc("3*x", x, res);
  EXPECT_EQ(res == 15, true);

  model1->s21_calc("x*3", x, res);
  EXPECT_EQ(res == 15, true);

  model1->s21_calc("3*x+2*x", x, res);
  EXPECT_EQ(res == 25, true);

  model1->s21_calc("3*x+2+x", x, res);
  EXPECT_EQ(res == 22, true);

  model1->s21_calc("-x", x, res);
  EXPECT_EQ(res == -5, true);

  char x2[3] = "-5";

  model1->s21_calc("x^2+3*x", x2, res);
  EXPECT_EQ(res == 10, true);

  model1->s21_calc("3*x", x2, res);
  EXPECT_EQ(res == -15, true);

  model1->s21_calc("x*3", x2, res);
  EXPECT_EQ(res == -15, true);

  model1->s21_calc("3*x+2*x", x2, res);
  EXPECT_EQ(res == -25, true);

  model1->s21_calc("3*x+2+x", x2, res);
  EXPECT_EQ(res == -18, true);

  model1->s21_calc("-x", x2, res);
  EXPECT_EQ(res == 5, true);
}


TEST(Calc, matematika_err) {
  double res = 999;
  char x[3] = "-1";

  EXPECT_EQ(model1->s21_calc("-cos(45)sin(67)", x, res) == -1, true);
  EXPECT_EQ(model1->s21_calc("1 - cos(45)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("-cos(45)+sin(-67)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("-cos(+45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("-ln(45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("5mod4+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("2^2^2", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("2^2^", x, res) == -1, true);
  EXPECT_EQ(model1->s21_calc("2^(-1+1*3)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("2^(-1+1*3)+5*4", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("log(-45)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("6mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("(-5)mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("(-5)mod(6mod4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("(2+3*5)mod(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("atan(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("asin(5)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("asin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("acos(5)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("acos(0.5)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("atan(5)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("sin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("cos(5)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("tan(5)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("ln(-5)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("log(-5)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("10mod(5-5)", x, res) == -2, true);
  EXPECT_EQ(model1->s21_calc("10mod(-x)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("10modx", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("xmod5", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("(-x)mod5", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("sqrt(x)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("sqrt(-1)", x, res) == -3, true);
  EXPECT_EQ(model1->s21_calc("sqrt(4)", x, res) == 0, true);
  EXPECT_EQ(model1->s21_calc("(5^-3)", x, res) == -1, true);
}

TEST(Calc, MatematikaExp) {
  std::string str_x = "1";
  double res = 999;

  EXPECT_EQ(model1->s21_calc("65e+4", str_x, res),  0);
  EXPECT_EQ(res == 650000, true);
  EXPECT_EQ(model1->s21_calc("0.5e+5", str_x, res),  0);
  EXPECT_EQ(res == 50000, true);
  EXPECT_EQ(model1->s21_calc("-1.5e+5", str_x, res),  0);
  EXPECT_EQ(res == -150000, true);
  EXPECT_EQ(model1->s21_calc("+0.5e+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->s21_calc("0.5e-6", str_x, res),  0);
  EXPECT_EQ(res == 5e-07, true);
  EXPECT_EQ(model1->s21_calc("0.5E+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->s21_calc("0.5E-2", str_x, res),  0);
  EXPECT_EQ(res == 0.005, true);
  EXPECT_EQ(model1->s21_calc("0.5 e+6", str_x, res),  0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1->s21_calc("0.5e+6+2", str_x, res),  0);
  EXPECT_EQ(res == 500002, true);
  EXPECT_EQ(model1->s21_calc("0.5e+2*4", str_x, res),  0);
  EXPECT_EQ(res == 200, true);
  EXPECT_EQ(model1->s21_calc("0.5e-3*4", str_x, res),  0);
  EXPECT_EQ(res == 0.002, true);
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