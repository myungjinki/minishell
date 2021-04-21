/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:35:16 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:18:21 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_envp_lstclear(t_envp_list **lst)
{
	t_envp_list *temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
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
	{
		free(str);
		return ;
	}
	free(lst->next->key);
	free(lst->next->value);
	temp = lst->next;
	lst->next = lst->next->next;
	free(str);
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
	ft_envp_lstdelone(*lst, ft_strdup("OLDPWD"));
}
