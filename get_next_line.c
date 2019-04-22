/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:04:34 by mescande          #+#    #+#             */
/*   Updated: 2019/04/22 15:53:14 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memrealloc(void *src, size_t size)
{
	void *dst;

	if (!(dst = malloc(size)))
		return (NULL);
	if (src == NULL)
		return (dst);
	ft_bzero(dst, size);
	dst = ft_memcpy(dst, src, size);
	ft_bzero(src, size);
//	free(src);
	return (dst);
}

int		noend(char *buff)
{
	int i;

	i = -1;
	while (++i < BUFF_SIZE)
		if (buff[i] == '\n' || buff[i] == -1)
			return (i);
	return (-1);
}

int		end(char **line, char **buff, int len)
{
	int 	i;

	i = 0;
	while (buff[0][i] != '\n' && buff[0][i] != -1 && i < BUFF_SIZE)
		line[0][len++] = buff[0][i++];
	if (!(*line = (char *)ft_memrealloc(*line, len + 1)))
		return (-1);
	line[0][len] = '\0';
	if (buff[0][i] == -1)
		return (0);
	if (buff[0][i + 1] == '\0')
		buff[0] = NULL;
	else
		buff[0] += i + 1;
	return (1);
}

size_t	ft_strcpynreturn(char *dst, char **src, int len)
{
	size_t	l;

	l = 0;
	while (src[0][l] != '\0' && src[0][l] != '\n' && src[0][l] != -1)
	{
		dst[l] = src[0][l];
		l++;
	}
	dst[l] = '\0';
	if (src[0][l] == -1)
	{
		src[0] = NULL;
		return (-2);
	}
	if (src[0][l] == '\n')
	{
		src[0] += l + 1;
		return (-1);
	}
	return (l + len);
}

int		get_next_line(const int fd, char **line)
{
	int			len;
	int			nbr_buff;
	static char	*buff;

	len = 0;
	nbr_buff = 2;
	if (!(*line = (char *)ft_memrealloc(NULL, nbr_buff * BUFF_SIZE)))
		return (-1);
	if (buff)
		len = ft_strcpynreturn(*line, &buff, len);
	if (!(buff = (char *)ft_memrealloc(buff, BUFF_SIZE + 1)))
		return (-1);
	if (len < 0)
		return (len == -1 ? 1 : 0);
	while (read(fd, buff, BUFF_SIZE))
	{
//		if (!(*line = (char *)ft_memrealloc(*line, nbr_buff++ * BUFF_SIZE)))
//			return (-1);
		if (noend(buff) == -1)
//		{
//			printf("Line : %s\nBuff ; %s\t\t%d, %d\n", *line, buff, len, nbr_buff);
			*line = ft_strjoin(*line, buff);
//			printf("line ; %s\n", *line);
//		}
		else
			return (end(line, &buff, len));
		len += BUFF_SIZE;
	}
	return (0);
}
