CC = clang
CFLAGS = -c -Wall -Wextra -Werror -g
NAME = libft.a
SRCS = add_fmt.c char_to_content.c clear_fmt.c ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_max.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_min.c ft_numlen.c ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_slen.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_uitoa.c ft_unumlen.c init_fmt.c int_to_content.c parse.c parse_sub.c print_fmt.c printf_flag.c printf_specifier.c ptr_to_content.c str_to_content.c uint_to_content.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = $(wildcard *.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OS = $(shell uname)
NORM = $(shell find /usr ~ -name 'norminette*' 2>/dev/null | head -1)
all: $(NAME)

%.o: %.c
	$(CC) $< $(CFLAGS) -o $@
$(NAME): $(OBJS)
	ar -rcs $(NAME) $^
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
norm:
	@if [ -z $(NORM) ]; then\
		echo "[-] No norminette T.T";\
	else\
		$(NORM) *.c *.h;\
	fi
.PHONY: all clean fclean re bonus norm
