/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:49 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 10:40:09 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"

static const char *g_flags = "-0";

bool			is_flag(char c)
{
	size_t i;

	i = 0;
	while (g_flags[i])
	{
		if (g_flags[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool			set_flag(char c, t_fmt fmt)
{
	size_t i;

	if (!is_flag(c))
		return (false);
	i = 0;
	while (g_flags[i] != c)
		i++;
	fmt->stat |= (1 << (FLAG_OFFSET + i));
	return (true);
}
