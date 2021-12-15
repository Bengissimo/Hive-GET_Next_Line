/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_newline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:56:44 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/15 22:48:18 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl;
	int		fd_42 = 42;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_strequ(argv[1], "4chars_no_nl.txt") == 1){
			if (ft_strequ(line, "1234") != 1)
			{
				printf("line: %s\n", line);
				printf("4 chars w/o newline [ko]\n");
				if (line != NULL)
				free(line);
				return (1);
			}
			else{
				printf("no new line test [ok]\n");
				return (0);
			}
		}
		
		if (ft_strequ(argv[1], "8chars_no_nl.txt") == 1){
			if (ft_strequ(line, "12345678") != 1)
			{
				printf("line: %s\n", line);
				printf("8 chars w/o newline [ko]\n");
				if (line != NULL)
				free(line);
				return (1);
			}
			else{
				printf("no new line test [ok]\n");
				return (0);
			}
		}
		
		if (ft_strequ(argv[1], "16chars_no_nl.txt") == 1){
			if (ft_strequ(line, "1234567812345678") != 1)
			{
				printf("line: %s\n", line);
				printf("16 chars w/o newline [ko]\n");
				if (line != NULL)
				free(line);
				return (1);
			}
			else{
				printf("no new line test [ok]\n");
				return (0);
			}
		}
		if (ft_strequ(argv[1], "empty_line.txt") == 1){
			
			if (ft_strequ(line, "") != 1)
			{
				printf("empty line [ko]\n");
				return (1);
			}
			else{
				printf("line: %s\n", line);
				printf("empty line [ok]\n");
				if (line != NULL)
				free(line);
			}
		}
	}	
	gnl = get_next_line(fd_42, &line);
	printf("fd 42 returns: %d \n", gnl);
	if(gnl != -1)
	{
		printf("fd 42 [ko]\n");
		return (1);
	}
	return (0);
}
