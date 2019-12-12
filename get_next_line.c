/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:21 by mescande          #+#    #+#             */
/*   Updated: 2019/12/12 14:40:58 by mescande         ###   ########.fr       */
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

int		react(char **line, t_buff *buff, int val)
{
	if (line && val == -1)
		free(line);
	if (buff && val <= 0)
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
		while (i == 0 && fd != buff->fd && buff->next)
			buff = buff->next;
		if (buff->fd != fd && (i += 1))
			prev = buff;
	}
	if (!buff || i == 1)
	{
		if (!(buff = (t_buff *)malloc(sizeof(t_buff))) ||
				!(buff->buff = (char *)malloc(BUFFER_SIZE + 1)))
			return (NULL);
		buff->fd = (fd < 0 ? -fd : fd);
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

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(buff = binit(buff, fd, buff))
			|| !(*line = ft_strndup("", 0)))
		return (-1);
	if (buff->buff[0])
	{
		*line = ft_strjoin(*line, buff->buff);
		if ((red = erasebuff(buff)))
			return (react(line, buff, red - 1));
	}
	while ((red = read(fd, buff->buff, BUFFER_SIZE)))
	{
		if (red == -1)
			return (react(line, buff, -1));
		if (!(*line = ft_strjoin(*line, buff->buff)))
			return (react(line, buff, -1));
		if ((red = erasebuff(buff)))
			return (react(line, buff, red - 1));
	}
	return (0);
}
/*
int		main(int ac, char **av)
{
	int		val;
	char	**line;
	int		fd;
	int		i;
//	int		fs;

//	fd = open((ac == 1 ? "get_next_line_utils.c" : av[1]), O_RDONLY);
	line = malloc(145 * sizeof(char *));
	fd = open((ac == 1 ? "test" : av[1]), O_RDONLY);
//	fs = open((ac == 1 ? "test" : av[1]), O_RDONLY);
	i = 0;
	while (((val = get_next_line((i%2 == 0 ? fd : fs), line + i))) && i  < 145)
	{
		if (val == -1)
		{
			//if (line)
				free(line);
			printf("GNL exit with -1");
			return (1);
		}
		printf("main '%s'\n", line[i]);
		fflush(stdout);
		free(line[i]);
		i++;
	}
	printf("ma 0 '%s'\n", (line[i] ? line[i] : line[i - 1]));
	free(line[i]);
	printf("T'es a la fin mon vieux\n");
	if (line)
		free(line);
	return (0);
}*/
