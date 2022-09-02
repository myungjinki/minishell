/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:50:25 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/10 14:04:39 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char			buf[8192];
	int				i;
	int				j;
	int				k;

	if (!src && !dest)
		return (NULL);
	i = n % 8192;
	j = (n - i) / 8192;
	k = 0;
	while (k < j)
	{
		ft_memcpy(buf, src, 8192);
		ft_memcpy(dest, buf, 8192);
		k++;
	}
	ft_memcpy(buf, src, i);
	ft_memcpy(dest, buf, i);
	return (dest);
}
