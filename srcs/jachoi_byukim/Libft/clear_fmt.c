/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:25:12 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 00:17:46 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			clear_fmt(t_fmt fmt)
{
	t_fmt	next;

	while (fmt)
	{
		if (fmt->content)
			free(fmt->content);
		fmt->content = NULL;
		next = fmt->next;
		free(fmt);
		fmt = next;
	}
	return (-1);
}

void		free_content(t_fmt fmt)
{
	if (!fmt)
		return ;
	if (fmt->content)
		free(fmt->content);
	fmt->content = NULL;
}

int			free_content_with_status(t_fmt fmt, int status)
{
	free_content(fmt);
	return (status);
}
