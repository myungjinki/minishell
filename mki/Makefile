# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/04/21 22:21:42 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

INC 		=	includes/
CC			=	gcc
CFLAGS_FT	=	-Wall -Wextra -Werror 
CFLAGS_ASAN	=	-fsanitize=address -g2
CFLAGS		=	$(CFLAGS_FT) $(CFLAGS_ASAN) -I $(INC)

LFLAGS		=	-Llib/libft -lft -lncurses

AR			=	ar
ARFLAGS		=	rcs

RM			=	rm -rf

BIN_F		=	ft_add_export\
				ft_cd\
				ft_exit\
				ft_pwd
BIN_D		=	srcs/bin/
BIN_C		=	$(addprefix $(BIN_D), $(addsuffix .c, $(BIN_F)))
BIN_O		=	$(addprefix $(BIN_D), $(addsuffix .o, $(BIN_F)))

ENV_F		=	ft_env\
				ft_envp_list\
				ft_envp_lstadd\
				ft_find_env
ENV_D		=	srcs/env/
ENV_C		=	$(addprefix $(ENV_D), $(addsuffix .c, $(ENV_F)))
ENV_O		=	$(addprefix $(ENV_D), $(addsuffix .o, $(ENV_F)))

PARSE_F		=	executor\
				expander\
				lexer\
				parser
PARSE_D		=	srcs/parse/
PARSE_C		=	$(addprefix $(PARSE_D), $(addsuffix .c, $(PARSE_F)))
PARSE_O		=	$(addprefix $(PARSE_D), $(addsuffix .o, $(PARSE_F)))

PIPE_F		=	ft_f_list\
				is_not_pipe\
				is_pipe
PIPE_D		=	srcs/pipe/
PIPE_C		=	$(addprefix $(PIPE_D), $(addsuffix .c, $(PIPE_F)))
PIPE_O		=	$(addprefix $(PIPE_D), $(addsuffix .o, $(PIPE_F)))

SHELL_F		=	control\
				cursor\
				delete\
				enter\
				main\
				mini_init\
				minishell\
				terminal_setting
SHELL_D		=	srcs/shell/
SHELL_C		=	$(addprefix $(SHELL_D), $(addsuffix .c, $(SHELL_F)))
SHELL_O		=	$(addprefix $(SHELL_D), $(addsuffix .o, $(SHELL_F)))

ETC_F		=	ft_free_split\
				ft_stoi\
				ft_strcmp
ETC_D		=	lib/etc/
ETC_C		=	$(addprefix $(ETC_D), $(addsuffix .c, $(ETC_F)))
ETC_O		=	$(addprefix $(ETC_D), $(addsuffix .o, $(ETC_F)))

DLIST_F		=	ft_d_lstadd_back\
				ft_d_lstadd_front\
				ft_d_lstclear\
				ft_d_lstcopy\
				ft_d_lstnew
DLIST_D		=	lib/d_list/
DLIST_C		=	$(addprefix $(DLIST_D), $(addsuffix .c, $(DLIST_F)))
DLIST_O		=	$(addprefix $(DLIST_D), $(addsuffix .o, $(DLIST_F)))

INC_D		=	includes/

LIBFT_D		=	lib/libft
LIBFT_A		=	$(LIBFT_D)/libft.a

OBJS		=	$(BIN_O) $(ENV_O) $(PARSE_O) $(PIPE_O) $(SHELL_O) $(ETC_O) $(DLIST_O)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_D)
	make bonus -C $(LIBFT_D)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_D)

fclean: clean
	$(RM) $(NAME)
	rm $(LIBFT_A)

re: clean all

.PHONY: bonus all clean fclean re