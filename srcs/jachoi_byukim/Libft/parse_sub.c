/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:33:29 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 09:49:07 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"
#include "ft_utils.h"

size_t				parse_flag(const char *format, va_list ap, t_fmt fmt)
{
	size_t	i;

	(void)ap;
	i = 0;
	while (set_flag(format[i], fmt))
		i++;
	return (i);
}

size_t				parse_width(const char *format, va_list ap, t_fmt fmt)
{
	size_t	i;
	size_t	n;

	if (format[0] == '*')
	{
		fmt->width = va_arg(ap, int);
		if (fmt->width < 0)
		{
			fmt->stat |= FLAG_MINUS;
			fmt->width *= -1;
		}
		return (1);
	}
	n = 0;
	i = 0;
	while (ft_isdigit(format[i]))
	{
		n *= 10;
		n += format[i] - '0';
		i++;
	}
	fmt->width = n;
	return (i);
}

size_t				parse_precision(const char *format, va_list ap, t_fmt fmt)
{
	size_t		i;
	size_t		n;

	if (format[0] != '.')
	{
		fmt->precision = -1;
		return (0);
	}
	if (format[1] == '*')
	{
		fmt->precision = va_arg(ap, int);
		return (2);
	}
	n = 0;
	i = 1;
	while (ft_isdigit(format[i]))
	{
		n *= 10;
		n += format[i] - '0';
		i++;
	}
	fmt->precision = n;
	return (i);
}

bool				parse_spec(const char *format, va_list ap, t_fmt fmt)
{
	bool ret;

	ret = false;
	if (!set_specifier(format[0], fmt))
		return (ret);
	if ((fmt->precision >= 0 && !(!IS_LINUX && (fmt->stat & SPEC_PERCENT))) ||
		((fmt->stat & FLAG_MINUS) && (fmt->stat & FLAG_ZERO)))
		fmt->stat &= ~FLAG_ZERO;
	if (fmt->stat & (SPEC_INT | SPEC_DECIMAL))
		ret = int_to_content(fmt, va_arg(ap, int));
	else if (fmt->stat & SPEC_CHAR)
		ret = char_to_content(fmt, (char)va_arg(ap, int));
	else if (fmt->stat & SPEC_STR)
		ret = str_to_content(fmt, va_arg(ap, char*));
	else if (fmt->stat & (SPEC_UINT | SPEC_BIG_HEX | SPEC_SMALL_HEX))
		ret = uint_to_content(fmt, (unsigned int)va_arg(ap, int));
	else if (fmt->stat & SPEC_PERCENT)
	{
		if (IS_LINUX)
			fmt->width = 0;
		ret = char_to_content(fmt, '%');
	}
	else if (fmt->stat & SPEC_PTR)
		ret = ptr_to_content(fmt, va_arg(ap, void*));
	return (ret);
}
