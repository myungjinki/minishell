/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:05:25 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:35:58 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	pfx_len = ft_strlen(s1);
	const size_t	sfx_len = ft_strlen(s2);
	char *const		ret = ft_calloc(pfx_len + sfx_len + 1, sizeof(char));

	if (ret)
	{
		ft_memcpy(ret, s1, pfx_len);
		ft_memcpy(&ret[pfx_len], s2, sfx_len);
	}
	return (ret);
}
