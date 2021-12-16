#!/bin/sh

make -C ../libft/ fclean && make -C ../libft/
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o ../get_next_line.o -c ../get_next_line.c
clang -Wall -Wextra -Werror -I../ -I../libft/includes -o main.o -c multi_fd.c
clang -o test_gnl main.o ../get_next_line.o -I ../libft/includes -L ../libft/ -lft
#echo BONUS multi fd
#echo ----------------------------------------------------------------------------------------------------------------------------
#./test_gnl
#echo ----------------------------------------------------------------------------------------------------------------------------

echo LEAK check
valgrind --show-leak-kinds=definite ./test_gnl


