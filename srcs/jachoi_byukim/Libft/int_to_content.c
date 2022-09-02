/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:36:45 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 00:19:05 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_printf.h"
#include "ft_utils.h"

static bool		fit_to_precision(t_fmt fmt, int64_t n, char *tmp)
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
		if (n < 0)
		{
			fmt->content[fmt->precision - tlen] = '0';
			fmt->content[0] = '-';
		}
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

static bool		fit_to_width(t_fmt fmt, int64_t n)
{
	char *tmp;

	if (fmt->bufsz < fmt->width)
	{
		if (!(tmp = malloc(fmt->width)))
			return (free_content_with_status(fmt, false));
		ft_memset(tmp, (fmt->stat & FLAG_ZERO) ? '0' : ' ', fmt->width);
		if (fmt->stat & FLAG_MINUS)
			ft_memcpy(tmp, fmt->content, fmt->bufsz);
		else
		{
			ft_memcpy(&tmp[fmt->width - fmt->bufsz], fmt->content, fmt->bufsz);
			if ((n < 0) && (fmt->stat & FLAG_ZERO))
			{
				tmp[fmt->width - fmt->bufsz] = '0';
				tmp[0] = '-';
			}
		}
		free_content(fmt);
		fmt->content = tmp;
		fmt->bufsz = fmt->width;
	}
	return (true);
}

bool			int_to_content(t_fmt fmt, int64_t n)
{
	char			*tmp;

	fmt->precision += (n < 0);
	if (n == 0 && fmt->precision == 0)
	{
		fmt->content = NULL;
		fmt->bufsz = 0;
	}
	else if (!(tmp = ft_itoa(n)) || !fit_to_precision(fmt, n, tmp))
		return (false);
	return (fit_to_width(fmt, n));
}
