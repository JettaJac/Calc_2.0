#ifndef SRC_MODEL_S21_SMARTCALC_H_
#define SRC_MODEL_S21_SMARTCALC_H_


namespace s21 {

    //// Error code
#define TRUE 0
#define FAIL -1
#define ZERO -2
#define EFUC -3  // неправильно введены значения в функциях

// #define size_t
// #define STACK_OVERFLOW 10
#define STACK_MAX_SIZE 100
#define INIT_SIZE 10

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102
// typedef double T;

#define SIZE 300
#define SIZE_N 100

class SmartCalc{
    public:
    int s21_calc(char *str, char *str_x, double *result); // main function

    private:
    typedef struct stack_tag {
    char data[STACK_MAX_SIZE][SIZE];
    double number[STACK_MAX_SIZE];
    int pri[STACK_MAX_SIZE];  // prioritet
    char x[SIZE];
    size_t size;
    } Stack_t; // возможно не надо Stck_t

    typedef struct {
    char str[SIZE];
    char val[SIZE];
    int tmp;
    char data_before[SIZE];
    char data_after[SIZE];
    int symbol_after;
    int symbol_before;
    int symbol;
    int brackets;
    } flags;





}







}
#endif  // SRC_MODEL_S21_SMARTCALC_H_