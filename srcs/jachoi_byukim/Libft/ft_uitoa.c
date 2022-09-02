/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:17:53 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 17:47:14 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_uitoa(uint64_t n, int base)
{
	const char	*digit[] = {"0123456789abcdef", "0123456789ABCDEF"};
	int			sz;
	char		*ret;

	if (base == 10)
		return (ft_itoa(n));
	sz = ft_unumlen(n, (base & 0xff));
	if (!(ret = (char*)malloc(sz + 1)))
		return (ret);
	ret[sz] = 0;
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		if (sz >= 1)
			ret[--sz] = digit[(base >> 10)][n % (base & 0xff)];
		n /= (base & 0xff);
	}
	return (ret);
}
