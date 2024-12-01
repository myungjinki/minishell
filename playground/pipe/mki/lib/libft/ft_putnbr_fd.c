/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:40:29 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:17:13 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	c = n % 10 + '0';
	if (n < -9)
	{
		write(fd, "-", 1);
		c = -(n % 10) + '0';
		ft_putnbr_fd(-(n / 10), fd);
	}
	else if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		c = -(n % 10) + '0';
	}
	write(fd, &c, 1);
}
