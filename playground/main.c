/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:17:24 by mki               #+#    #+#             */
/*   Updated: 2021/06/14 14:55:51 by mki              ###   ########.fr       */
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

// ls | grep a

int	main(void)
{	
	char	*cmd1[2] = {"ls", NULL};
	char	*cmd2[3] = {"grep", "e", NULL};
	int		fd1[2];
	int		pid1;
	int		fd2[2];
	int		pid2;

	pipe(fd1);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd1[1], 1);
		close(fd1[0]);
		execve("/bin/ls", cmd1, NULL);
	}
	else
	{
		close(fd1[1]);		
	}
	pipe(fd2);
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd1[1], 1);
		dup2(fd1[1], 1);
		close(fd1[0]);
		execve("/use/bin/grep", cmd2, NULL);
	}
	else
	{
		close(fd1[1]);		
	}
	return (0);	
}
