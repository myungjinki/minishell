/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:31:19 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:17:29 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *temp;

	temp = 0;
	while (*s)
	{
		if (*s == c)
			temp = (char *)s;
		s++;
	}
	if (*s == c)
		temp = (char *)s;
	return (temp);
}
