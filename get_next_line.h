/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymun <mraymun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:58 by mraymun           #+#    #+#             */
/*   Updated: 2020/11/18 07:56:01 by mraymun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strnew(int size);
char	*ft_strchr(char *s, int c);
void	*ft_memalloc(int size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(char *str);

#endif
