/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:27:49 by mescande          #+#    #+#             */
/*   Updated: 2019/04/09 20:38:30 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char *)malloc(++len * sizeof(char));
	if (s2 == 0)
		return (s2);
	while (--len != 0)
		s2[len] = s1[len];
	s2[0] = s1[0];
	return (s2);
}
