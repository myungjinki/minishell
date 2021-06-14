/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:54:15 by mki               #+#    #+#             */
/*   Updated: 2021/06/11 08:34:54 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	semi_num(t_make *make)
{
	int		i;
	t_list	*temp;
	t_token	*token;

	i = 0;
	while (make->lst)
	{
		token = make->lst->content;
		if (token->name == '>' || token->name == '<')
			make->str_num[i]--;
		if (token->name == 's')
			make->str_num[i]++;
		if (token->name == ';')
		{
			ft_lstadd_back(&make->result, ft_lstnew((t_list *)malloc(sizeof(t_list))));
			temp = ft_lstlast(make->result);
			temp = temp->content;
			temp->next = 0;
			i++;
		}
		if (token->name == '|')
			i++;
		make->lst = make->lst->next;
	}
}

int		pipe_semi_num(t_list *lst)
{
	t_token *token;
	int		result;

	result = 0;
	while (lst)
	{
		token = lst->content;
		if (token->name == '|' || token->name == ';')
			result++;
		lst = lst->next;
	}
	return (result);
}

void	make_init(t_make *make, t_list *lst, t_word **word)
{
	make->lst = lst;
	make->str_num = (int *)malloc(sizeof(int) * (pipe_semi_num(make->lst) + 1));
	ft_memset(make->str_num, 0, sizeof(int) * (pipe_semi_num(make->lst) + 1));
	make->w_fd = -2;
	make->r_fd = -2;
	make->result = NULL;
	ft_lstadd_back(&make->result, ft_lstnew((t_list *)malloc(sizeof(t_list))));
	make->temp = make->result->content;
	make->temp->next = 0;
	*word = (t_word *)malloc(sizeof(t_word));
	(*word)->fd_in = -2;
	(*word)->fd_out = -2;
	semi_num(make);
	(*word)->argv = (char **)malloc(sizeof(char *) * (make->str_num[0] + 1));
	(*word)->argv[make->str_num[0]] = 0;
	make->lst = lst;
}

t_list	*make_word_list(t_list *lst_begin)
{
	int		i;
	int		j;
	t_list	*head;
	t_word	*word;
	t_make	make;

	word = NULL;
	make_init(&make, lst_begin, &word);
	i = 0;
	j = 0;
	head = make.result;
	while (make.lst)
	{
		make.token = make.lst->content;
		if (make.token->name == 's')
			word->argv[j++] = ft_strdup(make.token->value);
		if (make.token->name == '>')
		{
			if (((t_token *)(make.lst->next->content))->name == '>')
			{
			}
			else
			{
				make.lst = make.lst->next;
				make.token = make.lst->content;
				while (make.token->name != 's')
				{
					make.lst = make.lst->next;
					make.token = make.lst->content;
				}
				make.w_fd = open(make.token->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (word->fd_in > 0)
					close(word->fd_in);
				word->fd_in = make.w_fd;
			}
		}
		else if (make.token->name == '<')
		{
			make.token->name = ' ';
			while (make.token->name != 's')
			{
				make.lst = make.lst->next;
				make.token = make.lst->content;
			}
			make.r_fd = open(make.token->value, O_RDONLY);
			if (make.r_fd < 0)
			{
				if (word->fd_in > 0)
					close(word->fd_in);
				free(word);
				word = NULL;
				while (make.lst && make.token->name != '|' && make.token->name != ';')
				{
					make.lst = make.lst->next;
					if (make.lst)
						make.token = make.lst->content;
				}
			}
			else
			{
				if (word->fd_out > 0)
					close(word->fd_out);
				word->fd_out = make.r_fd;
			}
		}
		if (make.token->name == ';' || make.token->name == '|')
		{
			pipe_semi_init(&make, &word, &i, &j);
//			make.temp = (t_list *)make.result->content;
//			make.temp =	ft_lstlast(make.temp);
//			make.temp->content = word;
//			make.temp = make.temp->next;
//			word = (t_word *)malloc(sizeof(t_word));
//			word->fd_in = -2;
//			word->fd_out = -2;
//			make.temp = make.result->content;
//			if (make.token->name == ';')
//				make.result = make.result->next;
//			else
//				ft_lstadd_back(&make.temp, ft_lstnew(NULL));
//			i++;
//			j = 0;
//			word->argv = (char **)malloc(sizeof(char *) * (make.str_num[i] + 1));
//			word->argv[make.str_num[i]] = 0;
		}
		if (make.lst)
			make.lst = make.lst->next;
	}
	make.temp = (t_list *)make.result->content;
	make.temp = ft_lstlast(make.temp);
	make.temp->content = word;
	printf("%p\n", word);
	lst_token_free(lst_begin, NULL);
	return (head);
}
