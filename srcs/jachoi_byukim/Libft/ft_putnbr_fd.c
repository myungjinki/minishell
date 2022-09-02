/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:14:04 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:46:27 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[1];

	if (n == -2147483648 || n == 0)
		return (void)write(fd, n ? "-2147483648" : "0", n ? 11 : 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		return (ft_putnbr_fd(-1 * n, fd));
	}
	if (n < 10)
	{
		buf[0] = n + '0';
		write(fd, buf, 1);
		return ;
	}
	else if (n == 10)
	{
		write(fd, "10", 2);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n > 10)
		ft_putnbr_fd(n % 10, fd);
}
