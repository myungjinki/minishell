/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:06:25 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/10 22:23:44 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return ((unsigned)*a - (unsigned)*b);
		a++;
		b++;
	}
	return ((unsigned)*a - (unsigned)*b);
}
