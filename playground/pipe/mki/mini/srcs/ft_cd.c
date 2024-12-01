/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:38:11 by sehan             #+#    #+#             */
/*   Updated: 2021/05/19 13:49:07 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_pwd_set(t_envp_list *lst, char *oldpwd)
{
	char	*temp;
	char	*str;

	ft_envp_lstdelone(&lst, "OLDPWD");
	lst = ft_find_env(lst, "PWD");
	temp = ft_strjoin("OLDPWD=", oldpwd);
	ft_envp_lstadd(&lst, temp);
	free(temp);
	if (lst)
	{
		free(lst->value);
		str = getcwd(0, 0);
		lst->value = ft_strdup(str);
	}
}

void		ft_cd(t_envp_list *lst, char *str)
{
	char		*path;
	int			boolean;
	t_envp_list	*lst_temp;
	char		*oldpwd;

	path = ft_strtrim(str, " ");
	if (*str == 0)
	{
		lst_temp = ft_find_env(lst, "HOME");
		str = lst_temp->value;
	}
	oldpwd = getcwd(0, 0);
	boolean = chdir(path);
	if (boolean == -1)
	{
		g_mini.status = 1;
		write(2, "cd: no such file or directory: ", 31);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
	}
	else
		ft_pwd_set(lst, oldpwd);
	free(oldpwd);
	free(path);
}
