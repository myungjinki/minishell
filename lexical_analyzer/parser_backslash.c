
#include "lexical_analyzer.h"

int	isspecial_in_dquote(char c)
{
	if (c == '`' || c == '\\' || c == '\"' || c == '$')
		return (1);
	return (0);
}

int	parser_backslash(t_list *lst, int mode)
{
	t_token	*token[2];
	t_list	*lst_next;
	char	c;

	lst_next = lst->next;
	if (lst->next == NULL)
		return (syntax_error(BACKSLASH_MULTI));
	token[0] = lst->content;
	token[1] = lst_next->content;
	c = token[1]->name;
	if (mode == 1 && !isspecial_in_dquote(c))
		return (0);
	token[0]->name = 's';
	free(token[0]->value);
	token[0]->value = token[1]->value;
	lst->next = lst_next->next;
	free(lst_next->content);
	free(lst_next);
	return (0);
}
