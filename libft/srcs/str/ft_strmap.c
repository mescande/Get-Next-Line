/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:45:10 by mescande          #+#    #+#             */
/*   Updated: 2019/04/08 20:25:20 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *res;
	char *tmp;

	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res == NULL || s == NULL)
		return (NULL);
	tmp = res;
	while (*s != '\0')
		*(tmp++) = f(*(s++));
	*tmp = '\0';
	return (res);
}
