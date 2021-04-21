/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:02:06 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 23:21:19 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_begin(char const *s1, char const *set)
{
	int i;
	int j;

	j = 0;
	while (s1[j])
	{
		i = 0;
		while (set[i])
		{
			if (s1[j] == set[i])
				break ;
			i++;
		}
		if (set[i] == 0)
			break ;
		j++;
	}
	return (j);
}

static int	ft_strtrim_end(char const *s1, char const *set)
{
	int i;
	int j;

	j = ft_strlen(s1) - 1;
	while (j >= 0)
	{
		i = 0;
		while (set[i])
		{
			if (s1[j] == set[i])
				break ;
			i++;
		}
		if (set[i] == 0)
			break ;
		j--;
	}
	return (j);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		j;

	if (!s1)
		return (NULL);
	s1 += ft_strtrim_begin(s1, set);
	if (*s1 == 0)
	{
		if (!(result = (char *)malloc(sizeof(char))))
			return (result);
		*result = 0;
		return (result);
	}
	j = ft_strtrim_end(s1, set);
	if (!(result = (char *)malloc(sizeof(char) * (j + 2))))
		return (result);
	ft_strlcpy(result, s1, j + 2);
	return (result);
}
