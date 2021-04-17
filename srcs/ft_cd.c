/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:38:11 by sehan             #+#    #+#             */
/*   Updated: 2021/04/13 17:33:35 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(t_envp_list *lst, char *str)
{
	char		*path;
	char		temp[256];

	path = ft_strtrim(str, " ");
	chdir(str);
	lst = ft_find_path(lst, "PWD");
	free(lst->value);
	getcwd(temp, 256);
	lst->value = ft_strdup(temp);
	free(path);
}
