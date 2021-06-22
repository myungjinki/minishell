
#include "lexical_analyzer.h"

static int	check(t_list *lst, t_token *token)
{
	lst = lst->next;
	if (lst)
	{
		token = lst->content;
		if (token->name == '>')
			lst = lst->next;
		if (lst == NULL)
			return (syntax_error(SYNTAX));
		token = lst->content;
		if (token->name == ' ')
			lst = lst->next;
		if (lst == NULL)
			return (syntax_error(SYNTAX));
		token = lst->content;
		if (token->name != 's' && !ft_isdigit(token->name) &&
				!ft_isspecial(token->name) && !ft_isquotes(token->name))
			return (syntax_error(SYNTAX));
	}
	else
		return (syntax_error(SYNTAX));
	return (0);
}

int			syntax_redirection(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '>' || token->name == '<')
			if (check(lst, token))
				return (1);
		lst = lst->next;
	}
	return (0);
}
