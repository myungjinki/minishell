/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:35:16 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 17:14:29 by sehan            ###   ########.fr       */
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
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	ft_envp_lstdelone(t_envp_list **lst, char *str)
{
	t_envp_list	*temp;

	while (*lst)
	{
		if (ft_strcmp((*lst)->key, str) == 0)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			return ;
		}
		lst = &((*lst)->next);
	}
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
	ft_envp_lstdelone(lst, "OLDPWD");
}
