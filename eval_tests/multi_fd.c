/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:15:22 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/21 15:52:26 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //open
#include <stdio.h> //printf

static void gnl_print_free(int fd, char **line)
{
	printf("return: %d\n", get_next_line(fd, line));
	printf("%s\n\n", *line);
	if (*line != NULL)
		ft_strdel(line);
}

int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("empty.txt", O_RDONLY);

	printf("fd1 empty file:\n");
	gnl_print_free(fd1, &line);
	fd2 = open("../get_next_line.h", O_RDONLY);

	printf("fd2 get_next_line.h:\n");
	gnl_print_free(fd2, &line);
	printf("fd1 empty file:\n");
	gnl_print_free(fd1, &line);
	printf("fd2 get_next_line.h:\n");
	gnl_print_free(fd2, &line);
	fd3 = open("4chars_any.txt", O_RDONLY);

	printf("fd3 4chars_any:\n");
	gnl_print_free(fd3, &line);
	printf("fd2 get_next_line.h:\n");
	gnl_print_free(fd2, &line);
	printf("fd3 4chars_any:\n");
	gnl_print_free(fd3, &line);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
