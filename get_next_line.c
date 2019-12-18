/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:21 by mescande          #+#    #+#             */
/*   Updated: 2019/12/18 20:18:06 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** 0 : continue la lecture // 2 : \n atteint // 1 : -1 atteint
*/

int		erasebuff(t_buff *buff)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (buff->buff[i] != '\n' && buff->buff[i] && buff->buff[i] != -1)
		i++;
	if (buff->buff[i] == '\n')
		ret = 2;
	if (buff->buff[i] == -1)
		ret = 1;
	j = -1;
	i++;
	while (buff->buff[++j])
		buff->buff[j] = (i + j > BUFFER_SIZE ? 0 : buff->buff[i + j]);
	return (ret);
}

int		react(char **line, t_buff **buff, int val)
{
	t_buff	*tmp;

	if (line && val == -1)
		free(*line);
	if (buff[0] && val <= 0)
	{
		if (buff[0]->buff)
			free(buff[0]->buff);
		if (buff[0]->prev)
			buff[0]->prev->next = buff[0]->next;
		if (buff[0]->next)
			buff[0]->next->prev = buff[0]->prev;
		tmp = buff[0];
		if (buff[0]->prev)
			buff[0] = buff[0]->prev;
		else if (buff[0]->next)
			buff[0] = buff[0]->next;
		else
			buff[0] = NULL;
		free(tmp);
	}
	return (val);
}

t_buff	*binit(t_buff *buff, int fd, t_buff *prev)
{
	int i;

	i = 0;
	if (buff)
	{
		while (buff->prev)
			buff = buff->prev;
		while (i == 0 && fd != buff->fd && buff->next)
			buff = buff->next;
		if (buff->fd != fd && (i += 1))
			prev = buff;
	}
	if (!buff || i == 1)
	{
		if (!(buff = (t_buff *)ft_memalloc(sizeof(t_buff))) ||
				!(buff->buff = (char *)ft_memalloc(BUFFER_SIZE + 1)))
			return (NULL);
		buff->fd = fd;
		buff->prev = prev;
		if (!(buff->next = NULL) && prev)
			prev->next = buff;
		buff->buff[BUFFER_SIZE] = 0;
	}
	return (buff);
}

int		get_next_line(int fd, char **line)
{
	static t_buff	*buff = NULL;
	int				red;

	if (!line || !(*line = ft_strndup("", 0)) || fd < 0 || BUFFER_SIZE <= 0 ||
			!(buff = binit(buff, fd, buff)))
		return (react(line, &buff, -1));
	if (buff->buff[0])
	{
		*line = ft_strjoin(*line, buff->buff);
		if ((red = erasebuff(buff)))
			return (react(line, &buff, red - 1));
	}
	while ((red = read(fd, buff->buff, BUFFER_SIZE)))
	{
		if (red == -1)
			return (react(line, &buff, -1));
		if (!(*line = ft_strjoin(*line, buff->buff)))
			return (react(line, &buff, -1));
		if ((red = erasebuff(buff)))
			return (react(line, &buff, red - 1));
	}
	return (react(line, &buff, 0));
}
