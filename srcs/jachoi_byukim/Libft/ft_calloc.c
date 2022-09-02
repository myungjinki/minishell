/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:02:42 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/02 01:10:08 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	char	*ret;
	size_t	i;

	while (!(ret = (char*)malloc(nmemb * size)))
		;
	i = 0;
	if (!ret)
		return (NULL);
	while (i < nmemb * size)
		ret[i++] = 0;
	return (ret);
}
