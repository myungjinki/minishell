/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:22:41 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 12:27:42 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt			add_fmt(t_fmt old)
{
	t_fmt ret;

	if (!old)
		return (NULL);
	if (!(ret = (t_fmt)malloc(sizeof(struct s_fmt))))
		return (NULL);
	ret->base = old->base;
	ret->content = NULL;
	ret->next = NULL;
	ret->stat = 0;
	ret->bufsz = 0;
	old->next = ret;
	return (ret);
}
