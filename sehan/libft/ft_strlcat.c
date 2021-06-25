/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:14:11 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:28:50 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (dest_size > size)
		return (src_size + size);
	while (*dest)
		dest++;
	i = dest_size;
	while (i + 1 < size && *src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = 0;
	return (dest_size + src_size);
}
