/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:45:11 by mescande          #+#    #+#             */
/*   Updated: 2019/04/12 11:49:06 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	return ((47 < (unsigned char)c && (unsigned char)c < 58) ||
			(64 < (unsigned char)c && (unsigned char)c < 71) ||
			(96 < (unsigned char)c && (unsigned char)c < 103));
}
