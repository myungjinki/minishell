/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:26:04 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 01:35:09 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_fmt(const char *format, t_fmt fmt)
{
	int		written;
	int		i;
	int		j;

	written = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			written += write(STDOUT_FILENO, fmt->content, fmt->bufsz);
			j = i + 1;
			while (!is_specifier(format[j]))
				j++;
			i = j + 1;
			fmt = fmt->next;
		}
		else
		{
			write(STDOUT_FILENO, &format[i++], 1);
			written++;
		}
	}
	clear_fmt(fmt->base);
	return (written);
}

int			eprint_fmt(const char *format, t_fmt fmt)
{
	int		written;
	int		i;
	int		j;

	written = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			written += write(STDERR_FILENO, fmt->content, fmt->bufsz);
			j = i + 1;
			while (!is_specifier(format[j]))
				j++;
			i = j + 1;
			fmt = fmt->next;
		}
		else
		{
			write(STDERR_FILENO, &format[i++], 1);
			written++;
		}
	}
	clear_fmt(fmt->base);
	return (written);
}
