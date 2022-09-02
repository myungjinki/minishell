/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:06:44 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/02 22:08:47 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t		ft_slen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
