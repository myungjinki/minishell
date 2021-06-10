/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:28:59 by sehan             #+#    #+#             */
/*   Updated: 2021/05/26 11:23:07 by sehan            ###   ########.fr       */
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
		ft_pwd();
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
		not_builtin(mini, envp, temp);
	exit(mini->status);
}

void		ft_wait(t_mini *mini, int i, t_f_list *temp)
{
	int	j;

	j = -1;
	while (++j < i)
		waitpid(mini->pid[j], &mini->status, 0);
	free(mini->pid);
	t_f_lstclear(&temp);
	mini->pid = 0;
}

void		pipe_init(t_mini *mini)
{
	mini->fd_lst = NULL;
	t_f_lstadd_back(&mini->fd_lst);
	pipe(mini->fd_lst->fd);
	close(mini->fd_lst->fd[1]);
}

void		is_pipe(t_mini *mini, char *envp[], t_list *lst)
{
	int			i;
	t_f_list	*f_lst_temp;

	i = 0;
	pipe_init(mini);
	f_lst_temp = mini->fd_lst;
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * ft_lstsize(lst));
	while (lst)
	{
		mini->fd_lst = t_f_lstlast(mini->fd_lst);
		t_f_lstadd_back(&mini->fd_lst);
		pipe(mini->fd_lst->next->fd);
		printf("%d\n", mini->fd_lst->next->fd[0]);
		mini->pid[i] = fork();
		if (mini->pid[i] == 0)
			exe(mini, envp, lst, i);
		else
		{
			close(mini->fd_lst->next->fd[1]);
			close(mini->fd_lst->fd[0]);
		}
		i++;
		lst = lst->next;
	}
	ft_wait(mini, i, f_lst_temp);
}
