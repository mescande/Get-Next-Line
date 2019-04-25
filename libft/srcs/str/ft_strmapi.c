/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:51:17 by mescande          #+#    #+#             */
/*   Updated: 2019/04/08 20:26:51 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;

	len = 0;
	if (s == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res == NULL || s == NULL)
		return (NULL);
	while (s[len] != '\0')
	{
		res[len] = f(len, s[len]);
		len++;
	}
	res[len] = 0;
	return (res);
}
