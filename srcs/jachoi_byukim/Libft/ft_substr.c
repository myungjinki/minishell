/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:04:52 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/07 09:45:34 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;

	ret = NULL;
	if (start + len > ft_strlen(s))
	{
		ret = ft_calloc(1, sizeof(char));
		return (ret);
	}
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret)
		ft_memcpy(ret, &s[start], len);
	return (ret);
}
