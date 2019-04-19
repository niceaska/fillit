/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:00:05 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/03 18:08:30 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		podstroka(const char *s1, const char *s2, size_t k, size_t e)
{
	long	i;
	long	n;

	n = 0;
	i = k;
	while (s1[k] == s2[n] && s1[k] && s2[n] && k < e)
	{
		k++;
		n++;
	}
	if (!s2[n])
		return (i);
	if (k >= e)
		return (-2);
	return (-1);
}

char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	size_t	i;
	long	k;

	i = 0;
	if (!needle[i])
		return ((char*)haystack);
	k = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			k = podstroka(haystack, needle, i, len);
			if (k == -2)
				return (NULL);
			if (k != -1)
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
