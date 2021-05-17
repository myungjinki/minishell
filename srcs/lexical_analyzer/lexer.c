/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:47 by mki               #+#    #+#             */
/*   Updated: 2021/05/17 12:49:16 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		ft_issp(char c)
{
	if (c == '*' || c == '@' || c == '#' || c == '?' ||
		c == '-' || c == '$' || c == '!' || c == '0')
		return (c);
	return (0);
}

int		ft_ismeta(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' ||
		c == ')' || c == '<' || c == '>' || c == '`')
		return (c);
	return (0);
}

int		ft_isspace(char c)
{
	if (c == ' ')
		return (c);
	return (0);
}

int		ft_isquotes(char c)
{
	if (c == '\'' || c == '\"' || c == '\\')
		return (c);
	return (0);
}

int		ft_isspecial(char c)
{
	return (ft_isdigit(c) || ft_issp(c) || ft_ismeta(c) || ft_isspace(c) || ft_isquotes(c));
}

int		token_string(t_list **begin_list, char *str, int idx)
{
	int		len;
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	// free(token->value);
	len = idx;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
			len++;
		else
			break ;
	}
	len -= idx;
	token->value = (char *)malloc(sizeof(char) * (len + 1));
	token->name = 's';
	ft_strlcpy(token->value, str + idx, len + 1);
	ft_lstadd_back(begin_list, ft_lstnew(token));
	return (len);
}

int		token_special(t_list **begin_list, char c)
{
	t_token	*t;

	t = (t_token *)malloc(1);
	t->name = c;
	// free(t->value);
	printf("%lu\n", sizeof(t_token));
	t->value = (char *)malloc(sizeof(char) * 2);
	t->value[0] = c;
	t->value[1] = '\0';
	ft_lstadd_back(begin_list, ft_lstnew(t));
	return (1);
}

t_list	*lexer(char *str)
{
	t_list	*lst_token;
	int		idx;

	lst_token = NULL;
	idx = 0;
	while (str[idx])
	{
		if (ft_isalpha(str[idx]))
			idx += token_string(&lst_token, str, idx);
		else if (ft_isspecial(str[idx]))
			idx += token_special(&lst_token, str[idx]);
		else
			idx++;
	}
	return (lst_token);
}
