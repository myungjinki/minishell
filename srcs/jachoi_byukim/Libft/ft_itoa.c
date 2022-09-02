/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:10:05 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/11 08:31:46 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t	ft_abs_internal(int64_t n)
{
	if (n < 0)
		return (n * (int64_t)-1);
	return (n);
}

static size_t	ft_nbrsz(int n)
{
	size_t sz;

	if (!n)
		return (1);
	sz = 0;
	if (n < 0)
		sz++;
	n = (int)ft_abs_internal(n);
	while (n)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

char			*ft_itoa(int n)
{
	const int	isminus = n < 0;
	size_t		sz;
	char		*ret;

	sz = ft_nbrsz(n);
	ret = ft_calloc(sz + 1, sizeof(char));
	if (!ret)
		return (NULL);
	if (!n)
		ret[0] = '0';
	while (n)
	{
		ret[--sz] = '0' + ft_abs_internal(n) % 10;
		n /= 10;
	}
	if (isminus)
		ret[0] = '-';
	return (ret);
}
