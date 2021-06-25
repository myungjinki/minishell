# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/06/22 20:23:32 by sehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
ASAN = -fsanitize=address -g2
CFLAGS = -Wall -Wextra -Werror $(ASAN)
LFLAGS = -Llibft -lft -lncurses
AR = ar rcs
RM = rm -f

FILES =	main \
		srcs/ft_strcmp \
		srcs/ft_pwd \
		srcs/ft_cd \
		srcs/ft_find_env \
		srcs/ft_envp_list \
		srcs/terminal_setting \
		srcs/ft_stoi \
		srcs/ft_d_lstnew \
		srcs/ft_d_lstadd_front \
		srcs/cursor \
		srcs/ft_d_lstclear \
		srcs/ft_d_lstadd_back \
		srcs/ft_d_lstcopy \
		srcs/delete \
		srcs/enter \
		srcs/mini_init \
		srcs/ft_free_split \
		srcs/ft_env \
		srcs/ft_exit \
		srcs/ft_add_export \
		srcs/ft_envp_lstadd \
		srcs/control \
		srcs/ft_f_list \
		srcs/is_pipe \
		srcs/is_not_pipe \
		srcs/unset\
		srcs/enter_end \
		srcs/is_pipe2 \
		srcs/ft_lst_free \
		srcs/ft_echo \
		lexical_analyzer/ft_isall \
		lexical_analyzer/lexer \
		lexical_analyzer/lexical_analyzer \
		lexical_analyzer/make_string \
		lexical_analyzer/make_word \
		lexical_analyzer/make_word2 \
		lexical_analyzer/make_word_list \
		lexical_analyzer/parser \
		lexical_analyzer/parser_backslash \
		lexical_analyzer/parser_env \
		lexical_analyzer/parser_quotes \
		lexical_analyzer/syntax_backslash \
		lexical_analyzer/syntax_error \
		lexical_analyzer/syntax_multiline \
		lexical_analyzer/syntax_quotes \
		lexical_analyzer/syntax_redirection \
		lexical_analyzer/token

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	make -C libft bonus
	$(CC) $(CFLAGS) $(LFLAGS) $(SRCS) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	if [ -e "libft/libft.a" ]; then rm libft/libft.a; fi

re: clean all

.PHONY: bonus all clean fclean re
