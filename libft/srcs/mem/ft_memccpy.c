/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:42:12 by mescande          #+#    #+#             */
/*   Updated: 2019/04/13 18:03:10 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dsti;
	const unsigned char	*srci;

	i = 0;
	dsti = (unsigned char *)dst;
	srci = (unsigned char *)src;
	while (i < n)
	{
		dsti[i] = srci[i];
		if ((unsigned char)srci[i++] == (unsigned char)c)
			return (dst + i);
	}
	return (0);
}
