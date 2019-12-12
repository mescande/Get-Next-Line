/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:49:39 by mescande          #+#    #+#             */
/*   Updated: 2019/12/06 18:09:31 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	erasebuff(t_buff *buff)
{
	int i;
	int	j;

	j = -1;
	i = 0;
	while (i < BUFFER_SIZE && buff->buff[i] != '\n')
		i++;
	while (++j < BUFFER_SIZE)
		buff->buff[j] = (i + j > BUFFER_SIZE ? 0 : buff->buff[i + j]);
	return ;
}

void	cpybuff(char *s2, char *res, int i, int j)
{
	res[i + j] = s2[j];
//	s2[j] = (i + j > BUFFER_SIZE ? 0 : s2[i + j]);
//	printf("i + j =\t%d\ns2[j] =\t%c\ns2[i+j]=%c\n", i+j, s2[j], s2[i+j]);
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2[j] && s2[j] != '\n' && s2[j] != -1)
		j++;
	if (!(res = malloc(i + j + 1)))
		return (NULL);
	i = (s1 ? -1 : 0);
	j = 0;
	while (s1 && s1[++i])
		res[i] = s1[i];
//	printf("\ns2'%s'\n", s2);
	while (s2[j] && s2[j] != '\n' && s2[j] != -1)
		cpybuff(s2, res, i, j++);
//	printf("\ns2'%s'\n", s2);
	res[i + j] = 0;
	if (s1)
		free(s1);
	return (res);
}

char	*ft_strndup(char *s, int i)
{
	char	*res;
	int		j;

	j = 0;
	if (!(res = malloc(i + 1)))
		return (NULL);
	while (j < i)
	{
		res[j] = s[j];
		j++;
	}
	res[j] = 0;
	return (res);
}
