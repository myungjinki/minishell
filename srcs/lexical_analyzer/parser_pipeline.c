/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:20:15 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 13:35:21 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	parser_pipeline(t_list *lst_begin)
{
	if (!lst_begin->next)
		return (syntax_error(PIPELINE_MULTI));
	return (0);
}
