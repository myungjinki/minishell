/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:36:13 by sehan             #+#    #+#             */
/*   Updated: 2021/05/31 14:48:05 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void		multline_delete(t_mini *mini, int *col, int *row)
{
	int	len;

	len = ft_strlen(mini->history->content);
	while (len > *col)
	{
		len = len - *col - 1;
		tputs(tgoto(mini->cm, 0, *row), 1, putchar_tc);
		tputs(mini->ce, 1, putchar_tc);
		(*row)--;
		*col = len;
		tputs(tgoto(mini->cm, *col, *row), 1, putchar_tc);
		get_cursor_position(col, row);
	}
	*col = 1;
	tputs(tgoto(mini->cm, *col, *row), 1, putchar_tc);
	tputs(mini->ce, 1, putchar_tc);
}

void		delete_end(t_mini *mini, int flag)
{
	int		col;
	int		row;

	flag = 0;
	get_cursor_position(&col, &row);
	multline_delete(mini, &col, &row);
	if (ft_strcmp(mini->history->content, "") && !flag)
		write(1, mini->history->content, ft_strlen(mini->history->content));
}
