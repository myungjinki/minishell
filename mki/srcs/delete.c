/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:36:13 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:04:20 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	nbr_size(int nbr)
{
	int result;

	result = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

static void	get_cursor_position(int *col, int *row)
{
	int		flag;
	int		i;
	char	buf[256];
	int		size;

	i = 0;
	flag = 0;
	write(0, "\033[6n", 4);
	size = read(0, buf, 255);
	buf[size] = 0;
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			size = ft_atoi(&buf[i]);
			if (flag == 0)
				*row = size - 1;
			else
				*col = size - 1;
			flag = 1;
			i += nbr_size(size) - 1;
		}
		i++;
	}
}

static int	putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void		delete_end(int flag)
{
	char	*cm;
	char	*ce;
	int		col;
	int		row;

	get_cursor_position(&col, &row);
	cm = tgetstr("cm", NULL);
	ce = tgetstr("ce", NULL);
	if (flag == 1)
		col = 1;
	else if (col != 1)
		--col;
	tputs(tgoto(cm, col, row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
}
