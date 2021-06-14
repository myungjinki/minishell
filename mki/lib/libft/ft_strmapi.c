/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:23:35 by sehan             #+#    #+#             */
/*   Updated: 2020/10/14 01:34:09 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			size;
	unsigned int	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (result);
	result[size] = 0;
	i = 0;
	while (*s)
	{
		result[i] = f(i, *s);
		s++;
		i++;
	}
	return (result);
}
