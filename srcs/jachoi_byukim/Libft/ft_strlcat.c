/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:55:33 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/11 08:30:09 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min_internal(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	ft_max_internal(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dst);
	const size_t	slen = ft_strlen(src);
	const size_t	ret = ft_min_internal(size, dlen) + slen;
	const size_t	n = ft_max_internal(0, (int)size - 1 - dlen);

	ft_memcpy(&dst[dlen], src, ft_min_internal(n, slen + 1));
	if (dlen < size)
		dst[dlen + n] = 0;
	return (ret);
}
