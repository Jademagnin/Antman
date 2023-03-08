##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile for antman
##

NAME = antman
CC	= gcc
SRC	= src/main.c \
	src/antman.c \
	src/helpers/init.c \
	src/helpers/error.c \
	src/helpers/lzss/encode.c \
	src/helpers/lzss/bit_io.c \
	src/helpers/lzss/buffer_op.c \

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -L ../lib/my -lmy -I ./include -I ../lib/my/include \
	-O2 -Wno-unused-result -fno-builtin-memset -fno-builtin-memcpy

all: $(NAME)
$(NAME):
	make -C ../lib/my/
	cp ../lib/my/include/my.h ./include/
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C ../lib/my/

re: fclean all
