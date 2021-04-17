/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:35:16 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 16:29:09 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_envp_lstclear(t_envp_list **lst)
{
	t_envp_list *temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

void	ft_envp_lstadd(t_envp_list **lst, char *str)
{
	t_envp_list	*path;
	char		**split;

	path = (t_envp_list *)malloc(sizeof(t_envp_list));
	if (!*lst)
		*lst = path;
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = path;
	}
	split = ft_split(str, '=');
	path->next = NULL;
	path->key = ft_strdup(split[0]);
	path->value = ft_strdup(split[1]);
	free_split(split);
}

void	ft_envp_lstdelone(t_envp_list *lst, char *str)
{
	t_envp_list	*temp;

	while (lst->next)
	{
		if (ft_strcmp(lst->next->key, str) == 0)
			break ;
		lst = lst->next;
	}
	if (!lst->next)
		return ;
	free(lst->next->key);
	free(lst->next->value);
	temp = lst->next;
	lst->next = lst->next->next;
	free(temp);
}

void	ft_envp_lstinit(t_envp_list **lst, char *envp[])
{
	int			i;

	i = 0;
	while (envp[i])
	{
		ft_envp_lstadd(lst, envp[i]);
		i++;
	}
	ft_envp_lstdelone(*lst, "OLDPWD");
}
