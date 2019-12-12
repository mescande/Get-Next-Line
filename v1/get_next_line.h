/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:07:45 by mescande          #+#    #+#             */
/*   Updated: 2019/12/06 18:09:00 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_buff
{
	int				fd;
	char			*buff;
	int				start;
	struct s_buff	*prev;
	struct s_buff	*next;
}				t_buff;

void			erasebuff(t_buff *buff);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strndup(char *s, int i);

int				cleanbuff(t_buff *buff, char **line);
int				react(char **line, t_buff *buff, int val);
t_buff			*binit(t_buff *buff, int fd, t_buff *prev);
int				get_next_line(int fd, char **line);

#endif