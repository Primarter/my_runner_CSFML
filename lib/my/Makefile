##
## EPITECH PROJECT, 2019
## makefile #1
## File description:
## compile lib etc
##

OBJ	=	$(patsubst %.c, %.o, $(wildcard *.c))

NAME	=	test

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		rm -f $(OBJ)
		rm -f $(NAME)
		mv libmy.a ../../
clean:
	rm -f $(OBJ)
	rm -f ../../libmy.a
fclean:	clean
	rm -f $(NAME)
re:	fclean all