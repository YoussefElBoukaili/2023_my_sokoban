##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC      =		gcc

RM      =		rm -f

NAME    =		my_sokoban

FLAGS	=		-lncurses

SRC		=		src/my_sokoban.c		\
				src/mini_printf.c 		\
				src/my_strlen.c			\
				src/show_map.c 			\
				src/movement.c 			\
				src/check_error.c 		\

OBJ		=     	$(SRC:.c=.o)

all:        $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) *.out
		$(RM) *.#
		$(RM) *.gnda
		$(RM) *.gndo

fclean:	clean
		$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
