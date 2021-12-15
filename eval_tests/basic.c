/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:37 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/15 22:58:27 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl;
	int		count;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	count = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "1234567") != 1)
		{
			printf("basic: [ko]\n");
			return (1);
		}
		printf("line: %s\n", line);
		count++;
		if (line != NULL)
			free(line);
	}
	printf("basic: [ok]\n");
	return (0);
}
