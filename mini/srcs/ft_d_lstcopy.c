/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstcopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:09:40 by sehan             #+#    #+#             */
/*   Updated: 2021/04/14 17:21:40 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_d_lstcopy(t_d_list **src, t_d_list *dst)
{
	*src = ft_d_lstnew(ft_strdup(dst->content));
	dst = dst->next;
	while (dst)
	{
		ft_d_lstadd_back(src, ft_d_lstnew(ft_strdup(dst->content)));
		dst = dst->next;
	}
}
