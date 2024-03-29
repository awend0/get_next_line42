/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:25:45 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/18 07:55:59 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

int		ft_appendremainder(char **remainder, char *buf)
{
	char	*ptr;

	ptr = ft_strnew(ft_strlen(*remainder) + BUFFER_SIZE);
	if (!ptr)
	{
		free(*remainder);
		free(buf);
		return (-1);
	}
	ft_memcpy(ptr, *remainder, ft_strlen(*remainder));
	ft_memcpy(ptr + ft_strlen(*remainder), buf, ft_strlen(buf));
	free(*remainder);
	*remainder = ptr;
	return (0);
}

int		ft_appendline(char **line, char **remainder, char *buf)
{
	char	*new;
	char	*tmp;

	tmp = ft_strchr(*remainder, '\n');
	*line = ft_strnew(tmp - *remainder);
	new = ft_strnew(ft_strlen(*remainder));
	if (!*line || !new)
	{
		free(*remainder);
		free(buf);
		return (-1);
	}
	ft_memcpy(*line, *remainder, (tmp - *remainder));
	*tmp = 0;
	tmp++;
	ft_memcpy(new, tmp, ft_strlen(tmp));
	free(*remainder);
	*remainder = new;
	free(buf);
	return (0);
}

int		ft_appendline2(char **line, char **remainder, char *buf)
{
	*line = ft_strnew(ft_strlen(*remainder));
	if (!*line)
	{
		free(*remainder);
		free(buf);
		return (-1);
	}
	ft_memcpy(*line, *remainder, ft_strlen(*remainder));
	free(*remainder);
	*remainder = 0;
	free(buf);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			readret;

	if (!remainder)
		remainder = ft_strnew(0);
	buf = ft_strnew(BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, NULL, 0)) < 0
		|| !remainder || !buf || !line)
		return (-1);
	while ((readret = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[readret] = 0;
		if (ft_appendremainder(&remainder, buf) == -1)
			return (-1);
		if (ft_strchr(remainder, '\n'))
			return ((ft_appendline(line, &remainder, buf) == -1) ? -1 : 1);
		if (readret < BUFFER_SIZE)
			return ((ft_appendline2(line, &remainder, buf) == -1) ? -1 : 0);
	}
	return (-1);
}
