/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 17:17:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	not_builtin_exe(char *envp[], char **split, char **argv, t_mini *mini)
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	while (split[i])
	{
		temp = ft_strjoin(split[i], "/");
		path = ft_strjoin(temp, argv[0]);
		free(temp);
		execve(path, argv, envp);
		free(path);
		i++;
	}
	(void)mini;
//	mini->env_temp = ft_find_env(mini->env, "PWD");
//	temp = ft_strjoin(mini->env_temp->value, "/");
//	path = ft_strjoin(temp, argv[0]);
//	execve(path, argv, envp);
//	free(path);
	free_split(split);
}

static void	not_builtin(t_mini *mini, char *envp[], char *temp)
{
	char		**argv;
	char		**split;

	backup_term(mini);
	argv = ft_split(temp, ' ');
	mini->env_temp = ft_find_env(mini->env, "PATH");
	printf("%s\n", temp);
	if (!mini->env_temp)
	{
		printf("bash: %s: No such file or directory\n", temp);
		exit(1);
	}
	split = ft_split(mini->env_temp->value, ':');
	not_builtin_exe(envp, split, argv, mini);
	printf("command not found: %s\n", temp);
	exit(0);
}

static void	builtin(t_mini *mini, char *envp[])
{
	char	*temp;
	char	**split;
	int		i;
	int		status;

	split = ft_split(mini->lst_temp->content, '|');
	i = 0;
	if (mini->pid == 0)
	{
		while (split[i])
		{
			pipe(mini->fd);
			temp = ft_strtrim(split[i], " ");
			if (ft_strcmp(split[i], "pwd") == 0)
				ft_pwd(mini->env);
			else if (ft_strncmp(split[i], "cd ", 3) == 0 ||
					(!ft_strcmp(split[i], "cd") && ft_strlen(split[i]) == 2))
				ft_cd(mini->env, split[i] + 3);
			else if (ft_strcmp(split[i], "env") == 0 || ft_strcmp(split[i], "export") == 0)
				ft_env(*mini, split[i]);
			else if (ft_strncmp(split[i], "export ", 7) == 0)
				ft_add_export(mini, split[i]);
			else if (ft_strcmp(split[i], "exit") == 0)
				ft_exit(mini, split[i]);
			else if (ft_strncmp(split[i], "unset ", 6) == 0)
				ft_envp_lstdelone(mini->env, ft_strtrim(split[i] + 6, " "));
			else
			{
				mini->pid = fork();
				if (mini->pid == 0)
				{
					dup2(mini->fd[1], 1);
					close(mini->fd[0]);
					not_builtin(mini, envp, split[i]);
				}
				else
				{
					wait(&status);
					dup2(mini->fd[0], 0);
					close(mini->fd[1]);
				}
				mini->pid = 0;
			}
			free(temp);
			i++;
		}
		exit(0);
	}
	free(split);
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
	term_set();
	write(1, ">", 1);
}
