# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/06/10 21:16:29 by sehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
ASAN = -fsanitize=address -g2
CFLAGS = -Wall -Wextra -Werror -I . $(ASAN)
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
		srcs/lexical_analyzer/executor\
		srcs/lexical_analyzer/ft_isall\
		srcs/lexical_analyzer/ft_ismeta\
		srcs/lexical_analyzer/ft_isquotes\
		srcs/lexical_analyzer/ft_isspace\
		srcs/lexical_analyzer/ft_isspecial\
		srcs/lexical_analyzer/lexer\
		srcs/lexical_analyzer/lexical_analyzer\
		srcs/lexical_analyzer/make_string\
		srcs/lexical_analyzer/make_word\
		srcs/lexical_analyzer/parser_backslash\
		srcs/lexical_analyzer/parser_dquotes\
		srcs/lexical_analyzer/parser_env\
		srcs/lexical_analyzer/parser_pipeline\
		srcs/lexical_analyzer/parser_quotes\
		srcs/lexical_analyzer/parser_redirection\
		srcs/lexical_analyzer/parser_semicolon\
		srcs/lexical_analyzer/parser\
		srcs/lexical_analyzer/syntax_backslash\
		srcs/lexical_analyzer/syntax_dquotes\
		srcs/lexical_analyzer/syntax_error\
		srcs/lexical_analyzer/syntax_multiline\
		srcs/lexical_analyzer/syntax_pipeline\
		srcs/lexical_analyzer/syntax_quotes\
		srcs/lexical_analyzer/syntax_redirection\
		srcs/lexical_analyzer/syntax_semicolon\
		srcs/lexical_analyzer/token_find\
		srcs/lexical_analyzer/token_free\
		srcs/ft_lst_free \
		srcs/lexical_analyzer/make_word2

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
	rm libft/libft.a

re: clean all

.PHONY: bonus all clean fclean re
