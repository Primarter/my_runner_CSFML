##
## EPITECH PROJECT, 2019
## makefile runner
## File description:
## compile src, lib, tests, etc
##

SRC	=	main.c			\
		main_game.c		\
		struct_def.c	\
		handle_sprite.c	\
		destroy.c		\
		movement.c		\
		map_handling.c	\
		text_print.c	\
		get_ground.c	\
		itos.c			\
		objects.c		\
		menu.c

CFLAGS = -Iinclude/ -W -Wall -Wextra -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS) libmy.a
	find -name "*.o" -type f -delete
clean:
	rm -f $(OBJ)
	rm -f log
fclean:	clean
	rm -f $(NAME)
	find -type f -name libmy.a -delete
	find -type f -name *.o -delete
	find -type f -name unit_tests -delete
	find -type f -name log -delete
re:	fclean all