/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:54:56 by sehan             #+#    #+#             */
/*   Updated: 2020/10/21 00:54:04 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_split_size(char const *s, char c)
{
	int size;

	size = 0;
	if (!s)
		return (-1);
	while (*s && *s == c)
		s++;
	if (*s == 0)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != 0)
			size++;
		while (*s != c && *s != 0)
			s++;
	}
	return (size);
}

int		ft_word_size(char const *s, char c)
{
	int size;

	size = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != 0)
	{
		size++;
		s++;
	}
	return (size);
}

char	**ft_alloc_free(char **s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;
	int		i;

	i = 0;
	size = ft_split_size(s, c);
	if (size == -1)
		return (NULL);
	if (!(result = (char **)ft_calloc(sizeof(char *), size + 1)))
		return (result);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		size = ft_word_size(s, c);
		if (!(result[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (ft_alloc_free(result, i));
		ft_strlcpy(result[i++], s, size + 1);
		while (*s != c && *s != 0)
			s++;
	}
	return (result);
}
