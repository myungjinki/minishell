/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:02:59 by sehan             #+#    #+#             */
/*   Updated: 2020/10/15 23:35:56 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = count * size;
	if (!(result = malloc(len)))
		return (result);
	while (i < len)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}
