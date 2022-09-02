/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:58:57 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/11 08:42:59 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_internal(int c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int			ft_atoi(const char *nptr)
{
	int64_t	tmp;
	int8_t	is_minus;

	tmp = 0;
	is_minus = 0;
	while (ft_isspace_internal(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		is_minus = (*nptr == '-');
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		tmp *= 10;
		tmp += (*nptr - '0');
		nptr++;
	}
	if (is_minus)
		tmp *= -1;
	return (tmp);
}
