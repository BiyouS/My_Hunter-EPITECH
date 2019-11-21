##
## EPITECH PROJECT, 2019
## d10
## File description:
## Compilation File
##

SRC =	my_getnbr.c	\
	my_put_nbr.c	\
	my_putchar.c	\
	my_putstr.c	\
	my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	libmy.a

all:	 $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o
	cp $(NAME) ../.
	mkdir -p ../../include
	cp my.h ../../include/my.h
clean:
	rm -f $(OBJ)
fclean:
	make clean
	rm -f ../$(NAME)
	rm -f $(NAME)
re:
	make fclean
	rm -f ../$(NAME)
	rm -f ../../include/my.h
