/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:49:42 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:36:17 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*e;
	size_t			len;

	e = ft_memchr(src, c, n);
	len = (size_t)e - (size_t)src + 1;
	ft_memcpy(dest, src, e ? len : n);
	return (e ? (unsigned char*)dest + len : NULL);
}
