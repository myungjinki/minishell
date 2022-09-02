/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:20:18 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 12:27:32 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool				init_fmt(t_fmt *pfmt)
{
	if (!pfmt)
		return (false);
	*pfmt = (t_fmt)malloc(sizeof(struct s_fmt));
	if (!*pfmt)
		return (false);
	(*pfmt)->content = NULL;
	(*pfmt)->next = NULL;
	(*pfmt)->stat = 0;
	(*pfmt)->bufsz = 0;
	(*pfmt)->base = *pfmt;
	return (true);
}
