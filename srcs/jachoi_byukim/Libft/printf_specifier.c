/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:57:37 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/21 23:20:48 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"

static const char *g_specifiers = "cspdiuxX%";

bool			is_specifier(char c)
{
	size_t i;

	i = 0;
	while (g_specifiers[i])
	{
		if (g_specifiers[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool			set_specifier(char c, t_fmt fmt)
{
	size_t i;

	if (!is_specifier(c))
		return (false);
	i = 0;
	while (g_specifiers[i] != c)
		i++;
	fmt->stat |= (1 << (SPEC_OFFSET + i));
	return (true);
}
