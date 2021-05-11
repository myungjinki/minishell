/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:30:01 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 13:36:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

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


int		parser_envp(t_list *lst, t_envp_list *envp)
{

}
