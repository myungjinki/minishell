/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:29 by sehan             #+#    #+#             */
/*   Updated: 2021/04/14 13:25:23 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_d_list	*ft_d_lstnew(void *content)
{
	t_d_list *result;

	result = (t_d_list *)malloc(sizeof(t_d_list));
	if (!result)
		return (result);
	result->content = content;
	result->next = 0;
	result->prev = 0;
	return (result);
}
