# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/05/03 10:11:54 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g2
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
		srcs/executor

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
