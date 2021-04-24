/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:44:56 by mki               #+#    #+#             */
/*   Updated: 2021/04/22 14:51:37 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int				ret;
	struct termios	termios_s;

	ret = tcgetattr(STDIN_FILENO, &termios_s);
	if (ret)
		return (0);
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &termios_s);
	if (ret)
		return (0);
	return (0);
}

	// printf("%lx\n", termios_s.c_iflag);
	// printf("%lx\n", termios_s.c_oflag);
	// printf("%lx\n", termios_s.c_cflag);
	// printf("%lx\n", termios_s.c_lflag);
	// printf("%d\n", termios_s.c_cc[1]);
	// printf("%lx\n", termios_s.c_ispeed);
	// printf("%lx\n", termios_s.c_ospeed);
