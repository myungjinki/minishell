/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/06/14 12:03:51 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	print_lst_token(t_list *lst)
{
	t_token	*token;

	while (lst)
	{
		token = lst->content;
		printf("%c: %s\n", token->name, token->value);
		lst = lst->next;
	}
}

void	list_check(t_list *lst)
{
	t_list	*temp;
	t_word 	*word;
	int		i;
	while (lst)
	{
		temp = lst->content;
		printf("???? : ");
		while (temp)
		{
			i = 0;
			word = temp->content;
			printf("%p\n", word->argv);
//			printf("%p\n", word->argv[0]);
//			printf("%p\n", word->argv[1]);
			while (word && word->argv[i])
			{
				printf("str : %s \n", word->argv[i]);
				i++;
			}
//			printf("fd_in  %d\n", word->fd_in);
//			printf("fd_out %d\n", word->fd_out);
			temp = temp->next;
		}
		printf("\n");
		lst = lst->next;
	}
}

t_list	*make_word_list(t_word *word)
{
	t_list	*ret;

	
	word = 0;
	ret = NULL;
	return (ret);
}

t_list	*lexical_analyzer(char *str, t_envp_list *lst_envp, int status)
{
	t_list	*lst;
	char	*trim;

	trim = ft_strtrim(str, " ");
	if (syntax_multline(trim))
		return (NULL);
	if (!(lst = lexer(trim)))
		return (NULL);
	free(trim);
	if (parser(lst, lst_envp, status))
		return (NULL);
//	print_lst_token(lst);
 	if (!(lst = make_word_list(make_word(lst))))
 		return (NULL);
// //	list_check(lst);
// 	return (lst);
	// if (!(lst = executor(str, ret)))
	// 	return (NULL);
	return (NULL);
}
