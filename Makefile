##
## EPITECH PROJECT, 2020
## B-PSU-200-STG-2-1-bsmysokoban-sylvian.burn
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_str_to_line_array.c	\
		src/error.c	\
		src/free.c	\
		src/game.c	\
		src/move.c	\
		src/end_screen.c	\
		src/scanning.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-lncurses	\
			-g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/my -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re