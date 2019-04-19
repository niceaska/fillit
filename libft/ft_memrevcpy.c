/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:57:43 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/07 18:01:11 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrevcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 1;
	while (i < n + 1)
	{
		((unsigned char*)dst)[n - i] = ((unsigned char*)src)[n - i];
		i++;
	}
	return (dst);
}
