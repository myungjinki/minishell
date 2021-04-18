/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/04/18 16:34:36 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	not_builtin(t_mini *mini, char *envp[], char *temp)
{
	char		**argv;
	char		*path;
	char		**split;
	int			i;
	char		*temp2;

	argv = ft_split(temp, ' ');
	mini->env_temp = ft_find_env(mini->env, "PATH");
	if (!mini->env_temp)
		exit(1);
	split = ft_split(mini->env_temp->value, ':');
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
	mini->env_temp = ft_find_env(mini->env, "PWD");
	path = ft_strjoin(mini->env_temp->value, "/");
	temp2 = ft_strjoin(path, argv[0]);

	signal(SIGQUIT, sig);

	execve(temp2, argv, envp);
	free(path);
	free_split(split);
	printf("command not found: %s\n", temp);
	exit(0);
}

static void	builtin(t_mini *mini, char *envp[])
{
	char	*temp;

	temp = ft_strtrim(mini->lst_temp->content, " ");
	if (ft_strcmp(temp, "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(temp, "cd ", 3) == 0 ||
			(!ft_strcmp(temp, "cd") && ft_strlen(temp) == 2))
		ft_cd(mini->env, temp + 3);
	else if (ft_strcmp(temp, "env") == 0 || ft_strcmp(temp, "export") == 0)
		ft_env(*mini, temp);
	else if (ft_strncmp(temp, "export ", 7) == 0)
		ft_add_export(mini, temp);
	else if (ft_strcmp(temp, "exit") == 0)
		ft_exit(mini, temp);
	else if (ft_strncmp(temp, "unset ", 6) == 0)
		ft_envp_lstdelone(mini->env, ft_strtrim(temp + 6, " "));
	else
	{
		mini->pid = fork();
		if (mini->pid == 0)
			not_builtin(mini, envp, temp);
		else
			wait(NULL);
		mini->pid = 0;
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
