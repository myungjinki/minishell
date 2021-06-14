/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:24:44 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 21:04:07 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	if (!dest && !src)
		return (NULL);
	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_temp[i] = s_temp[i];
		i++;
	}
	return (dest);
}
