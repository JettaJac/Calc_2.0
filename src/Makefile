.PHONY: all install uninstall clean dist test gcov_report leaks

CCF=g++ #-g -fsanitize=address -lstdc++ -std=c++17 -Wextra -Wall -Werror 
CC=gcc #-g -fsanitize=address
CFLAGS= #-g -fsanitize=address -Wextra -Wall -Werror
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS= -lgtest -lgtest_main -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
# OS=$(shell uname)
BUILD=../build/
BUILD_QT=$(BUILD)s21_calculator/

# all, install, uninstall, clean, +dvi, dist, test, gcov_report

SRCS = s21_calc.cc 
OBJS = $(SRCS:.c=.o) s21_calc.cc 
OBJS2 = $(SRCS:.c=.o) mytest_calc.cc
NAME = s21_calc
NAME2 = test2
REPORT_NAME = report
OBJS_m = $(SRCS:.c=.o) main.cc 

# ifeq ($(OS), Linux)
#   LIBS=-lcheck -lpthread -lrt -lm -lsubunit
#   OPEN_CM=xdg-open
# else
#   LIBS=-lcheck
#   OPEN_CM=open
# endif


all: install

objs: $(SRCS)
	$(CC) $(CFLAGS)  $(SRCS) -c



test: $(OBJS2)
	$(CCF) $(CHECK_FLAGS) $(OBJS2) -o mytest_calc
	 ./mytest_calc

main: $(OBJS)	
#	make clean	
	$(CCF) $(CHECK_FLAGS) $(OBJS_m) -o s21_calc_2.0
	./s21_calc_2.0
    CK_FORK=no leaks -exclude -s21_calc_2.0 --atExit -- ./s21_calc_2.0  | grep LEAK:	 

install: 
		rm -fr $(BUILD)
		rm -rf $(HOME)/Desktop/s21_Calc.app
		@mkdir -p $(BUILD)
		@mkdir -p $(BUILD_QT)
		cp *.c *.h  $(BUILD)
		cmake -S  ./QT_calc/ -B $(BUILD_QT)
		make -C  $(BUILD_QT)
		cp -r  $(BUILD_QT)s21_Calc.app $(HOME)/Desktop/

uninstall:
	rm -fr $(BUILD)
	rm -rf $(HOME)/Desktop/s21_Calc.app

dvi:
	cd doxygen && ./doxygen Doxyfile && open html/index.html

dist: install
	@rm -rf ./smart_calc_archive
	@mkdir -p ./smart_calc_archive/
	@mkdir -p ./smart_calc_archive/html
	# cp -r Makefile *.c *.h smart_calc_archive/
	cp -r  $(BUILD_QT)s21_Calc.app  ./smart_calc_archive/
	cd ./doxygen && cp -r ./doxygen ./smart_calc_archive
	tar -cvzf ./smart_calc_archive.tgz ./smart_calc_archive
	rm -fr ./smart_calc_archive/

gcov_report:
	$(CCF) -o $(NAME) $(SRCS) mytest_calc.c $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o $(REPORT_NAME) tests.info
	open report/src/index.html
	rm $(NAME)
	rm *.gcno *.gcda

check: 
#	CK_FORK=no leaks --atExit -- ./s21_calc
	cp ../materials/linters/.clang-format .clang-format
	clang-format  -n *.c *.h
	clang-format  -i *.c *.h

leaks: test
	 CK_FORK=no leaks --atExit -- ./mytest_calc	

# val:
# #   valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
# 	# leaks --atExit -- ./mytest_calc	

clean:
	rm -rf $(OBJST)
	rm -rf *.o
	rm -rf *.out
	rm -rf *.dSYM
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.a
	rm -rf $(REPORT_NAME)
	rm -rf *.log
	rm -rf mytest_calc
	rm -fr $(BUILD)
	rm -rf $(HOME)/Desktop/s21_Calc.app
	rm -rf s21_calc
	rm -rf ./smart_calc_archive.tgz
	make check
