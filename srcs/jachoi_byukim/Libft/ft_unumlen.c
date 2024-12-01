/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:16:22 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 17:45:56 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		ft_unumlen(uint64_t n, int base)
{
	int			i;

	i = 1;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}
