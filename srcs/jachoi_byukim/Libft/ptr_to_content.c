/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:40:57 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 08:17:11 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"
#include "ft_utils.h"

static bool	fit_to_width(t_fmt fmt)
{
	char *tmp;

	if (fmt->bufsz < fmt->width)
	{
		if (!(tmp = malloc(fmt->width)))
		{
			free_content(fmt);
			return (false);
		}
		ft_memset(tmp, ' ', fmt->width);
		ft_memcpy((fmt->stat & FLAG_MINUS) ? tmp :
			&tmp[fmt->width - fmt->bufsz], fmt->content, fmt->bufsz);
		free_content(fmt);
		fmt->content = tmp;
		fmt->bufsz = fmt->width;
	}
	return (true);
}

static bool	nil_ptr(t_fmt fmt)
{
	char *tmp;

	if (!(tmp = malloc(5)))
		return (false);
	ft_memcpy(tmp, "(nil)", 5);
	fmt->content = tmp;
	fmt->bufsz = 5;
	return (fit_to_width(fmt));
}

static bool	add_suffix(t_fmt fmt)
{
	char *tmp;

	if (!(tmp = malloc(fmt->bufsz + 2)))
	{
		free_content(fmt);
		return (false);
	}
	ft_memcpy(tmp, "0x", 2);
	ft_memcpy(&tmp[2], fmt->content, fmt->bufsz);
	free_content(fmt);
	fmt->content = tmp;
	fmt->bufsz += 2;
	return (true);
}

bool		ptr_to_content(t_fmt fmt, void *ptr)
{
	const int saved = fmt->width;

	if (!ptr && IS_LINUX)
		return (nil_ptr(fmt));
	fmt->stat |= SPEC_SMALL_HEX;
	fmt->width = 0;
	if (!uint_to_content(fmt, (uint64_t)ptr) || !add_suffix(fmt))
		return (false);
	fmt->width = saved;
	fmt->stat &= ~SPEC_SMALL_HEX;
	return (fit_to_width(fmt));
}
