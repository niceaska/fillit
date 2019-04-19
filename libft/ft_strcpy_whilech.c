/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_whilech.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:21:05 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/02/23 15:21:18 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strcpy_whilech(char **dst, char *src, char c)
{
	size_t			i;
	size_t			n;

	n = 0;
	i = 0;
	if (!dst || !src)
		return (-1);
	if (*dst)
	{
		free(*dst);
		*dst = NULL;
	}
	while (src[i] && src[i] != c)
		i++;
	if (!(*dst = ft_strnew(i)))
		return (-1);
	while (n < i)
	{
		(*dst)[n] = src[n];
		n++;
	}
	return (i);
}
