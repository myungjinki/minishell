/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:36:02 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:36:06 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		syntax_error(int num)
{
	if (num == BACKSLASH_MULTI)
		printf("\\ Multiline Command doesn't work\n");
	else if (num == DQUOTES_MULTI)
		printf("\" Multiline Command doesn't work\n");
	else if (num == QUOTES_MULTI)
		printf("\' Multiline Command doesn't work\n");
	else if (num == PIPELINE_MULTI)
		printf("| Multiline Command doesn't work\n");
	else if (num == SYNTAX)
		printf("syntax error near unexpected token\n");
	return (1);
}
