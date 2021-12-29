SRC = ft_philo.c \
		ft_lib.c \
		ft_atoi.c \
		ft_init_info.c \
		ft_init_philo.c \
		ft_eat.c \
		ft_routine.c \
		ft_finish.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

THREAD_FLAGS = -lpthread -D_REENTRANT

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = philo

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(THREAD_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
