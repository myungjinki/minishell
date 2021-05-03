/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:47 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 20:07:58 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_issp(char c)
{
	if (c == '*' || c == '@' || c == '#' || c == '?' ||
		c == '-' || c == '$' || c == '!' || c == '0')
		return (c);
	else
		return (0);
}

int		ft_ismeta(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' ||
		c == ')' || c == '<' || c == '>')
		return (c);
	else
		return (0);
}

int		ft_isspace(char c)
{
	if (c == ' ')
		return (c);
	else
		return (0);
}

int		ft_isspecial(char c)
{
	return (ft_isdigit(c) || ft_issp(c) || ft_ismeta(c) || ft_isspace(c));
}

int		token_string(t_list **begin_list, char *str, int idx)
{
	int		len;
	t_token	*t;

	t = (t_token *)malloc(sizeof(t_token));
	len = idx;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
			len++;
		else
			break ;
	}
	len -= idx;
	t->value = (char *)malloc(sizeof(char) * (len + 1));
	t->name = 's';
	ft_strlcpy(t->value, str + idx, len + 1);
	ft_lstadd_back(begin_list, ft_lstnew(t));
	return (len);
}

int		token_special(t_list **begin_list, char c)
{
	t_token	*t;

	t = (t_token *)malloc(sizeof(t_token));
	t->name = c;
	t->value = (char *)malloc(sizeof(char) + 2);
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
