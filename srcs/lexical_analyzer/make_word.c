/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:54:15 by mki               #+#    #+#             */
/*   Updated: 2021/06/12 16:32:03 by sehan            ###   ########.fr       */
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

void	word_init(t_word **word, int i)
{
	int j;

	j = 0;
	*word = (t_word *)malloc(sizeof(t_word) * (i + 1));
	while (j <= i)
	{
		word[0][j].fd_in = -2;
		word[0][j].fd_out = -2;
		j++;
	}
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
		else if (token->name == '>' || token->name == '<')
		{
			if (((t_token *)lst->next->content)->name == '>')
				lst = lst->next;
			str_size[i]--;
		}
		lst = lst->next;
	}
	word_init(word, i);
	return (str_size);
}

//void	word_check(t_word *word)
//{
//	int i;
//	int j;
//
//	i = 0;
//	while (1)
//	{
//		j = 0;
//		printf("fd_out : %d fd_in %d\n", word[i].fd_out, word[i].fd_in);
//		while (word[i].argv && word[i].argv[j])
//		{
//			printf("%s ", word[i].argv[j]);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//}

t_word	*make_word_list(t_list *lst_begin)
{
	t_token	*token;
	t_word	*word;
	int		*str_size;
	int		i;
	int		j;

	str_size = string_size(lst_begin, &word);
	i = 0;
	j = -1;
	word[i].argv = (char **)malloc(sizeof(char *) * (str_size[i] + 1));
	word[i].argv[str_size[i]] = 0;
	while (lst_begin)
	{
		token = lst_begin->content;
		if (token->name == 's')
			word[i].argv[++j] = ft_strdup(token->value);
		else if (token->name == '>')
			right_angle_bracket(&lst_begin, word, &i);
		else if (token->name == '<')
			token = left_angle_bracket(&lst_begin, word, &i, &j);
		if (token->name == ';' || token->name == '|')
			malloc_argv(word, &i, &j, str_size[i + 1]);
		lst_begin = lst_begin->next;
	}
//	word_check(word);
	return (word);
}