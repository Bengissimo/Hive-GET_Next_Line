/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:57:11 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/15 22:58:31 by bkandemi         ###   ########.fr       */
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

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(line, "123") != 1)
		{
			printf("adv [ko]\n");
			//if (line != NULL)
			//free(line);
		}
		printf("line: %s\n", line);
		if (line != NULL)
			free(line);
	}	
	printf("adv [ok]\n");
	return (0);
}
