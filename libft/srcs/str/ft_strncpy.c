/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:09:56 by mescande          #+#    #+#             */
/*   Updated: 2019/04/08 18:07:26 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t l;

	l = -1;
	while (src[++l] != '\0' && l < len)
		dst[l] = src[l];
	if (l != len)
		while (l < len)
			dst[l++] = '\0';
	return (dst);
}
