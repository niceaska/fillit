/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:53:17 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/03 17:39:04 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		podstroka(const char *s1, const char *s2, size_t k)
{
	long	i;
	long	n;

	n = 0;
	i = k;
	while (s1[k] == s2[n] && s1[k] && s2[n])
	{
		k++;
		n++;
	}
	if (!s2[n])
		return (i);
	return (-1);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	long	k;

	i = 0;
	k = 0;
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i])
	{
		k = podstroka(haystack, needle, i);
		if (k != -1)
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
