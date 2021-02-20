##
## EPITECH PROJECT, 2020
## B-PSU-200-STG-2-1-bsmysokoban-sylvian.burn
## File description:
## Makefile
##

SRC	=	main.c	\
		my_str_to_line_array.c	\
		error.c	\
		free.c	\

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