SRC = ft_philo.c \
		ft_parsing.c \
		ft_itoa.c \
		ft_libft.c \
		ft_fill.c \
		ft_thread.c \
		ft_action.c \
		ft_eat.c \
		ft_end.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,${SRC})
OBJ_DIR	= objs/

FLAGS = -Wall -Wextra -Werror

THREAD_FLAGS = -lpthread -D_REENTRANT

$(OBJ_DIR)%.o	: %.c
				mkdir -p $(OBJ_DIR)
				cc $(FLAGS) -c $< -o $@

NAME = philo

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(THREAD_FLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
