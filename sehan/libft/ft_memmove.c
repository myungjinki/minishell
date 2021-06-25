/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:27:52 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:29:54 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_temp;
	unsigned char	*s_temp;
	size_t			i;

	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	if (dest > src)
	{
		i = n;
		while (0 < i)
		{
			*(d_temp + i - 1) = *(s_temp + i - 1);
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
