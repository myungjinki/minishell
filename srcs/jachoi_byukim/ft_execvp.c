/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:50:38 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 00:02:40 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_indir(char *dir, char *file)
{
	DIR*const		d = opendir(dir);
	struct dirent	*dd;

	if (!d)
		return (false);
	readdir(d);
	readdir(d);
	while ((dd = readdir(d)))
	{
		if (!ft_strcmp(dd->d_name, file))
		{
			closedir(d);
			return (true);
		}
	}
	closedir(d);
	return (false);
}

void	make_abspath(char *dir, char *file, char **ret)
{
	const int	file_len = ft_strlen(file);
	const int	dir_len = ft_strlen(dir);
	char *const	tmp = ft_calloc(dir_len + file_len + 2, sizeof(char));

	ft_memcpy(tmp, dir, dir_len);
	tmp[dir_len] = '/';
	ft_memcpy(tmp + dir_len + 1, file, file_len);
	tmp[dir_len + file_len + 1] = 0;
	free(*ret);
	*ret = tmp;
}

int		ft_execvp(char *file, char **argv)
{
	char**const	envp = env_to_arr();
	t_list		*iter;
	bool		end;

	end = false;
	if (ft_strchr(file, '/'))
	{
		end = true;
		execve(file, argv, envp);
	}
	iter = g_path;
	while (iter && !end)
	{
		if (is_indir(iter->content, file))
		{
			make_abspath(iter->content, file, &argv[0]);
			end = true;
			execve(argv[0], argv, envp);
		}
		iter = iter->next;
	}
	free_2d_array(envp);
	return (-1);
}
