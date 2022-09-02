/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:06:13 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/10 14:19:18 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_isinstr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			s;
	size_t			e;
	char			*ret;

	s = 0;
	e = ft_strlen(s1) - 1;
	while (ft_isinstr(set, s1[s]) && s < ft_strlen(s1))
		s++;
	while (ft_isinstr(set, s1[e]) && e >= s)
		e--;
	if (e == s)
		ret = ft_calloc(1, sizeof(char));
	else
		ret = ft_substr(s1, s, e - s + 1);
	return (ret);
}
