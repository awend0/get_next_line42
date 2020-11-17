/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:28:39 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/17 18:51:12 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(int size)
{
	return ((char*)ft_memalloc(sizeof(char) * (size + 1)));
}

char	*ft_strchr(char *s, int c)
{
	while (*s && !(*s == c))
		s++;
	return ((*s == c) ? s : 0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	if (!dst)
		return (0);
	source = src;
	dest = dst;
	while (n--)
		*dest++ = *source++;
	return (dst);
}

void	*ft_memalloc(int size)
{
	void	*ptr;
	char	*tmp;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	tmp = ptr;
	while (size--)
		*tmp++ = '\0';
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	return (size);
}
