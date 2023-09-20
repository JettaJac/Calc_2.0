.PHONY: all install uninstall clean dist test gcov_report leaks

CXX=g++ 
CC=g++ 
CCXXFLAGS_C=  -Wextra -Wall -Werror #-g -fsanitize=address 
CXXFLAGS=  -lstdc++ -std=c++17
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS= -lgtest -lgtest_main -lpthread
ALL_FLAGS=$(CXXFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
# OS=$(shell uname)
BUILD=../build/
BUILD_QT=$(BUILD)s21_calculator/

# all, install, uninstall, clean, +dvi, dist, test, gcov_report

SRCS = ./a_model/s21_calc.cc ./a_controller/controller.cc ./a_model/credit.cc
OBJS = $(SRCS:.c=.o) 
OBJS2 = $(SRCS:.c=.o) ./a_test/mytest_calc.cc 
OBJS3 = $(SRCS:.c=.o) ./a_test/mytest_calc_full.cc 
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
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_C)  $(SRCS) -c


test2: $(OBJS2)
	$(CXX) $(CHECK_FLAGS) $(OBJS2) -o mytest_calc
	 ./mytest_calc


test: $(OBJS2)
	$(CXX) $(CHECK_FLAGS) $(OBJS2) -o mytest_calc
	 ./mytest_calc

testfull: $(OBJS3)
	$(CC) $(CHECK_FLAGS) $(OBJS3) -o mytest_calc
	 ./mytest_calc	 

main: $(OBJS)	
#	make clean	
	$(CXX) $(OBJS_m) -o s21_calc_2.0
	./s21_calc_2.0
    CK_FORK=no leaks -exclude -s21_calc_2.0 --atExit -- ./s21_calc_2.0  | grep LEAK:	 

install: 
		rm -fr $(BUILD)
		rm -rf $(HOME)/Desktop/s21_Calc.app
		@mkdir -p $(BUILD)
		@mkdir -p $(BUILD_QT)
		#cp ./*/*.cc ./*/*.h  $(BUILD)
		cmake -S  ./a_vier_QT/ -B $(BUILD_QT)
		make -C  $(BUILD_QT)
		cp -r  $(BUILD_QT)s21_Calc.app $(HOME)/Desktop/
		open $(HOME)/Desktop/s21_Calc.app

uninstall:
	rm -fr $(BUILD)
	rm -rf $(HOME)/Desktop/s21_Calc.app

dvi:
#	cd doxygen && ./doxygen Doxyfile && open html/index.html
	cd doxygen && chmod +x doxygen && ./doxygen Doxyfile && open html/index.html

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
	$(CXX) -o $(NAME) $(SRCS) mytest_calc.cc credit.cc $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o $(REPORT_NAME) tests.info
	open report/index.html
	rm $(NAME)
	rm *.gcno *.gcda

check: 
#	CK_FORK=no leaks --atExit -- ./mytest_calc
	cp ../materials/linters/.clang-format .clang-format
	clang-format  -n *.cc
	clang-format  -i *.cc
	clang-format  -n ./*/*.cc ./*/*.h
	clang-format  -i ./*/*.cc ./*/*.h

leaks: test
	 CK_FORK=no leaks --atExit -- ./mytest_calc	

# val:
# #   valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a_test
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
	rm -rf ./a_model/mytest_calc_full
	rm -fr $(BUILD)
	rm -rf $(HOME)/Desktop/s21_Calc.app
	rm -rf ./a_model/s21_calc
	rm -rf ./smart_calc_archive.tgz
	rm -rf ./s21_calc_2.0
	make check
	rm -rf .clang-format
