/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:37:04 by mescande          #+#    #+#             */
/*   Updated: 2019/12/18 20:19:20 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		val;
	char	*line;
	int		fd;
	int		i;
//	int		fs;

//	fd = open((ac == 1 ? "get_next_line_utils.c" : av[1]), O_RDONLY);
	fd = open((ac <= 1 ? "test" : av[1]), O_RDONLY);
//	fs = open((ac <= 2 ? "test" : av[2]), O_RDONLY);
	i = 0;
	while (((val = get_next_line(/*(i%2 == 0 ? fd : fs)*/fd, &line))) && i  < 145)
	{
		if (val == -1)
		{
			printf("GNL exit with -1\n");
			return (1);
		}
		printf("%s\n", line);
		fflush(stdout);
		free(line);
		i++;
	}
	printf("%s\n", line);
	fflush(stdout);
	free(line);
//	printf("T'es a la fin mon vieux\n");
	while (1)
		;
	return (0);
}
