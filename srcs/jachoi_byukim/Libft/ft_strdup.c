/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:03:18 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/03 10:00:26 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	len = ft_slen(s);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s, len);
	return (ret);
}
