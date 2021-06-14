/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:54:59 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:28:24 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_size(long long n)
{
	int size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	int			size;
	char		*result;

	nbr = n;
	size = int_size(nbr);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (result);
	result[size] = 0;
	if (nbr == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		size--;
		result[size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
