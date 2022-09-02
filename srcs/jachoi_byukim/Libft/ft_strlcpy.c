/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:53:57 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:35:55 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t sz;
	size_t l;

	l = ft_strlen(src);
	sz = (l < size - 1) ? l : size - 1;
	if (size)
	{
		ft_memcpy(dst, src, sz);
		dst[sz] = 0;
	}
	return (l);
}
