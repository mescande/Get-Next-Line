/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:21 by mescande          #+#    #+#             */
/*   Updated: 2019/12/06 18:17:17 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** 0 : continue la lecture // 2 : \n atteint // 1 : -1 atteint
*/

int		cleanbuff(t_buff *buff, char **line)
{
	int	i;
	int	ret;

	ret = 0;
	i = buff->start;
	while (buff->buff[i] && buff->buff[i] != '\n' && buff->buff[i] != -1)
		i++;
	if (buff->buff[i] == '\n')
	{
		ret = 2;
		if (!(*line = ft_strjoin(*line, ft_strndup(buff->buff + buff->start, i + 1))))
			return (-1);
		erasebuff(buff);
		buff->start = i + 1;
	}
	else if (buff->buff[i] == -1)
	{
		ret = 1;
		if (!(*line = ft_strjoin(*line, buff->buff)))
			return (-1);
		erasebuff(buff);
		buff->start = 0;
	}
	else
		buff->start = 0;
	return (ret);
}

int		react(char **line, t_buff *buff, int val)
{
//	printf("BUFF :'%s'\n", buff->buff);
	if (val == -1 && line)
		free(line);
	if (val <= 0 && buff)
	{
		if (buff->buff)
			free(buff->buff);
		if (buff->prev)
			buff->prev->next = buff->next;
		if (buff->next)
			buff->next->prev = buff->prev;
		free(buff);
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
		while (i == 0 && fd != buff->fd)
			if (buff->next)
				buff = buff->next;
		if (buff->fd != fd && ++i)
			prev = buff;
	}
	if (!buff || i == 1)
	{
		if (!(buff = (t_buff *)malloc(sizeof(t_buff))) ||
				!(buff->buff = (char *)malloc(BUFFER_SIZE + 1)))
			return (NULL);
		buff->fd = (fd < 0 ? -fd : fd);
		buff->start = 0;
		buff->prev = prev;
		buff->next = NULL;
		buff->buff[BUFFER_SIZE] = 0;
	}
	return (buff);
}

int		get_next_line(int fd, char **line)
{
	static t_buff	*buff;
	int				red;

	*line = ft_strndup("", 0);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(buff = binit(buff, fd, buff)))
		return (-1);
	if (buff->start)
	{
		*line = ft_strjoin(NULL, (buff->buff + buff->start));
		erasebuff(buff);
		if ((red = cleanbuff(buff, line)))
			return (react(line, buff, red - 1));
	}
	buff->buff[BUFFER_SIZE] = 0;
	while ((red = read(fd, buff->buff, BUFFER_SIZE)))
	{
		if (red == -1)
			return (react(line, buff, -1));
		if ((red = cleanbuff(buff, line)))
			return (react(line, buff, red - 1));
		if (!(*line = ft_strjoin(*line, buff->buff)))
			return (react(line, buff, -1));
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		val;
	char	**line;
	int		fd;
	int		i;

//	fd = open((ac == 1 ? "get_next_line_utils.c" : av[1]), O_RDONLY);
	fd = open((ac == 1 ? "test" : av[1]), O_RDONLY);
	line = malloc(145 * sizeof(char *));
	i = 0;
	while ((val = get_next_line(fd, line + i)) && i  < 145)
	{
		if (val == -1)
		{
			if (line)
				free(line);
			printf("GNL exit with -1");
			return (1);
		}
		printf("main '%s'\n", line[i]);
		i++;
	}
	printf("ma 0 '%s'\n", (line[i] ? line[i] : line[i - 1]));
	printf("T'es a la fin mon vieux\n");
	if (line)
		free(line);
	return (0);
}
