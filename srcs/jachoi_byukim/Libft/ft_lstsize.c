/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:33:32 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:36:19 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*iter;
	int		sz;

	sz = 0;
	iter = 0;
	if (lst)
		iter = lst;
	while (iter)
	{
		iter = iter->next;
		sz++;
	}
	return (sz);
}
