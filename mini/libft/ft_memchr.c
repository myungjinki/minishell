/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:50:30 by sehan             #+#    #+#             */
/*   Updated: 2020/10/19 20:07:32 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		i++;
	}
	if (n != i && *(unsigned char *)s == (unsigned char)c)
		return ((void *)s);
	if (n == i)
		return (NULL);
	return ((void *)s);
}
