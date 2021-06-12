/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:05:13 by sehan             #+#    #+#             */
/*   Updated: 2021/06/12 16:26:16 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	malloc_argv(t_word *word, int *i, int *j, int size)
{
	(*i)++;
	*j = -1;
	word[*i].argv = (char **)malloc(sizeof(char *) * (size + 1));
	word[*i].argv[size] = 0;
}

void	open_fail(t_list **lst, t_word *word, int *i, int *j)
{
	t_token *token;

	token = (*lst)->content;
	if (word[*i].fd_out > 0)
		close(word[*i].fd_out);
	while ((*lst)->next && token->name != '|' && token->name != ';')
	{
		(*lst) = (*lst)->next;
		token = (*lst)->content;
	}
	while ((*j)--)
		free(word[*i].argv[*j]);
	free(word[*i].argv);
	word[*i].argv = NULL;
}

t_token	*left_angle_bracket(t_list **lst, t_word *word, int *i, int *j)
{
	t_token	*token;

	token = (*lst)->content;
	while (token->name != 's')
	{
		(*lst) = (*lst)->next;
		token = (*lst)->content;
	}
	if (word[*i].fd_in > 0)
		close(word[*i].fd_in);
	word[*i].fd_in = open(token->value, O_RDONLY);
	if (word[*i].fd_in < 0)
		open_fail(lst, word, i, j);
	return ((*lst)->content);
}

void	right_angle_bracket(t_list **lst, t_word *word, int *i)
{
	t_token *token;
	t_list	*temp;

	token = (*lst)->content;
	temp = (*lst)->next;
	while (token->name != 's')
	{
		*lst = (*lst)->next;
		token = (*lst)->content;
	}
	if (word[*i].fd_out > 0)
		close(word[*i].fd_out);
	if (((t_token *)temp->content)->name == '>')
		word[*i].fd_out = open(token->value, O_WRONLY | O_CREAT, 0644);
	else
		word[*i].fd_out = open(token->value,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
