/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:46:29 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/17 20:03:40 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			i = get_next_line(fd, &line);
			if (i == 1)
				printf("\033[1;31m%s\033[0m\n", line);
			else if (i == -1)
			{
				printf("\033[1;31mError\033[0m\n");
				break;
			}
			else if (i == 0)
			{
				printf("\033[1;31m%s\033[0m\n", line);
				break;
			}
		}
		close(fd);
	}
	return (0);
}