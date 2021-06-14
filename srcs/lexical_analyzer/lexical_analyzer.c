/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/06/14 22:14:35 by sehan            ###   ########.fr       */
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

void	print_list(t_list *lst)
{
	t_list	*second;
	int		i;

	while (lst)
	{
		second = lst->content;
		while (second)
		{
			i = 0;
			if (((t_word *)second->content)->argv[i])
			{
				printf("%s ", ((t_word *)second->content)->argv[i]);
				i++;
			}
			printf("%s ", ((t_word *)second->content)->argv[1]);
			second = second->next;
		}
		printf("\n");
		lst = lst->next;
	}
}

t_list	*lexical_analyzer(char *str, t_envp_list *lst_envp, int status)
{
	t_list	*lst;
	char	*trim;
	t_word	*word;

	trim = ft_strtrim(str, " ");
	if (syntax_multline(trim))
		return (NULL);
	if (!(lst = lexer(trim)))
		return (NULL);
	free(trim);
	if (parser(lst, lst_envp, status))
		return (NULL);
	word = make_word(lst);
	lst = make_word_list(lst, word);
	print_list(lst);
//	print_lst_token(lst);
// 	if (!(lst = make_word_list(lst)))
//		return (NULL);
// //	list_check(lst);
// 	return (lst);
	// if (!(lst = executor(str, ret)))
	// 	return (NULL);
	return (lst);
}
