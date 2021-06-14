#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int	quote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\'') 
			return (0);
		(*i)++;
	}
	if (str[*i] == 0)
		return (1);
	return (0);
}

int dquote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\"')
			return (0);
		if (str[*i] == '\\' && str[*i + 1] != 0)
			(*i)++;
		(*i)++;
	}
	if (str[*i] == 0)
		return (1);
	return (0);
}

int multline(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			if (quote(str, &i))
				return (1);
		if (str[i] == '\"')
			if (dquote(str, &i))
				return (1);
		if (str[i] == '\\')
			if (str[i + 1] == 0)
				return (1);
		if (str[i] == 124)
			if (str[i + 1] == 0)
				return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	char buf[4096];
	int size;

	memset(buf, 0, 4096);
	while ((size = read(0, buf, 4096)))
	{
		buf[size - 1] = 0;
		if (multline(buf))
			printf("multline error\n");
		else
			printf("%s\n", buf);
		memset(buf, 0, 4096);
	}
	return (0);
}
