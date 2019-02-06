##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc -Iinclude/ -Wall -Werror -Wextra -Wpedantic -pedantic-errors -lcsfml-graphics -lcsfml-audio -lcsfml-system

RM		=	rm -f

NAME		=	my_hunter

SRCS		=	src/display.c 	\
			src/game.c	\
			src/my_putstr.c	\
			src/set_struc.c	\
			src/my_put_nbr.c

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	clean fclean re

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
