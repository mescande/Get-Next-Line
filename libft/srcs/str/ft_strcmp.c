/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:41:49 by mescande          #+#    #+#             */
/*   Updated: 2019/04/12 21:17:59 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t pos;

	pos = 0;
	while ((unsigned char)s1[pos] == (unsigned char)s2[pos] && s1[pos] != '\0')
		pos++;
	if (s1[pos] == '\0')
	{
		if (s2[pos] == '\0')
			return (0);
		return (-1);
	}
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
