/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:26:28 by sehan             #+#    #+#             */
/*   Updated: 2021/06/21 21:14:46 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_env_size(t_mini mini)
{
	t_envp_list	*temp;
	int			size;

	size = 0;
	temp = mini.env;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

static void	ft_env_str(t_mini mini, char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = ft_strdup(mini.env->key);
		mini.env = mini.env->next;
		i++;
	}
}

static void	ft_env_sort(char **str, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(str[j], str[j + 1]) > 0)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void		ft_export(t_mini mini)
{
	int			size;
	t_envp_list	*temp;
	char		**str;
	int			i;

	size = ft_env_size(mini);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	str[size] = NULL;
	temp = mini.env;
	ft_env_str(mini, str, size);
	ft_env_sort(str, size);
	i = 0;
	while (i < size)
	{
		printf("declare - x %s", str[i]);
		temp = ft_find_env(mini.env, str[i]);
		if (temp->value)
			printf("=\"%s\"", temp->value);
		printf("\n");
		i++;
	}
	free_split(str);
}

void		ft_env(t_mini mini, char *str)
{
	if (ft_strcmp(str, "env") == 0)
	{
		if (!ft_find_env(mini.env, "PATH"))
		{
			printf("minishell: env: No such file or directory\n");
			g_mini.status = 127;
			return ;
		}
		while (mini.env)
		{
			if (mini.env->value && ft_strcmp(mini.env->value, ""))
				printf("%s=%s\n", mini.env->key, mini.env->value);
			mini.env = mini.env->next;
		}
	}
	else
		ft_export(mini);
}
