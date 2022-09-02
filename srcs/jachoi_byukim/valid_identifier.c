/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 04:39:58 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 00:29:52 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	valid_identifier(char *s)
{
	if (ft_isdigit(*s++))
		return (false);
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (false);
		s++;
	}
	return (true);
}
