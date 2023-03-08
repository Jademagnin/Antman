##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile for antman project
##

CC	= gcc
OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -L ./lib/my -lmy -I ./include

all:
	make -C ./antman/
	make -C ./giantman/

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./antman/
	make fclean -C ./giantman/
	rm -f ./antman/antman
	rm -f ./giantman/giantman

tests_run:
	clear
	@cd tests && ./unit_tests

unit_tests:
	make re
	make tests_run

cstyle:
	make fclean
	cstyle

re: fclean all
