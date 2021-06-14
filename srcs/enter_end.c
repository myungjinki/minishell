/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:00:00 by sehan             #+#    #+#             */
/*   Updated: 2021/06/14 21:00:56 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	enter_end(t_mini *mini)
{
	if (mini->status >= 256)
		mini->status /= 256;
	if (mini->flag)
		mini->status = mini->flag;
	term_set();
	write(1, ">", 1);
}
