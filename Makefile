##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	= 	src/main.c	\

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc -Wextra -Wall -Werror -g3 -no-pie

NAME	=	lem_in

LIB_NAME	=	libmy.a

FLAGS	=	-L./lib/my -lmy

CFLAGS	=	-I./include

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f lib/my/$(LIB_NAME)
	rm -f $(NAME)

re:	fclean all
