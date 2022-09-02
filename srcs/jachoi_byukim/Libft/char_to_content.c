/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:47:52 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/23 08:36:06 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_defs.h"
#include "ft_utils.h"

bool			char_to_content(t_fmt fmt, char c)
{
	const size_t	bufsz = ft_max(fmt->width, 1);
	char *const		tmp = (char*)malloc(bufsz);

	if (!tmp)
		return (false);
	ft_memset(tmp, ((fmt->stat & FLAG_ZERO) && !IS_LINUX) ? '0' : ' ', bufsz);
	if (fmt->stat & FLAG_MINUS)
		tmp[0] = c;
	else
		tmp[bufsz - 1] = c;
	fmt->bufsz = bufsz;
	fmt->content = tmp;
	return (true);
}
