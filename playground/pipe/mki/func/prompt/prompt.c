/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:59:42 by mki               #+#    #+#             */
/*   Updated: 2021/04/22 13:05:33 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char	c;

	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		// write(1, &c, 1);
	}
	return (0);
}
