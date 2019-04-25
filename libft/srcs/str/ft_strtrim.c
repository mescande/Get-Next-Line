/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:37:49 by mescande          #+#    #+#             */
/*   Updated: 2019/04/09 20:41:09 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	char	*res;
	char	*cpy;
	size_t	len;

	if (s == NULL)
		return (NULL);
	cpy = (char *)s;
	while (*cpy == ' ' || *cpy == '\n' || *cpy == '\t')
		cpy++;
	len = ft_strlen(cpy);
	res = ft_strnew(len + 1);
	if (res == 0)
		return (0);
	res = ft_strcpy(res, cpy);
	len--;
	while (res[len] == ' ' || res[len] == '\n' || res[len] == '\t')
		res[len--] = '\0';
	cpy = (char *)malloc((ft_strlen(res) + 1) * sizeof(char));
	cpy = ft_strcpy(cpy, res);
	free(res);
	return (cpy);
}
