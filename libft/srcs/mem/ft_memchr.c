/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:07:45 by mescande          #+#    #+#             */
/*   Updated: 2019/04/08 11:30:04 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		a;
	const unsigned char	*si;

	i = -1;
	si = s;
	a = (unsigned char)c;
	while (++i < n)
	{
		if (si[i] == a)
			return ((void *)(s + i));
	}
	return (0);
}
