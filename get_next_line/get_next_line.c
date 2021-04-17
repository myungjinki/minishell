/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:41:28 by sehan             #+#    #+#             */
/*   Updated: 2020/11/05 16:24:45 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_split(char **str, char **line, char *buff)
{
	int		size;
	char	*temp;

	size = 0;
	while ((*str)[size] != 0 && (*str)[size] != '\n')
		size++;
	if ((*str)[size] == 0)
		return (0);
	*line = (char *)malloc(sizeof(char) * (size + 1));
	temp = *str;
	ft_strlcpy(*line, *str, size + 1);
	*str = ft_strdup(*str + size + 1);
	free(buff);
	free(temp);
	return (size + 1);
}

static int	error_check(ssize_t size, char **str, char *buff)
{
	if (size < 0)
	{
		free(buff);
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

static void	last_word(char **str, char *buff, char **line)
{
	*line = *str;
	*str = ft_strdup("");
	free(buff);
	free(*str);
	*str = NULL;
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*temp;
	char		*buff;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 10240 ||
			!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (get_split(&str[fd], line, buff))
		return (1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = 0;
		temp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free(temp);
		if (get_split(&str[fd], line, buff))
			return (1);
	}
	if (error_check(size, &str[fd], buff))
		return (-1);
	last_word(&str[fd], buff, line);
	return (0);
}
