##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compil our project
##

SRCS	=	my_hunter.c		\
		game.c			\
		create_sprite_array.c	\
		global.c		\
		credits.c		\
		duck.c			\
		event_gest.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_hunter

CC	=	gcc

INCLUDE	=	-I ./include/

CFLAGS	+=	-g -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -Wall -Wextra $(INCLUDE)

LIB	=	-L lib/my/ -lmy

all:	mylib $(NAME)

mylib:
	make -C ./lib/my -lmy

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)

clean:
	make clean -C ./lib/my
	rm -f $(OBJS)

fclean:
	make fclean -C ./lib/my
	make clean
	rm -f $(NAME)

re:
	make fclean
	make
