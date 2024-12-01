/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:42:38 by sehan             #+#    #+#             */
/*   Updated: 2021/06/14 22:02:58 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envp_list	*ft_find_env(t_envp_list *lst, char *key)
{
	while (lst)
	{
		if (ft_strcmp(key, lst->key) == 0)
			break ;
		lst = lst->next;
	}
	return (lst);
}
