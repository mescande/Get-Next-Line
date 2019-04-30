/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:04:17 by mescande          #+#    #+#             */
/*   Updated: 2019/04/30 14:13:44 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_buff
{
	char			*buff;
	int				fd;
	struct s_buff	*prev;
	struct s_buff	*next;
}				t_buff;

int				get_next_line(const int fd, char **line);

#endif
