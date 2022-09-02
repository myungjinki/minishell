/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:56:42 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 14:36:39 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s) + 1;
	while (--n >= 0)
	{
		if ((unsigned char)s[n] == (unsigned char)c)
			return (char*)&s[n];
	}
	return (NULL);
}
