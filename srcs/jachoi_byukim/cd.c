/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:11:57 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 01:38:47 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_directory(char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	bool		ret;
	struct stat	s;

	fstat(fd, &s);
	ret = (s.st_mode & S_IFMT) == S_IFDIR;
	close(fd);
	return (ret);
}

void	cd_internal(char *dir)
{
	struct stat	buffer;

	g_laststat = 1;
	if (stat(dir, &buffer) != 0)
		ft_eprintf("cd: no such file or directory: %s\n", dir);
	else if (is_directory(dir))
	{
		if (!~chdir(dir))
			ft_eprintf("cd: %s: %s\n", dir, strerror(errno));
		else
			g_laststat = 0;
	}
	else
		ft_eprintf("cd: not a directory: %s\n", dir);
}

void	wrapper_cd(t_process *proc)
{
	char	*dir;
	t_env	*env;

	g_laststat = 1;
	dir = NULL;
	if (proc->idx == 1)
	{
		env = get_env("HOME");
		if (!env)
		{
			ft_eprintf("%s: cd: HOME not set\n", SHELL_NAME);
			return ;
		}
		dir = get_env_value("HOME");
	}
	else
		dir = ft_strdup(proc->argv[1]);
	cd_internal(dir);
	free(dir);
}
