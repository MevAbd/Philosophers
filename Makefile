SRC = philo.c \
		parsing.c \
		lib.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = philo

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
