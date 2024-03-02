NAME = push_swap

FLAG = -g -Wall -Wextra -Werror
CC = cc 

SRC = main.c\
	parsing.c\
	utils_check.c\
	utils_parsing.c\
	swap.c\
	push.c\
	rotate.c\
	r_reverse.c\
	


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	mv libft/libft.a .
	$(CC) $(OBJ) -L. -lft -o $(NAME)

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<



clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all clean fclean re

