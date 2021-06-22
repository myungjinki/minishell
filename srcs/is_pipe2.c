/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:08 by sehan             #+#    #+#             */
/*   Updated: 2021/06/22 18:27:12 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parent(t_mini *mini, t_word **word, t_list *lst)
{
	*word = lst->content;
	if ((*word)->fd_in > 0)
		close((*word)->fd_in);
	if ((*word)->fd_out > 0)
		close((*word)->fd_out);
	close(mini->fd_lst->next->fd[1]);
	close(mini->fd_lst->fd[0]);
}

void	pipe_exe(t_mini *mini, char **split)
{
	if (ft_strcmp(split[0], "pwd") == 0)
		ft_pwd();
	else if (!ft_strncmp(split[0], "cd", 2) && split[1])
		ft_cd(mini->env, split[1]);
	else if (ft_strcmp(split[0], "export") == 0 && split[1])
		ft_add_export(mini, split);
	else if (ft_strcmp(split[0], "env") == 0 ||
			ft_strcmp(split[0], "export") == 0)
		ft_env(*mini, split[0]);
	else if (ft_strcmp(split[0], "exit") == 0)
		ft_exit(mini, split);
}
