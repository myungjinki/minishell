/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 12:05:43 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin(t_mini *mini, char *envp[])
{
	char	*temp;
	char	*path;
	char	**split;
	pid_t	pid;

	pid = 0;
	temp = ft_strtrim(mini->lst_temp->content, " ");
	if (ft_strcmp(temp, "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(temp, "cd ", 3) == 0)
		ft_cd(mini->env, temp + 3);
	else
	{
		split = ft_split(temp, ' ');
		path = ft_strjoin("/bin/", split[0]);
		pid = fork();
		if (pid == 0)
		{
			execve(path, split, envp);
		}
		else
			wait(NULL);
		free(path);
	}
	free(temp);
}

void	enter(t_mini *mini, char *envp[])
{
	write(1, "\n", 1);
	if (ft_strcmp(mini->lst_temp->content, ""))
	{
		mini->temp = mini->history->content;
		mini->history->content = ft_strdup(mini->lst_temp->content);
		builtin(mini, envp);
		free(mini->temp);
		mini->lst_temp = mini->head;
		ft_d_lstclear(&mini->lst_temp);
		ft_d_lstadd(&mini->history);
		ft_d_lstcopy(&mini->lst_temp, mini->history);
		mini->head = mini->lst_temp;
	}
	else
		mini->lst_temp = mini->head;
	write(1, ">", 1);
}
