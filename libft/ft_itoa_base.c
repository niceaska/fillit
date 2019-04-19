/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 05:09:56 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/13 06:17:03 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long			ft_length(size_t n, int osn)
{
	long	len;

	len = 1;
	while (n > (size_t)(osn - 1))
	{
		n /= osn;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(size_t n, int osn)
{
	char	*a;
	long	len;

	if (osn > 16 || osn < 2)
		return ("0");
	len = ft_length(n, osn);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a[len] = '\0';
	while (--len >= 0)
	{
		if (n % osn > 9)
			a[len] = n % osn + 'A' - 10;
		else
			a[len] = n % osn + '0';
		n /= osn;
	}
	return (a);
}
