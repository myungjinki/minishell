/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:02:56 by sehan             #+#    #+#             */
/*   Updated: 2021/06/10 21:52:33 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	pipe_semi_init(t_make *make, t_word **word, int *i, int *j)
{
	make->temp = (t_list *)make->result->content;
	make->temp = ft_lstlast(make->temp);
	make->temp->content = word;
	make->temp = make->temp->next;
	*word = (t_word *)malloc(sizeof(t_word));
	(*word)->fd_in = -2;
	(*word)->fd_out = -2;
	make->temp = make->result->content;
	if (make->token->name == ';')
		//make->result = make->result->content;
		make->result = make->result->next;
	else
		ft_lstadd_back(&make->temp, ft_lstnew(NULL));
	(*i)++;
	*j = 0;
	(*word)->argv = (char **)malloc(sizeof(char *) * (make->str_num[*i] + 1));
//	printf("%d\n", make->str_num[*i]);
	(*word)->argv[make->str_num[*i]] = 0;
}
