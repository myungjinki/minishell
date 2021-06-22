
#include "lexical_analyzer.h"

int	syntax_backslash(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\\')
			return (syntax_error(BACKSLASH_MULTI));
		lst = lst->next;
	}
	return (0);
}
