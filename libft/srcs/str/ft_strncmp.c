/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:44 by mescande          #+#    #+#             */
/*   Updated: 2019/04/12 21:38:57 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t pos;

	pos = 0;
	while ((unsigned char)s1[pos] == (unsigned char)s2[pos] &&
			s1[pos] != '\0' && pos < n)
		pos++;
	if (s1[pos] == '\0' || pos == n)
	{
		if (s2[pos] == '\0' || pos == n)
			return (0);
		return (-1);
	}
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
