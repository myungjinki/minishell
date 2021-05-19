/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:40:18 by sehan             #+#    #+#             */
/*   Updated: 2021/05/19 12:09:37 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pid_fork(t_mini *mini, char *envp[], t_list *lst)
{
	mini->pid[0] = fork();
	if (mini->pid[0] == 0)
		not_builtin(mini, envp, lst);
	else
		wait(&mini->status);
	mini->pid[0] = 0;
}

void		is_not_pipe(t_mini *mini, char *envp[], t_list *lst)
{
	char **str;

	str = lst->content;
	mini->pid = (pid_t *)malloc(sizeof(pid_t));
	if (ft_strcmp(str[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strncmp(str[0], "cd ", 3) == 0 ||
			(!ft_strcmp(str[0], "cd") && ft_strlen(str[0]) == 2))
		ft_cd(mini->env, str[1]);
	else if (ft_strcmp(str[0], "export") == 0 && str[1])
		ft_add_export(mini, str);
	else if (ft_strcmp(str[0], "env") == 0 || ft_strcmp(str[0], "export") == 0)
		ft_env(*mini, str[0]);
	else if (ft_strcmp(str[0], "exit") == 0)
		ft_exit(mini, str[0]);
	else if (ft_strcmp(str[0], "unset") == 0)
		unset(&mini->env, str);
	else
		pid_fork(mini, envp, lst);
}
