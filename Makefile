# ==============================
# so_long Makefile
# ==============================

SRC     =	main.c			\
			ft_strlen.c		\
			ft_atoi_base.c	\
			ft_atoi.c		\
			ft_itoa_base.c	\
			ft_isdigit.c	\
			ft_lstnew.c		\
			ft_lstadd_back.c	\
			ft_lstsize.c	\
			ft_lstlast.c

OBJ		=	$(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
			cc $(OBJ) -o $(NAME)

%.o:	%.c
		cc -g -std=gnu17 -Wall -Wextra -Werror -O3 -c $< -o $@


clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
