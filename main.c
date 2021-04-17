/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:41:42 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 12:10:50 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_mini	mini;

	argv = 0;
	argc = 0;

	mini_init(&mini, envp);
	while (read(0, mini.str, 4) > 0)
	{
		mini.c = ft_stoi(mini.str);
		if (mini.c == ARROW_UP || mini.c == ARROW_DOWN)
			arrow(&mini.lst_temp, mini.c);
		else if (mini.c == 10)
			enter(&mini, envp);
		else if (mini.c == DELETE)
		{
			delete_end(0);
			if (ft_strlen(mini.lst_temp->content))
				mini.lst_temp->content[ft_strlen(mini.lst_temp->content) - 1] = 0;
		}
		else
		{
			mini.temp = mini.lst_temp->content;
			mini.lst_temp->content = ft_strjoin(mini.lst_temp->content, mini.str);
			free(mini.temp);
			write(1, mini.str, 1);
		}
		ft_memset(mini.str, 0, 5);
	}
	return (0);
}
