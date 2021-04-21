# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:42:00 by sehan             #+#    #+#              #
#    Updated: 2021/04/21 17:36:48 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
CFLAGS_FT	=	-Wall -Wextra -Werror 
CFLAGS_ASAN	=	-fsanitize=address -g2
CFLAGS		=	$(CFLAGS_FT) $(CFLAGS_ASAN)
LFLAGS		=	-Llib/libft -lft -lncurses
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -rf

SRCS_F		=	control\
				cursor\
				delete\
				enter\
				ft_add_export\
				ft_cd\
				ft_env\
				ft_envp_list\
				ft_envp_lstadd\
				ft_exit\
				ft_find_env\
				ft_pwd\
				main\
				mini_init\
				terminal_setting
SRCS_D		=	srcs/
SRCS_C		=	$(addprefix $(SRCS_D), $(addsuffix .c, $(SRCS_F)))
SRCS_O		=	$(addprefix $(SRCS_D), $(addsuffix .o, $(SRCS_F)))

ETC_F		=	ft_free_split\
				ft_stoi\
				ft_strcmp
ETC_D		=	lib/etc/
ETC_C		=	$(addprefix $(ETC_D), $(addsuffix .c, $(ETC_F)))
ETC_O		=	$(addprefix $(ETC_D), $(addsuffix .o, $(ETC_F)))

LIST_F		=	ft_d_lstadd_back\
				ft_d_lstadd_front\
				ft_d_lstclear\
				ft_d_lstcopy\
				ft_d_lstnew
LIST_D		=	lib/d_list/
LIST_C		=	$(addprefix $(LIST_D), $(addsuffix .c, $(LIST_F)))
LIST_O		=	$(addprefix $(LIST_D), $(addsuffix .o, $(LIST_F)))

INC_D		=	includes/

LIBFT_D		=	lib/libft
LIBFT_A		=	$(LIBFT_D)/libft.a

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(SRCS_O) $(ETC_O) $(LIST_O)
	make -C $(LIBFT_D)
	make bonus -C $(LIBFT_D)
	$(CC) $(CFLAGS) $(LFLAGS) $(SRCS_O) $(ETC_O) $(LIST_O) -o $@

all: $(NAME)

clean:
	$(RM) $(SRCS_O) $(ETC_O) $(LIST_O)
	make clean -C $(LIBFT_D)

fclean: clean
	$(RM) $(NAME)
	rm $(LIBFT_A)

re: clean all

.PHONY: bonus all clean fclean re