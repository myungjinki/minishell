/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_lstadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:33:05 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:35:36 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			ft_find_equal(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static void	ft_envp_lstadd_back(t_envp_list **lst, t_envp_list *temp)
{
	while ((*lst)->next)
		lst = &((*lst)->next);
	(*lst)->next = temp;
}

void		ft_envp_lstadd(t_envp_list **lst, char *str)
{
	t_envp_list *temp;
	char		**split;

	split = ft_split(str, '=');
	temp = ft_find_env(*lst, split[0]);
	if (temp)
		free(temp->value);
	else
	{
		temp = (t_envp_list *)malloc(sizeof(t_envp_list));
		temp->next = NULL;
		if (!*lst)
			*lst = temp;
		else
			ft_envp_lstadd_back(lst, temp);
		temp->key = ft_strdup(split[0]);
	}
	if (split[1])
		temp->value = ft_strdup(split[1]);
	else if (ft_find_equal(str))
		temp->value = ft_strdup("");
	else
		temp->value = NULL;
	free_split(split);
}
