/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:08:37 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:36:01 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_arrcnt(char const *s, char c)
{
	size_t ret;

	ret = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			ret++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

static char		*ft_split_next(const char *s, char c, int *pi)
{
	size_t		i;
	size_t		j;
	char		*ret;

	i = *pi;
	ret = 0;
	while (s[i] && s[i] == c)
		i++;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	if (i - j)
		ret = ft_calloc(i - *pi + 1, sizeof(char));
	if (ret)
		ft_memcpy(ret, &s[j], i - j);
	*pi = i;
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char **const	ret = ft_calloc(ft_split_arrcnt(s, c) + 1, sizeof(char*));
	char			*elem;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while ((elem = ft_split_next(s, c, &i)))
		ret[j++] = elem;
	return (ret);
}
