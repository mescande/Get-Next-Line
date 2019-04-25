/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:07:06 by mescande          #+#    #+#             */
/*   Updated: 2019/04/25 04:49:03 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		end_in_buff(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n' || *buff == -1)
			return (1);
		buff++;
	}
	return (0);
}

int		ft_retfree(void *buff)
{
	free(buff);
	return (-1);
}

int		returnvalue(char **buff, char **line)
{
	int		i;
	char	*tmp;
	char	*save;
	int		len;

	i = 0;
	if (!(tmp = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (ft_retfree(*line));
	while (buff[0][i] != '\n' && buff[0][i] != -1)
	{
		tmp[i] = buff[0][i];
		i++;
	}
	save = ft_strjoin(*line, tmp);
	free(tmp);
	free(*line);
	*line = save;
	if (buff[0][i] == -1)
		return (ft_retfree(*buff));
	len = ft_strlen(*buff);
	*buff = ft_memmove((void *)(*buff), (void *)((*buff) + i + 1), len - i);
	ft_bzero(buff[0] + len - i, len - (i + 1));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	char			*tmp;
	ssize_t			val;

	if (!buff)
		if (!(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
	val = 1;
	*line = ft_strnew(1);
	while (buff && val)
	{
		if (end_in_buff(buff))
			return (returnvalue(&buff, line));
		else
		{
			tmp = ft_strjoin(*line, buff);
			free(*line);
			*line = tmp;
			ft_bzero(buff, BUFF_SIZE + 1);
			if ((val = read(fd, buff, BUFF_SIZE)) == -1)
				return (ft_retfree(*line));
		}
	}
	return (0);
}
