
#include "lexical_analyzer.h"

int	ft_isspecial(char c)
{
	if (c == '*' || c == '@' || c == '#' || c == '?' ||
		c == '-' || c == '$' || c == '!' || c == '0')
		return (c);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (c);
	return (0);
}

int	ft_isquotes(char c)
{
	if (c == '\'' || c == '\"' || c == '\\')
		return (c);
	return (0);
}

int	ft_ismeta(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' ||\
		c == ')' || c == '<' || c == '>' || c == '`' || c == '/')
		return (c);
	return (0);
}

int	ft_isall(char c)
{
	return (ft_isdigit(c) || ft_isspecial(c) || ft_ismeta(c) ||\
		ft_isspace(c) || ft_isquotes(c));
}
