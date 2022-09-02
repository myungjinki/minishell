/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:10:56 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/07 09:39:39 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	sz;
	size_t	i;
	char	*ret;

	sz = ft_strlen(s);
	ret = ft_calloc(sz + 1, sizeof(char));
	i = 0;
	while (i < sz && ret)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
