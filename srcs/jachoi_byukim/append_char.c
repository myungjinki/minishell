/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:59:38 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/02 22:00:00 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_char(char *org, char c)
{
	const int	l = ft_slen(org);
	char *const	ret = ft_calloc(l + 2, 1);

	ft_memcpy(ret, org, l);
	ret[l] = c;
	ret[l + 1] = 0;
	if (org)
		free(org);
	return (ret);
}
