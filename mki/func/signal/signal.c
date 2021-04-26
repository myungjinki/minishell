/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:45:19 by mki               #+#    #+#             */
/*   Updated: 2021/04/22 16:51:00 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ctrl_d(int signum)
{
	printf("your input is ctrl+c\n");
	exit(0);
}

int	main(void)
{
	signal(SIGINT, ctrl_d);
	while (1)
	{
		printf("mki is god\n");
		sleep(1);
	}
	return (0);
}
