/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 17:58:51 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	not_builtin_exe(char *envp[], char **split, char **argv)
{
	int		i;
	char	*temp;
	char	*path;
	char	*str;

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
	str = getcwd(0, 0);
	temp = ft_strjoin(str, "/");
	path = ft_strjoin(temp, argv[0]);
	execve(path, argv, envp);
	free(str);
	free(path);
	free(temp);
}

void		not_builtin(t_mini *mini, char *envp[], t_list *lst)
{
	char		**argv;
	char		**split;

	backup_term(mini);
	argv = (char **)lst->content;
	mini->env_temp = ft_find_env(mini->env, "PATH");
	if (!mini->env_temp)
	{
		printf("%s: No such file or directory\n", argv[0]);
		exit(127);
	}
	split = ft_split(mini->env_temp->value, ':');
	not_builtin_exe(envp, split, argv);
	printf("%s: command not found\n", argv[0]);
	exit(0);
}

static void	builtin(t_mini *mini, char *envp[])
{
	int			i;
	t_f_list	*f_lst_temp;

	i = 0;
	mini->pid = 0;
	f_lst_temp = mini->fd_lst;
	if (((t_list *)mini->token.lst->content)->next)
		is_pipe(mini, envp);
	else
		is_not_pipe(mini, envp);
	mini->pid = 0;
}

void		enter(t_mini *mini, char *envp[])
{
	write(1, "\n", 1);
	token(mini, envp);
	if (ft_strcmp(mini->history->content, ""))
	{
		mini->status = 0;
		free(mini->head->content);
		free(mini->head->temp);
		mini->head->content = ft_strdup(mini->history->content);
		mini->head->temp = ft_strdup(mini->history->content);
		free(mini->history->content);
		mini->history->content = mini->history->temp;
		mini->history->temp = ft_strdup(mini->history->content);
		builtin(mini, envp);
		ft_d_lstadd(&mini->head);
		mini->history = mini->head;
	}
	else
		mini->history = mini->head;
	printf("%d\n", mini->status);
	if (mini->status >= 256)
		mini->status /= 256;
	term_set();
	write(1, ">", 1);
}
