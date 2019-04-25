/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:34:25 by mescande          #+#    #+#             */
/*   Updated: 2019/04/13 18:12:12 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	testsep(char *str, const char *sep)
{
	size_t	len;
	size_t	n;

	len = ft_strlen(sep);
	n = 0;
	while (n < len)
		if (*str == sep[n++])
			return (1);
	return (0);
}

char		*ft_strtok(char *str, const char *sep)
{
	static char	*sttc_str;
	size_t		len;
	size_t		n;
	char		*res;

	n = 0;
	len = 0;
	if (str != NULL)
		sttc_str = str;
	while (*sttc_str && testsep(sttc_str, sep))
		sttc_str++;
	if (*sttc_str == 0)
		return (0);
	while (sttc_str[len] && !testsep(sttc_str + len, sep))
		len++;
	res = sttc_str;
	if (sttc_str[len] != '\0')
	{
		sttc_str[len] = '\0';
		sttc_str += len + 1;
	}
	else
		sttc_str += len;
	return (res);
}
