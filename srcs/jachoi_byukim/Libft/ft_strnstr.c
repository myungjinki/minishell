/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:57:24 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/11 08:30:23 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min_internal(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);
	int				count;

	count = ft_min_internal(ft_strlen(big), len) - little_len + 1;
	while (--count >= 0)
	{
		if (!ft_strncmp(big, little, little_len))
			return (char*)big;
		big++;
	}
	return (0);
}
