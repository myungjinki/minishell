/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:00:00 by sehan             #+#    #+#             */
/*   Updated: 2021/06/22 17:43:02 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	enter_end(t_mini *mini)
{
	int i;

	if (mini->status >= 256 && mini->status != 258)
		mini->status /= 256;
	if (mini->flag)
		mini->status = mini->flag;
	term_set();
	write(1, "minishell$ ", 11);
	get_cursor_position(&mini->col_size, &i);
}

void	enter_mid(t_mini *mini, char *envp[], char *str)
{
	if (mini->lst_parsed && *str != 0)
		builtin(mini, envp);
	else if (!mini->lst_parsed)
		mini->status = 258;
	else if (*str != 0)
		mini->status = 127;
	if (*str != 0 && mini->lst_parsed)
		ft_lst_free(mini->lst_parsed);
}
