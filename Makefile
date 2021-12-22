SRC = ft_philo.c \
		ft_parsing.c \
		ft_lib.c \
		ft_atoi.c \
		ft_init_info.c \
		ft_thread.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

THREAD_FLAGS = -lpthread -D_REENTRANT

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = philo

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(THREAD_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
