/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/04/25 16:16:28 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	mini->env_temp = ft_find_env(mini->env, "PWD");
	temp = ft_strjoin(mini->env_temp->value, "/");
	path = ft_strjoin(temp, argv[0]);
	execve(path, argv, envp);
	free(path);
	free_split(split);
}

void		not_builtin(t_mini *mini, char *envp[], char *temp)
{
	char		**argv;
	char		**split;

	backup_term(mini);
	argv = ft_split(temp, ' ');
	mini->env_temp = ft_find_env(mini->env, "PATH");
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
	char		**split;
	int			i;
	t_f_list	*f_lst_temp;

	split = ft_split(mini->lst_temp->content, '|');
	i = 0;
	mini->pid = 0;
	f_lst_temp = mini->fd_lst;
	if (split[i + 1])
		is_pipe(mini, envp, split);
	else
		is_not_pipe(mini, envp, split[0]);
	mini->pid = 0;
	free_split(split);
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
