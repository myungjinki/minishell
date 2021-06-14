/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:16:46 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 22:03:04 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(result = (char *)malloc(sizeof(char) * size)))
		return (result);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}
