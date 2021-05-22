/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:04:05 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 13:25:53 by mki              ###   ########.fr       */
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
	else if (num == L_REDIRECTION_SYNTAX)
		printf("bash: syntax error near unexpected token `<'\n");
	else if (num == R_REDIRECTION_SYNTAX)
		printf("bash: syntax error near unexpected token `>'\n");
	else if (num == R_REDIRECTIONS_SYNTAX)
		printf("bash: syntax error near unexpected token `>>'\n");
	else if (num == PIPELINE_SYNTAX)
		printf("bash: syntax error near unexpected token `|'\n");
	else if (num == PIPELINES_SYNTAX)
		printf("bash: syntax error near unexpected token `||'\n");
	else if (num == SEMICOLON_SYNTAX)
		printf("bash: syntax error near unexpected token `;'\n");
	else if (num == SEMICOLONS_SYNTAX)
		printf("bash: syntax error near unexpected token `;;'\n");
	return (1);
}