/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:39:51 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 01:36:04 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct		s_fmt
{
	char			*content;
	int				bufsz;
	int				width;
	int				precision;
	int				stat;
	struct s_fmt	*next;
	struct s_fmt	*base;
}*					t_fmt;
bool				parse_spec(const char *format, va_list ap, t_fmt fmt);
bool				parse(const char *format, va_list ap, t_fmt fmt);
size_t				parse_flag(const char *format, va_list ap, t_fmt fmt);
size_t				parse_width(const char *format, va_list ap, t_fmt fmt);
size_t				parse_precision(const char *format, va_list ap, t_fmt fmt);
size_t				parse_len(const char *format, va_list ap, t_fmt fmt);
bool				is_specifier(char c);
bool				set_specifier(char c, t_fmt fmt);
bool				is_flag(char c);
bool				set_flag(char c, t_fmt fmt);
int					clear_fmt(t_fmt fmt);
int					print_fmt(const char *format, t_fmt fmt);
int					ft_printf(const char *format, ...);
bool				init_fmt(t_fmt *pfmt);
t_fmt				add_fmt(t_fmt old);
bool				ptr_to_content(t_fmt fmt, void *ptr);
bool				int_to_content(t_fmt fmt, int64_t n);
bool				uint_to_content(t_fmt fmt, uint64_t n);
bool				char_to_content(t_fmt fmt, char c);
bool				str_to_content(t_fmt fmt, char *str);
void				free_content(t_fmt fmt);
int					free_content_with_status(t_fmt fmt, int status);
int					eprint_fmt(const char *format, t_fmt fmt);
int					ft_eprintf(const char *format, ...);
#endif
