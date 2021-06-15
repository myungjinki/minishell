/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:25:11 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 22:32:00 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_envp_list **lst, char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		export_check(str, i, &j);
		ft_envp_lstdelone(lst, str[i]);
		i++;
	}
}
