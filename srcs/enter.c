/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 14:35:58 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	not_builtin(t_mini *mini, char *envp[], char *temp)
{
	char		**argv;
	char		*path;
	char		**split;
	t_envp_list	*lst;
	int			i;
	char		*temp2;

	argv = ft_split(temp, ' ');
	lst = ft_find_path(mini->env, "PATH");
	if (!lst)
		exit(1);
	split = ft_split(lst->value, ':');
	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], "/");
		temp2 = ft_strjoin(path, argv[0]);
		free(path);
		execve(temp2, argv, envp);
		free(temp2);
		i++;
	}
	free_split(split);
	exit(1);
}

static void	builtin(t_mini *mini, char *envp[])
{
	char	*temp;
	pid_t	pid;

	temp = ft_strtrim(mini->lst_temp->content, " ");
	if (ft_strcmp(temp, "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(temp, "cd ", 3) == 0)
		ft_cd(mini->env, temp + 3);
	else if (ft_strcmp(temp, "env") == 0)
		ft_env(*mini);
	else if (ft_strcmp(temp, "exit") == 0)
		ft_exit(mini, temp);
	else
	{
		pid = fork();
		if (pid == 0)
			not_builtin(mini, envp, temp);
		else
			wait(NULL);
	}
	free(temp);
}

void		enter(t_mini *mini, char *envp[])
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
