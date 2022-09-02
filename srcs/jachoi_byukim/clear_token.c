/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:52:55 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:05:21 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_token(void)
{
	t_token *tok;
	t_token *next;

	tok = g_token;
	while (tok)
	{
		next = tok->next;
		if (tok->data)
			free(tok->data);
		free(tok);
		tok = next;
	}
	g_token = 0;
}
