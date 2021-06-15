# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/06/15 12:21:25 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
ASAN = -fsanitize=address -g2
CFLAGS = -Wall -Wextra -Werror -I . $(ASAN)
LFLAGS = -Llibft -lft -lncurses -Llexical_analyzer -llex
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

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	make -C libft bonus
	make -C lexical_analyzer
	$(CC) $(CFLAGS) $(LFLAGS) $(SRCS) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C libft
	make clean -C lexical_analyzer

fclean: clean
	$(RM) $(NAME)
	rm lexical_analyzer/liblex.a
	rm libft/libft.a

re: clean all

.PHONY: bonus all clean fclean re
