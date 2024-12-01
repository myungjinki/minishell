/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:38:11 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 19:40:56 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pwd_set(t_envp_list *lst)
{
	char	*temp;
	char	str[256];

	ft_envp_lstdelone(lst, ft_strdup("OLDPWD"));
	lst = ft_find_env(lst, "PWD");
	temp = ft_strjoin("OLDPWD=", lst->value);
	ft_envp_lstadd(&lst, temp);
	free(lst->value);
	free(temp);
	getcwd(str, 256);
	lst->value = ft_strdup(str);
}

static void	ft_cd_hyphen(t_envp_list *lst, char **str)
{
	t_envp_list *lst_temp;

	lst_temp = ft_find_env(lst, "OLDPWD");
	if (lst_temp)
	{
		*str = lst_temp->value;
		printf("%s\n", *str);
	}
	else
	{
		printf("cd: OLDPWD not set\n");
		return ;
	}
}

void		ft_cd(t_envp_list *lst, char *str)
{
	char		*path;
	int			boolean;
	t_envp_list	*lst_temp;

	path = ft_strtrim(str, " ");
	if (*str == '-')
		ft_cd_hyphen(lst, &path);
	else if (*str == 0)
	{
		lst_temp = ft_find_env(lst, "HOME");
		str = lst_temp->value;
	}
	boolean = chdir(path);
	if (boolean == -1)
		printf("cd: no such file or directory: %s\n", path);
	ft_pwd_set(lst);
	free(path);
}
