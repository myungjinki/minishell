/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:28:59 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 16:58:52 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	dup2_set(t_mini *mini, t_word *word, t_list *temp, int i)
{
	if (word->fd_in > 0)
		dup2(word->fd_in, 0);
	else if (i != 0)
		dup2(mini->fd_lst->fd[0], 0);
	if (word->fd_out > 0)
		dup2(word->fd_out, 1);
	else if (temp->next)
		dup2(mini->fd_lst->next->fd[1], 1);
}

static void	exe(t_mini *mini, char *envp[], t_list *temp, int i)
{
	char	**split;
	t_word	*word;

	word = temp->content;
	split = word->argv;
	close(mini->fd_lst->next->fd[0]);
	if (split)
	{
		dup2_set(mini, word, temp, i);
		if (!ft_strcmp(split[0], "pwd") || !ft_strcmp(split[0], "cd") ||
			(!ft_strcmp(split[0], "export") && split[1]) ||
			!ft_strcmp(split[0], "export") || !ft_strcmp(split[0], "env") ||
			!ft_strcmp(split[0], "exit"))
			pipe_exe(mini, split);
		else if (ft_strcmp(split[0], "unset") == 0)
			unset(&mini->env, split);
		else if (!ft_strcmp(split[0], "echo"))
			ft_echo(split);
		else
			not_builtin(mini, envp, temp);
		exit(mini->status);
	}
	exit(0);
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
	t_word		*word;

	i = 0;
	pipe_init(mini);
	f_lst_temp = mini->fd_lst;
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * ft_lstsize(lst));
	while (lst)
	{
		mini->fd_lst = t_f_lstlast(mini->fd_lst);
		t_f_lstadd_back(&mini->fd_lst);
		pipe(mini->fd_lst->next->fd);
		mini->pid[i] = fork();
		if (mini->pid[i] == 0)
			exe(mini, envp, lst, i);
		else
			parent(mini, &word, lst);
		i++;
		lst = lst->next;
	}
	ft_wait(mini, i, f_lst_temp);
}
