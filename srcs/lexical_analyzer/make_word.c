/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:54:15 by mki               #+#    #+#             */
/*   Updated: 2021/06/11 19:04:47 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		pipe_and_semi_size(t_list *lst)
{
	int		i;
	t_token	*token;
	
	i = 0;
	while (lst)
	{
		token = lst->content;
		if (token->name == ';' || token->name == '|')
			i++;
		lst = lst->next;
	}
	return (i);
}

int		*string_size(t_list *lst, t_word **word)
{
	t_token	*token;
	int		*str_size;
	int		i;

	i = 0;
	str_size = (int *)malloc(sizeof(int) * (pipe_and_semi_size(lst) + 1));
	ft_memset(str_size, 0, sizeof(int) * (pipe_and_semi_size(lst) + 1));
	while (lst)
	{
		token = lst->content;
		if (token->name == 's')
			str_size[i]++;
		else if (token->name == ';' || token->name == '|')
			i++;
		lst = lst->next;
	}
	*word = (t_word *)malloc(sizeof(t_word) * (i + 1));
	printf("size : %d\n", i);
	return (str_size);
}

t_list	*make_word_list(t_list *lst_begin)
{
	t_list	*result;
	t_token	*token;
	t_word	*word;
	int		*str_size;
	int		i;
	int		j;

	str_size = string_size(lst_begin, &word);
	result = NULL;
	i = 0;
	j = -1;
	word[i].argv = (char **)malloc(sizeof(char *) * (str_size[i] + 1));
	word[i].argv[str_size[i]] = 0;
	while (lst_begin)
	{
		token = lst_begin->content;
		if (token->name == 's')
		{
			word[i].argv[++j] = ft_strdup(token->value);
		}
		else if (token->name == ';' || token->name == '|')
		{
			i++;
			j = -1;
			word[i].argv = (char **)malloc(sizeof(char *) * (str_size[i] + 1));
			word[i].argv[str_size[i]] = 0;
		}
		else if (token->name == '>')
		{
		}
		else if (token->name == '<')
		{
		}
		lst_begin = lst_begin->next;
	}
	return (result);
}
