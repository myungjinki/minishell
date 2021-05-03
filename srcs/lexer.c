/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:47 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 10:49:48 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		chech_symbol(t_list **ret, char *str, int idx)
{
	int		len;

	return (len);
}

t_list	*lexer(char *str)
{
	t_list	*ret;
	int		idx;

	ret = NULL;
	idx = 0;
	while (str[idx])
		idx += check_symbol(&ret, str, idx);
	return (ret);
}
