/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:40:18 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:36:37 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_not_pipe(t_mini *mini, char *envp[], char *str)
{
	if (ft_strcmp(str, "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(str, "cd ", 3) == 0 ||
			(!ft_strcmp(str, "cd") && ft_strlen(str) == 2))
		ft_cd(mini->env, str + 3);
	else if (ft_strcmp(str, "env") == 0 || ft_strcmp(str, "export") == 0)
		ft_env(*mini, str);
	else if (ft_strncmp(str, "export ", 7) == 0)
		ft_add_export(mini, str);
	else if (ft_strcmp(str, "exit") == 0)
		ft_exit(mini, str);
	else if (ft_strncmp(str, "unset ", 6) == 0)
		ft_envp_lstdelone(mini->env, ft_strtrim(str + 6, " "));
	else
	{
		mini->pid = fork();
		if (mini->pid == 0)
			not_builtin(mini, envp, str);
		else
			wait(NULL);
		mini->pid = 0;
	}
}
