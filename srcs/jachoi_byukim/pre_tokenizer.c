/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:46:37 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 02:40:12 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_str(char *cmd)
{
	int		i;
	char	*sub;
	char	*ret;

	if (*cmd != '$')
		return (NULL);
	if (!ft_isalnum(cmd[1]) && cmd[1] != '_')
		return (ft_strdup("$"));
	if (cmd[1] == '?' && !cmd[2])
		return (ft_itoa(g_laststat));
	if (ft_isdigit(cmd[1]) ||
			(!ft_isalnum(cmd[1]) && cmd[1] != '_'))
		return (ft_strdup(""));
	i = 0;
	while (ft_isalnum(cmd[1 + i]) || cmd[1 + i] == '_')
		i++;
	sub = ft_substr(cmd, 1, i);
	ret = get_env_value(sub);
	free(sub);
	return (ret);
}

int		env_len(char *cmd)
{
	int i;

	if (cmd[1] == '?')
		if (!ft_isalnum(cmd[2]) && cmd[2] != '_')
			return (2);
	i = 0;
	while (ft_isalnum(cmd[1 + i]) || cmd[1 + i] == '_')
		i++;
	return (i + 1);
}

void	pretok_setstat(char *pstat, char c)
{
	if (!*pstat && ft_strchr("\'\"", c))
		*pstat = c;
	else if (*pstat == c)
		*pstat = 0;
}

int		env_put(char *const dst, char *tmp, int d)
{
	int			i;

	i = -1;
	while (++i < (int)ft_strlen(tmp))
		dst[d++] = tmp[i];
	free(tmp);
	return (d);
}

char	*pre_tokenizer(char *src, int d, int s, char status)
{
	char *const	dst = ft_calloc(MAX_FILENAME, sizeof(char));
	char		*tmp;

	while (src[s])
	{
		if (!ft_isalnum(src[s]) && src[s] != '_')
		{
			pretok_setstat(&status, src[s]);
			if (status != '\'' && src[s] == '$')
			{
				if (s == 0 || escape_count(src, s) % 2)
				{
					tmp = env_str(src + s);
					s += env_len(src + s);
					d = env_put(dst, tmp, d);
					continue ;
				}
			}
		}
		dst[d++] = src[s++];
	}
	return (dst);
}
