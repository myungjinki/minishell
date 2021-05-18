/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:40:18 by sehan             #+#    #+#             */
/*   Updated: 2021/05/17 16:49:21 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_not_pipe(t_mini *mini, char *envp[], t_list *lst)
{
	char **str;

	str = lst->content;
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
	{
		mini->pid = fork();
		if (mini->pid == 0)
			not_builtin(mini, envp, lst);
		else
			wait(&mini->status);
		mini->pid = 0;
	}
}
