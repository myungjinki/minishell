/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:00:00 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 19:03:06 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	enter_end(t_mini *mini)
{
	int i;

	if (mini->status >= 256)
		mini->status /= 256;
	if (mini->flag)
		mini->status = mini->flag;
	term_set();
	write(1, "minishell$ ", 11);
	get_cursor_position(&mini->col_size, &i);
}
