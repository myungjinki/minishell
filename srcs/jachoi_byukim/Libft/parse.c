/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:30:03 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 09:11:24 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_format(const char *format, va_list ap, t_fmt fmt)
{
	size_t idx;

	if (!format || format[0] != '%')
		return (0);
	idx = 1;
	idx += parse_flag(&format[idx], ap, fmt);
	idx += parse_width(&format[idx], ap, fmt);
	idx += parse_precision(&format[idx], ap, fmt);
	if (!parse_spec(&format[idx], ap, fmt))
		return (0);
	idx += 1;
	return (idx);
}

bool			parse(const char *format, va_list ap, t_fmt fmt)
{
	size_t	i;
	size_t	offset;
	t_fmt	tmp;

	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			i++;
		if (!format[i])
			break ;
		if (!(offset = parse_format(&format[i], ap, fmt)))
			return (false);
		if (!(tmp = add_fmt(fmt)))
			return (false);
		fmt = tmp;
		i += offset;
	}
	return (true);
}
