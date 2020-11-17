/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:25:45 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/17 18:55:07 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_appendremainder(char **remainder, char *buf)
{
	char	*ptr;

	ptr = ft_strnew(ft_strlen(*remainder) + BUFF_SIZE);
	if (!ptr)
		return (-1);
	ft_memcpy(ptr, *remainder, ft_strlen(*remainder));
	ft_memcpy(ptr + ft_strlen(*remainder), buf, ft_strlen(buf));
	free(*remainder);
	*remainder = ptr;
	return (0);
}

int		ft_appendline(char **line, char **remainder)
{
	char	*ptr;
	char	*new;
	char	*tmp;

	ptr = ft_strnew(ft_strlen(*remainder) + BUFF_SIZE);
	new = ft_strnew(ft_strlen(*remainder));
	if (!ptr || !new)
		return (-1);
	ft_memcpy(ptr, *line, ft_strlen(*line));
	tmp = ft_strchr(*remainder, '\n');
	ft_memcpy(ptr + ft_strlen(*line), *remainder, (tmp - *remainder));
	free(*line);
	*line = ptr;
	*tmp = 0;
	tmp++;
	ft_memcpy(new, tmp, ft_strlen(tmp));
	free(*remainder);
	*remainder = new;
	return (0);
}

int		ft_appendline2(char **line, char **remainder, char **buf)
{
	char	*ptr;

	ptr = ft_strnew(ft_strlen(*line) + BUFF_SIZE);
	if (!ptr)
		return (-1);
	ft_memcpy(ptr, *line, ft_strlen(*line));
	ft_memcpy(ptr + ft_strlen(*line), *remainder, ft_strlen(*remainder));
	free(*line);
	*line = ptr;
	free(*remainder);
	*remainder = 0;
	free(*buf);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			readret;

	if (!remainder)
		remainder = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (!remainder || !buf || !line || fd < 0)
		return (-1);
	while ((readret = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		buf[readret] = 0;
		if (ft_appendremainder(&remainder, buf) == -1)
			return (-1);
		if (ft_strchr(remainder, '\n'))
			return ((ft_appendline(line, &remainder) == -1) ? -1 : 1);
		if (readret < BUFF_SIZE)
			return ((ft_appendline2(line, &remainder, &buf) == -1) ? -1 : 0);
	}
	return (-1);
}
