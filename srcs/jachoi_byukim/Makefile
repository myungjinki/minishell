CC = clang
FLAGS = -g -Wall -Wextra -Werror
NAME = minishell
SRCS = append_char.c array.c cd.c clear_token.c cmd.c echo.c env.c exec.c export.c ft_execvp.c ft_exit.c main.c parser.c pipe.c pre_tokenizer.c pre_tokenizer_2.c process.c prompt.c pwd.c redir.c setup_env.c setup_path.c tokenizer.c tokenizer_utils.c unset.c valid_identifier.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./Libft/libft.a
all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -L Libft -lft -o $@ $(OBJS)
$(LIBFT):
	make -C Libft
clean:
	rm -rf *.o && make -C Libft clean
fclean: clean
	rm -rf $(NAME) && make -C Libft fclean
re: fclean all
