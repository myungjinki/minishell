/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:28:59 by sehan             #+#    #+#             */
/*   Updated: 2021/04/26 15:51:03 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	exe(t_mini *mini, char *envp[], t_list *temp, int i)
{
	char **split;

	split = (char **)temp->content;
	close(mini->fd_lst->next->fd[0]);
	if (i != 0)
		dup2(mini->fd_lst->fd[0], 0);
	if (temp->next)
		dup2(mini->fd_lst->next->fd[1], 1);
	if (ft_strcmp(split[0], "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(split[0], "cd", 2) == 0)
		ft_cd(mini->env, split[1]);
	else if (ft_strcmp(split[0], "export") == 0 && split[1])
		ft_add_export(mini, split);
	else if (ft_strcmp(split[0], "env") == 0 ||
			ft_strcmp(split[0], "export") == 0)
		ft_env(*mini, split[0]);
	else if (ft_strcmp(split[0], "exit") == 0)
		ft_exit(mini, split[0]);
	else if (ft_strcmp(split[0], "unset") == 0)
		unset(&mini->env, split);
	else
	{
		not_builtin(mini, envp, temp);
		mini->pid = 0;
	}
	exit(0);
}

void		is_pipe(t_mini *mini, char *envp[])
{
	int			i;
	t_f_list	*f_lst_temp;
	t_list		*temp;

	temp = (t_list *)mini->token.lst->content;
	i = 0;
	mini->fd_lst = NULL;
	t_f_lstadd_back(&mini->fd_lst);
	pipe(mini->fd_lst->fd);
	close(mini->fd_lst->fd[1]);
	f_lst_temp = mini->fd_lst;
	while (temp)
	{
		mini->fd_lst = t_f_lstlast(mini->fd_lst);
		t_f_lstadd_back(&mini->fd_lst);
		pipe(mini->fd_lst->next->fd);
		mini->pid = fork();
		if (mini->pid == 0)
			exe(mini, envp, temp, i);
		else
		{
			wait(NULL);
			close(mini->fd_lst->next->fd[1]);
			close(mini->fd_lst->fd[0]);
		}
		i++;
		temp = temp->next;
	}
	t_f_lstclear(&f_lst_temp);
}
