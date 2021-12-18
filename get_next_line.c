/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:00:43 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/18 23:51:59 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	seek_more_newline(char **remaining, char **line)
{
	char	*p_newline;
	char	*prev;

	p_newline = ft_strchr(*remaining, '\n');
	if (p_newline)
	{
		*p_newline = '\0';
		prev = *remaining;
		*line = ft_strdup(*remaining);
		*remaining = ft_strdup(p_newline + 1);
		ft_strdel(&prev);
		return (1);
	}
	else
	{
		*line = ft_strdup(*remaining);
		ft_strdel(remaining);
	}
	return (0);
}

static void	update_line(char **line, char buff[BUFF_SIZE + 1])
{
	char	*oldline;

	oldline = *line;
	*line = ft_strjoin(*line, buff);
	ft_strdel(&oldline);
}

static int	read_line(char *newline, const int fd, char **left, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			read_bytes;

	while (newline == NULL)
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		if (read_bytes == 0 || read_bytes == -1)
		{
			if (ft_strlen(*line) > 0)
				return (1);
			ft_strdel(&left[fd]);
			ft_strdel(line);
			return (read_bytes);
		}
		buff[read_bytes] = '\0';
		newline = ft_strchr(buff, '\n');
		if (newline)
		{
			*newline = '\0';
			left[fd] = ft_strdup(newline + 1);
		}
		update_line(line, buff);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		*newline;
	static char	*left[FD_MAX];

	if (fd < 0 || line == NULL)
        return (-1);
	if (left[fd] != NULL)
	{		
		if (seek_more_newline(&left[fd], line) == 1)
			return (1);
	}
	else
		*line = ft_strnew(1);
	newline = NULL;
	return (read_line(newline, fd, left, line));
}
