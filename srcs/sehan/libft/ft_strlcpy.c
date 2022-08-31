/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:58:56 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 21:34:56 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t		result;
	const char	*temp;
	size_t		i;

	temp = src;
	result = 0;
	i = 0;
	if (!dst && !src)
		return (0);
	while (*temp)
	{
		temp++;
		result++;
	}
	if (size == 0)
		return (result);
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (result);
}
