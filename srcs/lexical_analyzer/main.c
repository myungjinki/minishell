/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:34:43 by mki               #+#    #+#             */
/*   Updated: 2021/05/06 18:08:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		main(int argc, char *argv[], char *envp[])
{
	char	buf[1024];
	int		i;
	t_list	*lst;
	t_token *token;

	argc = 0;
	argv = 0;
	i = 0;
	while (i < 1024)
		buf[i++] = 0;
	while (1)
	{
		scanf("%s", buf);
		lst = lexical_analyzer(buf, envp);
		// printf("%s\n", ((char **)(((t_list *)lst->content))->content)[0]);
	}
	return (0);
}