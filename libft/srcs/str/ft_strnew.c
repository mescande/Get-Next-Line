/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:53:24 by mescande          #+#    #+#             */
/*   Updated: 2019/04/09 20:39:46 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(res = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	ft_bzero((void *)res, size + 1);
	return (res);
}
