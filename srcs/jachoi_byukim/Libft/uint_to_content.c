/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_to_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:06:37 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 21:56:06 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_printf.h"
#include "ft_utils.h"

static bool		fit_to_precision(t_fmt fmt, char *tmp)
{
	const int tlen = ft_slen(tmp);

	if (fmt->precision > tlen)
	{
		if (!(fmt->content = (char*)malloc(fmt->precision)))
		{
			free(tmp);
			return (false);
		}
		ft_memset(fmt->content, '0', fmt->precision);
		ft_memcpy(&fmt->content[fmt->precision - tlen], tmp, tlen);
		fmt->bufsz = fmt->precision;
		free(tmp);
	}
	else
	{
		fmt->content = tmp;
		fmt->bufsz = tlen;
	}
	return (true);
}

static bool		fit_to_width(t_fmt fmt)
{
	char *tmp;

	if (fmt->bufsz < fmt->width)
	{
		if (!(tmp = malloc(fmt->width)))
		{
			free_content(fmt);
			return (false);
		}
		ft_memset(tmp, (fmt->stat & FLAG_ZERO) ? '0' : ' ', fmt->width);
		ft_memcpy((fmt->stat & FLAG_MINUS) ? tmp :
			&tmp[fmt->width - fmt->bufsz], fmt->content, fmt->bufsz);
		free_content(fmt);
		fmt->content = tmp;
		fmt->bufsz = fmt->width;
	}
	return (true);
}

bool			uint_to_content(t_fmt fmt, uint64_t n)
{
	int		base;
	char	*tmp;

	base = 10;
	if (fmt->stat & SPEC_BIG_HEX)
		base = (16 | 1024);
	else if (fmt->stat & SPEC_SMALL_HEX)
		base = 16;
	if (n == 0 && fmt->precision == 0)
	{
		fmt->content = NULL;
		fmt->bufsz = 0;
	}
	else if (!(tmp = ft_uitoa(n, base)) || !fit_to_precision(fmt, tmp))
		return (false);
	return (fit_to_width(fmt));
}
