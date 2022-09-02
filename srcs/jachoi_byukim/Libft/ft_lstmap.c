/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:36:17 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 21:59:30 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*ret;
	t_list	*tmp;
	int		fatal;

	fatal = false;
	ret = NULL;
	iter = lst;
	while (iter)
	{
		fatal |= !(tmp = ft_lstnew(f(iter->content)));
		if (tmp && !fatal)
			ft_lstadd_back(&ret, tmp);
		iter = iter->next;
	}
	if (fatal)
		ft_lstiter(ret, del);
	return (!fatal ? ret : 0);
}
