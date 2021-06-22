/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_multiline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:36:22 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:39:15 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	quote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\'')
			return (0);
		(*i)++;
	}
	if (str[*i] == 0)
		return (syntax_error(QUOTES_MULTI));
	return (0);
}

int	dquote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\"')
			return (0);
		if (str[*i] == '\\' && str[*i + 1] != 0)
			(*i)++;
		(*i)++;
	}
	if (str[*i] == 0)
		return (syntax_error(DQUOTES_MULTI));
	return (0);
}

int	double_semi(char *str, int *i)
{
	(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == ';')
		return (1);
	return (0);
}

int	syntax_multline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			if (quote(str, &i))
				return (1);
		if (str[i] == '\"')
			if (dquote(str, &i))
				return (1);
		if (str[i] == '|')
			if (str[i + 1] == 0)
				return (syntax_error(PIPELINE_MULTI));
		if (str[i] == ';')
			if (double_semi(str, &i))
				return (syntax_error(SYNTAX));
		i++;
	}
	if (str[0] == ';')
		return (syntax_error(SYNTAX));
	return (0);
}
