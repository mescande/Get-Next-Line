/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:18:23 by mescande          #+#    #+#             */
/*   Updated: 2019/04/08 11:29:16 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	pos;
	size_t	srch;

	pos = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[pos] != '\0')
	{
		srch = 0;
		while (haystack[pos + srch] != '\0' && needle[srch] != '\0' &&
				haystack[pos + srch] == needle[srch])
			srch++;
		if (needle[srch] == '\0')
			return ((char *)(haystack + pos));
		pos++;
	}
	return (0);
}
