/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:43:18 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 01:38:46 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	g_stat;

bool	parsing_error(char *s)
{
	if (!s)
		return (false);
	if (!ft_strcmp("permission denied", s) && !g_token)
		return (false);
	else if (s)
		ft_eprintf("%s: syntax error near unexpected token `%s`\n",
				SHELL_NAME, s);
	return (true);
}

void	cmd(char *command)
{
	char *post_command;

	if (!command || !*command)
		return ;
	clear_token();
	g_stat = 0;
	post_command = pre_tokenizer(command, 0, 0, 0);
	if (parsing_error(tokenizer(post_command)))
		return (free(post_command));
	parse_and_exec();
	return (free(post_command));
}
