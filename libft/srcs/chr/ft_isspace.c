/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:37:19 by mescande          #+#    #+#             */
/*   Updated: 2019/04/12 12:03:34 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return ((unsigned char)c == '\t' || (unsigned char)c == '\n' ||
			(unsigned char)c == '\v' || (unsigned char)c == '\f' ||
			(unsigned char)c == '\r' || (unsigned char)c == ' ');
}
