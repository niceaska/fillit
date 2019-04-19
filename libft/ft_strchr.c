/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:32:42 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/04 14:20:47 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *a;

	if (!s)
		return (NULL);
	a = (char*)s;
	while (*a)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	if (c == '\0')
		return (a);
	return (NULL);
}
