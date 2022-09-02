/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:15:18 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 01:35:41 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_fmt	fmt;
	bool	error;

	va_start(ap, format);
	error = (!init_fmt(&fmt) || !parse(format, ap, fmt));
	va_end(ap);
	if (error)
		return (clear_fmt(fmt));
	return (print_fmt(format, fmt->base));
}

int			ft_eprintf(const char *format, ...)
{
	va_list	ap;
	t_fmt	fmt;
	bool	error;

	va_start(ap, format);
	error = (!init_fmt(&fmt) || !parse(format, ap, fmt));
	va_end(ap);
	if (error)
		return (clear_fmt(fmt));
	return (eprint_fmt(format, fmt->base));
}
