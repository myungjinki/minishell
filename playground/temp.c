/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:17:24 by mki               #+#    #+#             */
/*   Updated: 2021/06/14 14:44:19 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** execve()	-> <unistdh.h>
** fork()	-> <unistdh.h>
** dup2()	-> <unistdh.h>
** pipe()	-> <unistdh.h>
*/

/*
** ls | grep a
*/

/*
** if there is pipe |
** pipe(fd)
** fork()
** dup2()
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(void)
{	
	char	*grep1[3] = {"grep", "a", NULL};
	char	*grep2[3] = {"grep", "b", NULL};
	char	*ls[2] = {"ls", NULL};
	char	*pwd[2] = {"pwd", NULL};
	int		pid[3];
	int		fd_child[3][2];
	int		fd = open("test", O_CREAT | O_WRONLY, 0644);
	
	pipe(fd_child[0]);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(fd_child[0][1], 1);
		close(fd_child[0][0]);
		execve("/usr/bin/grep", grep1, NULL);
	}
	else
	{
		close(fd_child[0][1]);
	}
	pipe(fd_child[1]);
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(fd_child[0][0], 0);
		dup2(fd_child[1][1], 1);
		close(fd_child[0][1]);
		close(fd_child[1][0]);
		execve("/bin/ls", ls, NULL);
	}
	else
	{
		close(fd_child[0][0]);
		close(fd_child[1][1]);
	}
	pipe(fd_child[2]);
	pid[2] = fork();
	// if (pid[2] == 0)
	// {
	// 	dup2(fd_child[1][0], 0);
	// 	// dup2(fd_child[2][1], 1);
	// 	close(fd_child[1][1]);
	// 	close(fd_child[2][0]);

	// 	execve("/bin/ls", ls, NULL);
	// }
	// else
	// {
	// 	close(fd_child[1][0]);
	// 	close(fd_child[2][1]);
	// }
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	// waitpid(pid[2], NULL, 0);
	// dup2(fd_child1[0], 0);
	// execve("/usr/bin/grep", grep2, NULL);
	// dup2(fd, 1);
	return (0);	
}
