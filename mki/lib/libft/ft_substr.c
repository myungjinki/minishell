/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:13:35 by sehan             #+#    #+#             */
/*   Updated: 2020/10/14 01:47:14 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
	{
		if (!(result = (char *)malloc(sizeof(char))))
			return (result);
		*result = 0;
		return (result);
	}
	if (start + len > size)
		len = size - start;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (result);
	while (++i < len)
		result[i] = s[start + i];
	result[i] = 0;
	return (result);
}
