/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:48:03 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:36:09 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	int				m;

	d = s;
	m = n;
	while (--m >= 0)
		d[m] = (unsigned char)c;
	return (s);
}
