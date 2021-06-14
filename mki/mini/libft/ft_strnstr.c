/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:43:45 by sehan             #+#    #+#             */
/*   Updated: 2020/11/05 19:49:36 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < n && *big)
	{
		j = 0;
		while (little[j] && j + i < n)
		{
			if (big[j] != little[j])
				break ;
			j++;
		}
		if (!little[j])
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
