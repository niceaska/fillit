/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:15:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/07 20:17:14 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t len1;
	size_t len2;

	i = 0;
	k = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	k = len1;
	if (size > len1)
	{
		while (i < size - len1 - 1 && src[i])
		{
			dst[k] = src[i];
			i++;
			k++;
		}
		dst[k] = '\0';
	}
	else
		return (size + len2);
	return (len1 + len2);
}
