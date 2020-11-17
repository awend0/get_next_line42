/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:46:29 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/17 19:48:31 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				main(int argc, char **argv)
{
	int			fd;
	char		*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
			printf("\033[1;31m%s\033[0m\n", line);
		printf("\033[1;31m%s\033[0m\n", line);
		close(fd);
	}
	return (0);
}