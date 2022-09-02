/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:21:34 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 10:09:46 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"
#include "ft_utils.h"

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
		ft_memset(tmp, (!IS_LINUX && (fmt->stat & FLAG_ZERO))
						? '0' : ' ', fmt->width);
		ft_memcpy((fmt->stat & FLAG_MINUS) ? tmp :
			&tmp[fmt->width - fmt->bufsz], fmt->content, fmt->bufsz);
		free_content(fmt);
		fmt->content = tmp;
		fmt->bufsz = fmt->width;
	}
	return (true);
}

static char		*null_internal(t_fmt fmt)
{
	char	*tmp;
	int		cutlen;

	if (fmt->precision <= -1 || fmt->precision >= 6 || !IS_LINUX)
	{
		if (!(tmp = malloc(6)))
			return (tmp);
		cutlen = (fmt->precision <= -1) ? 6 : ft_min(6, fmt->precision);
		ft_memcpy(tmp, "(null)", cutlen);
		fmt->content = tmp;
		fmt->bufsz = cutlen;
	}
	else
	{
		tmp = malloc(1);
		if (!tmp)
			return (tmp);
		tmp[0] = 0;
		fmt->content = tmp;
		fmt->bufsz = 0;
	}
	return (tmp);
}

static bool		null_str(t_fmt fmt)
{
	char *tmp;

	fmt->content = NULL;
	fmt->bufsz = 0;
	if (!(tmp = null_internal(fmt)))
		return (false);
	return (fit_to_width(fmt));
}

static bool		cut_to_precision(t_fmt fmt, char *str)
{
	size_t cutlen;

	cutlen = ft_slen(str);
	if (fmt->precision >= 0)
		cutlen = ft_min(cutlen, fmt->precision);
	if (!(fmt->content = malloc(cutlen)))
		return (false);
	ft_memcpy(fmt->content, str, cutlen);
	fmt->bufsz = cutlen;
	return (true);
}

bool			str_to_content(t_fmt fmt, char *str)
{
	if (!str)
		return (null_str(fmt));
	if (!cut_to_precision(fmt, str))
		return (false);
	return (fit_to_width(fmt));
}
