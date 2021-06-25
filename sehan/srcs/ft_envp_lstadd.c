/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_lstadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:33:05 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 12:59:13 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_find_equal(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static void	ft_envp_lstadd_back(t_envp_list **lst, t_envp_list *temp)
{
	while ((*lst)->next)
		lst = &((*lst)->next);
	(*lst)->next = temp;
}

static char	**export_split(char *str)
{
	int		i;
	char	**result;
	int		size;

	i = 0;
	size = 1;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=' && str[i + 1])
		size++;
	result = (char **)malloc(sizeof(char *) * (size + 1));
	result[size] = 0;
	result[0] = ft_substr(str, 0, i);
	if (size == 2)
		result[1] = ft_substr(str + i + 1, 0, ft_strlen(str + i + 1));
	return (result);
}

void		ft_envp_lstadd(t_envp_list **lst, char *str)
{
	t_envp_list *temp;
	char		**split;

	split = export_split(str);
	temp = ft_find_env(*lst, split[0]);
	if (temp)
		free(temp->value);
	else
	{
		temp = (t_envp_list *)malloc(sizeof(t_envp_list));
		temp->next = NULL;
		if (!*lst)
			*lst = temp;
		else
			ft_envp_lstadd_back(lst, temp);
		temp->key = ft_strdup(split[0]);
	}
	if (split[1])
		temp->value = ft_strdup(split[1]);
	else if (ft_find_equal(str))
		temp->value = ft_strdup("");
	else
		temp->value = NULL;
	free_split(split);
}
