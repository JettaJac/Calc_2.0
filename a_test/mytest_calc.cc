#include <gtest/gtest.h>

#include <array>
#include <vector>

#include "../a_controller/controller.h"
// gcc -g -coverage mytest_calc.c SmartCalc.c -o test.out -I -l -lcheck

using namespace std;
using namespace s21;
Controller model1;
const double ERC = 0.00000001;
class Test2 : public Model {};

// _________________________________ BEGIN

TEST(Calc, MatematikaSimple) {
  double res = 0;
  int tmp = 1;
  char x[3] = "1";
  string str;

  Test2 TTT;
  TTT.SmartCalc("5", x, res);

  model1.SmartCalc("5", x, res);
  EXPECT_EQ(res == 5, true);

  str = "0.345+5";
  model1.SmartCalc(str, x, res);
  EXPECT_EQ(res == 5.345, true);

  model1.SmartCalc("5+7-3-2", x, res);
  EXPECT_EQ(res == 7, true);

  model1.SmartCalc("5+7-3*2", x, res);
  EXPECT_EQ(res == 6, true);

  model1.SmartCalc("5+7*3-3*2", x, res);
  EXPECT_EQ(res == 20, true);

  model1.SmartCalc("5+7-3/2", x, res);
  EXPECT_EQ(res == 10.5, true);

  model1.SmartCalc("3*(5+6)-2*4-(8*9/3-6)", x, res);
  EXPECT_EQ(res == 7, true);

  model1.SmartCalc("3*(5+6)-2*4-(8*9/3-6)/7", x, res);
  EXPECT_EQ(res - 22.4285714285714286 <= ERC, true);

  model1.SmartCalc("3*(5+6)-2*4-(8*9/3-6)/7-2*3", x, res);
  EXPECT_EQ(res - 16.4285714285714286 <= ERC, true);

  model1.SmartCalc("3-(5+6)*(2+4)-8*9-6/7-2*3", x, res);
  EXPECT_EQ(res - (-141.8571428571428571) <= ERC, true);

  tmp = model1.SmartCalc("(5+4-2*5)/(5-5)", x, res);
  EXPECT_EQ(tmp, -2);

  tmp = model1.SmartCalc("(4+10)/0*2+1", x, res);
  EXPECT_EQ(tmp, -2);

  model1.SmartCalc("80/2", x, res);
  EXPECT_EQ(res - 40 <= ERC, true);

  model1.SmartCalc("80/(2-10)", x, res);
  EXPECT_EQ(res - (-10) <= ERC, true);

  model1.SmartCalc("80/(-10)", x, res);
  EXPECT_EQ(res - (-8) <= ERC, true);

  model1.SmartCalc("-80/(-10)", x, res);
  EXPECT_EQ(res - 8 <= ERC, true);

  model1.SmartCalc("-(5+1)", x, res);
  EXPECT_EQ(res - (-6) <= ERC, true);

  model1.SmartCalc("-(-(5+2)*4)", x, res);
  EXPECT_EQ(res - 28 <= ERC, true);

  model1.SmartCalc("-(+(5+2)*4)", x, res);
  EXPECT_EQ(res - (-28) <= ERC, true);

  model1.SmartCalc("5", x, res);
  EXPECT_EQ(res - 5 <= ERC, true);

  model1.SmartCalc("-5", x, res);
  EXPECT_EQ(res - (-5) <= ERC, true);

  model1.SmartCalc("sin(cos(log(5^2)))", x, res);

  EXPECT_EQ(res - 0.17115002489 <= ERC, true);

  model1.SmartCalc(
      "sin(cos(tan(acos(asin(atan(log(1*ln(sqrt(5mod3^(-2)+x)))))))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.742174 <= ERC, true);

  // 0.71188622115482
  model1.SmartCalc("sin(cos(tan(acos(1))))", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.8414709848 <= ERC, true);

  model1.SmartCalc("sin(2)", x, res);
  cout << res << endl;
  EXPECT_EQ(res - 0.90929742682 <= ERC, true);

  model1.SmartCalc("sqrt((-2)*(-2))", x, res);
  EXPECT_EQ(res == 2, true);
}

TEST(Calc, MatematikaTrig_1) {
  double res = 999;
  char x[3] = "46";

  model1.SmartCalc("sin(5)", x, res);
  res = res - (-0.95892427466);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("cos(5)", x, res);
  res = res - (0.28366218546);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("cos(45)", x, res);
  res = res - (0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("-cos(45)+sin(67)", x, res);
  res = res - (0.98687716056);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("-cos(45)", x, res);
  res = res - (-0.52532198881);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("1-cos(45)", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("1-(-cos(45))", x, res);
  res = res - (1.52532198882);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("1-(-(-cos(45)))", x, res);
  res = res - (0.47467801118);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("acos(0.5)", x, res);
  res = res - (1.0471975511966);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("asin(0.5)", x, res);
  res = res - (0.523598775598299);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("atan(x)", x, res);
  res = res - (1.5490606199531);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("sin(x)", x, res);
  res = res - (0.90178834764881);
  EXPECT_EQ(res <= ERC, true);
  cout << "TEST_ " << res << endl;
}

TEST(Calc, MatematikaLog) {
  double res = 999;
  char x[3] = "1";

  model1.SmartCalc("log(5)", x, res);
  res = res - (0.6989700043360189);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("ln(5)", x, res);
  res = res - (1.6094379124341004);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("log(45)", x, res);
  res = res - (1.6532125137753437);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("ln(45)+log(67)", x, res);
  res = res - (5.6327372924711462);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("(-log(45)+sin(67))-(ln(10)+log(56))", x, res);
  res = res - (-6.55950561275);
  EXPECT_EQ(res <= ERC, true);

  model1.SmartCalc("-ln(45-20)", x, res);
  res = res - (-3.2188758248682007);
  EXPECT_EQ(res <= ERC, true);
}

TEST(Calc, MatematikaMod) {
  double res = 999;
  char x[3] = "1";

  model1.SmartCalc("45mod4", x, res);
  EXPECT_EQ(res == 1, true);

  model1.SmartCalc("(2+3*5)mod(3*2)", x, res);
  EXPECT_EQ(res == 5, true);

  model1.SmartCalc("(2^2^2)mod3", x, res);
  EXPECT_EQ(res == 1, true);

  model1.SmartCalc("5mod2+33mod6*6", x, res);
  EXPECT_EQ(res == 19, true);

  model1.SmartCalc("(-7)mod(7mod4)", x, res);
  EXPECT_EQ(res == -1, true);
}

TEST(Calc, MatematikaPow) {
  double res = 999;
  char x[3] = "1";

  model1.SmartCalc("2^(-1+1*3)", x, res);
  EXPECT_EQ(res == 4, true);

  model1.SmartCalc("2^(-1+1*3)+5*4", x, res);
  EXPECT_EQ(res == 24, true);

  model1.SmartCalc("2^(-2)", x, res);
  EXPECT_EQ(res == 0.25, true);

  model1.SmartCalc("(-3^(-3))", x, res);
  res = res - (-0.037037037037037);
  EXPECT_EQ(res <= ERC, true);
}

TEST(Calc, MatematikaX) {
  double res = 999;
  char x[3] = "5";

  model1.SmartCalc("x^2+3*x", x, res);
  EXPECT_EQ(res == 40, true);

  model1.SmartCalc("3*x", x, res);
  EXPECT_EQ(res == 15, true);

  model1.SmartCalc("x*3", x, res);
  EXPECT_EQ(res == 15, true);

  model1.SmartCalc("3*x+2*x", x, res);
  EXPECT_EQ(res == 25, true);

  model1.SmartCalc("3*x+2+x", x, res);
  EXPECT_EQ(res == 22, true);

  model1.SmartCalc("-x", x, res);
  EXPECT_EQ(res == -5, true);

  char x2[3] = "-5";

  model1.SmartCalc("x^2+3*x", x2, res);
  EXPECT_EQ(res == 10, true);

  model1.SmartCalc("3*x", x2, res);
  EXPECT_EQ(res == -15, true);

  model1.SmartCalc("x*3", x2, res);
  EXPECT_EQ(res == -15, true);

  model1.SmartCalc("3*x+2*x", x2, res);
  EXPECT_EQ(res == -25, true);

  model1.SmartCalc("3*x+2+x", x2, res);
  EXPECT_EQ(res == -18, true);

  model1.SmartCalc("-x", x2, res);
  EXPECT_EQ(res == 5, true);
}

TEST(Calc, MatematikaErr) {
  double res = 999;
  char x[3] = "-1";

  EXPECT_EQ(model1.SmartCalc("y", x, res) == -1, true);
  EXPECT_EQ(model1.SmartCalc("", "", res) == -1, true);
  EXPECT_EQ(model1.SmartCalc("-cos(45)sin(67)", x, res) == -1, true);
  EXPECT_EQ(model1.SmartCalc("1 - cos(45)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("-cos(45)+sin(-67)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("-cos(+45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("-ln(45)+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("5mod4+sin(67)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("2^2^2", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("2^2^", x, res) == -1, true);
  EXPECT_EQ(model1.SmartCalc("2^(-1+1*3)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("2^(-1+1*3)+5*4", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("log(-45)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("6mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("(-5)mod(-4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("(-5)mod(6mod4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("(2+3*5)mod(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("atan(3*2)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("asin(5)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("asin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("acos(5)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("acos(0.5)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("atan(5)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("sin(0.4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("cos(5)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("tan(5)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("ln(-5)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("log(-5)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("10mod(5-5)", x, res) == -2, true);
  EXPECT_EQ(model1.SmartCalc("10mod(-x)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("10modx", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("xmod5", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("(-x)mod5", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("sqrt(x)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("sqrt(-1)", x, res) == -3, true);
  EXPECT_EQ(model1.SmartCalc("sqrt(4)", x, res) == 0, true);
  EXPECT_EQ(model1.SmartCalc("(5^-3)", x, res) == -1, true);
}

TEST(Calc, MatematikaExp) {
  std::string str_x = "1";
  double res = 999;

  EXPECT_EQ(model1.SmartCalc("(1+2)e+2", str_x, res), -1);  // потом обработать
  EXPECT_EQ(model1.SmartCalc("(-2)e+6", str_x, res), -1);  // потом обработать
  EXPECT_EQ(model1.SmartCalc("sin(x)e+2", str_x, res),
            -1);  // потом обработать
  EXPECT_EQ(model1.SmartCalc("(-2)e+sin(5)", str_x, res),
            -1);  // потом обработать
  EXPECT_EQ(model1.SmartCalc("2e+(6+1)", str_x, res), -1);  // потом обработать
  EXPECT_EQ(model1.SmartCalc("xe+x", str_x, res), 0);
  EXPECT_EQ(res == 10, true);
  EXPECT_EQ(model1.SmartCalc("xe+4", str_x, res), 0);
  EXPECT_EQ(res == 10000, true);
  EXPECT_EQ(model1.SmartCalc("65e+x", str_x, res), 0);
  EXPECT_EQ(res == 650, true);
  EXPECT_EQ(model1.SmartCalc("65e+4", str_x, res), 0);
  EXPECT_EQ(res == 650000, true);
  EXPECT_EQ(model1.SmartCalc("0.5e+5", str_x, res), 0);
  EXPECT_EQ(res == 50000, true);
  EXPECT_EQ(model1.SmartCalc("-1.5e+5", str_x, res), 0);
  EXPECT_EQ(res == -150000, true);
  EXPECT_EQ(model1.SmartCalc("+0.5e+6", str_x, res), 0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1.SmartCalc("0.5e-6", str_x, res), 0);
  EXPECT_EQ(res == 5e-07, true);
  EXPECT_EQ(model1.SmartCalc("0.5E+6", str_x, res), 0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1.SmartCalc("0.5E-2", str_x, res), 0);
  EXPECT_EQ(res == 0.005, true);
  EXPECT_EQ(model1.SmartCalc("0.5 e+6", str_x, res), 0);
  EXPECT_EQ(res == 500000, true);
  EXPECT_EQ(model1.SmartCalc("0.5e+6+2", str_x, res), 0);
  EXPECT_EQ(res == 500002, true);
  EXPECT_EQ(model1.SmartCalc("0.5e+2*4", str_x, res), 0);
  EXPECT_EQ(res == 200, true);
  EXPECT_EQ(model1.SmartCalc("0.5e-3*4", str_x, res), 0);
  EXPECT_EQ(res == 0.002, true);
}

// TEST(Calc, PrintStack) {
//   std::list<Model::Stack_t2_> stack_N;
//   Model::Stack_t2_ current;
//   current.data = "1";
//   current.type = 9;
//   stack_N.push_back(current);

//   current.data = "+";
//   current.type = 1;
//   stack_N.push_back(current);

//   current.data = "3";
//   current.type = 9;
//   stack_N.push_back(current);

//   model1.Printstack(stack_N);
// }

TEST(Calc, credit_calc) {
  CreditM::Credit_t credit_N;
  credit_N.type = 1;
  credit_N.total_credit = 60000;
  credit_N.period = 6;
  credit_N.period_uom = 'm';  // y - year, m - month
  credit_N.percent_rate = 24;
  credit_N.overpayment = 0.0;
  credit_N.month_min = 0.0;
  credit_N.month_max = 0.0;

  model1.CalcCreditC(credit_N);
  EXPECT_EQ(credit_N.overpayment == 4200, true);
  EXPECT_EQ(credit_N.month_max == 11200, true);
  EXPECT_EQ(credit_N.month_min == 10200, true);

  credit_N.period_uom = 'y';
  credit_N.period = 0.5;
  model1.CalcCreditC(credit_N);

  credit_N.overpayment = credit_N.overpayment - 4200;
  EXPECT_EQ(credit_N.overpayment <= 0, true);
  credit_N.month_max = credit_N.month_max - 10120;
  EXPECT_EQ(credit_N.month_max <= 0, true);

  credit_N.type = 2;
  model1.CalcCreditC(credit_N);

  credit_N.overpayment = credit_N.overpayment - 4400;
  EXPECT_EQ(credit_N.overpayment <= 0, true);
  credit_N.month_max = credit_N.month_max - 10740;
  EXPECT_EQ(credit_N.month_max <= 0, true);
  credit_N.month_min = credit_N.month_min - 10740;
  EXPECT_EQ(credit_N.month_min <= 0, true);

  credit_N.period_uom = 'm';
  credit_N.period = 6;
  model1.CalcCreditC(credit_N);

  credit_N.overpayment = credit_N.overpayment - 4269;
  EXPECT_EQ(credit_N.overpayment <= 0, true);
  credit_N.month_max = credit_N.month_max - 10711;
  EXPECT_EQ(credit_N.month_max <= 0, true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}