#!/bin/sh

make -C ../libft/ fclean && make -C ../libft/
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o main.o -c advanced.c
clang -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft

echo ADVANCED TESTS
echo ----------------------------------------------------------------------------------------------------------------------------
echo ----"Read and return a line of 4 characters ending by newline included from the standard output"----------
cat 4chars_1.txt | ./test_gnl
echo ----"Read and return two lines of 4 characters ending by newline included from the standard output"----------
cat 4chars_2.txt | ./test_gnl
echo ----"Read and return any number of lines of 4 characters ending by newline included from the standard output"----------
cat 4chars_any.txt | ./test_gnl
echo ----"Read and return a line of 4 characters ending by newline included from a file"----------
./test_gnl "4chars_1.txt"
echo ----"Read and return two lines of 4 characters ending by newline included from a file"----------
./test_gnl "4chars_2.txt"
echo ----"Read and return any number of lines of 4 characters ending by newline included from a file"----------
./test_gnl "4chars_any.txt"

clang -Wall -Wextra -Werror -I../ -I../libft/includes -o main.o -c no_newline.c
clang -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft
echo ----"Read and return a line of 4 characters without newline included from a file."----------
./test_gnl "4chars_no_nl.txt"
echo ----"Read and return a line of 8 characters without newline included from a file."----------
./test_gnl "8chars_no_nl.txt"
echo ----"Read and return a line of 16 characters without newline included from a file."----------
./test_gnl "16chars_no_nl.txt"
echo ----"Read and return an empty line from a file and fd is 42."----------
./test_gnl "empty_line.txt"
echo ----------------------------------------------------------------------------------------------------------------------------

