/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:43:25 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 13:48:49 by sehan            ###   ########.fr       */
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
	char		**split;
	t_word		*word;

	word = lst->content;
	mini->env_temp = ft_find_env(mini->env, "PATH");
	if (!mini->env_temp)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(word->argv[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	split = ft_split(mini->env_temp->value, ':');
	not_builtin_exe(envp, split, word->argv);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(word->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

static void	builtin(t_mini *mini, char *envp[])
{
	int			i;
	t_f_list	*f_lst_temp;
	t_list		*temp;

	i = 0;
	mini->pid = 0;
	f_lst_temp = mini->fd_lst;
	temp = mini->lst_parsed;
	while (temp)
	{
		if (((t_list *)temp->content)->next)
			is_pipe(mini, envp, temp->content);
		else
			is_not_pipe(mini, envp, temp->content);
		temp = temp->next;
	}
	mini->pid = 0;
}

static void	history(t_mini *mini)
{
	char *temp;

	temp = ft_strdup(mini->history->content);
	free(mini->head->content);
	free(mini->head->temp);
	mini->head->content = ft_strdup(temp);
	mini->head->temp = ft_strdup(temp);
	free(mini->history->content);
	mini->history->content = ft_strdup(mini->history->temp);
	free(mini->history->temp);
	mini->history->temp = ft_strdup(mini->history->content);
	ft_d_lstadd(&mini->head);
	mini->history = mini->head;
	free(temp);
}

void		enter(t_mini *mini, char *envp[])
{
	char *str;

	write(1, "\n", 1);
	if (ft_strcmp(mini->history->content, ""))
	{
		backup_term(mini);
		mini->flag = 0;
		str = ft_strtrim(mini->history->content, " ");
		if (*str != 0)
			mini->lst_parsed =
				lexical_analyzer(mini->history->content,
						mini->env, mini->status);
		mini->status = 0;
		if (mini->lst_parsed && *str != 0)
			builtin(mini, envp);
		else if (*str != 0)
			mini->status = 127;
		if (*str != 0 && mini->lst_parsed)
			ft_lst_free(mini->lst_parsed);
		history(mini);
		free(str);
	}
	else
		mini->history = mini->head;
	enter_end(mini);
}
