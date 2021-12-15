#!/bin/sh

make -C ../libft/ fclean && make -C ../libft/
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o main.o -c basic.c
clang -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft
echo BASIC TESTS
echo ----------------------------------------------------------------------------------------------------------------------------
echo ----"Read and return a line of 8 characters ending by newline included from the standard output"----------
cat 8chars_1.txt | ./test_gnl
echo ----"Read and return two lines of 8 characters ending by newline included from the standard output"----------
cat 8chars_2.txt | ./test_gnl
echo ----"Read and return any number of lines of 8 characters ending by newline included from the standard output"----------
cat 8chars_any.txt | ./test_gnl
echo ----"Read and return a line of 8 characters ending by newline included from a file"----------
./test_gnl "8chars_1.txt"
echo ----"Read and return two lines of 8 characters ending by newline included from a file"----------
./test_gnl "8chars_2.txt"
echo ----"Read and return any number of lines of 8 characters ending by newline included from a file"----------
./test_gnl "8chars_any.txt"
echo ----------------------------------------------------------------------------------------------------------------------------
