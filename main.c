/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:33:47 by mescande          #+#    #+#             */
/*   Updated: 2019/04/30 15:41:21 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
//	if (ac != 2)
//		return (-1);
	char **line;
	int fd = open("nou", O_RDONLY);
	int i = 0;
	line = (char **)malloc(15 * sizeof(char *));
	while (ac && get_next_line(fd, line + i))
	{
		printf("%s\nmain\n", line[i++]);
		fflush(stdout);
	}
//	while (1)
//		;
	return (0);
}
