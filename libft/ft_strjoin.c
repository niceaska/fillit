/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:45:03 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/02/20 16:52:47 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_join(char const *s1, char const *s2, char *a)
{
	while (*s1 || *s2)
	{
		while (*s1)
		{
			*a = *s1;
			a++;
			s1++;
		}
		while (*s2)
		{
			*a = *s2;
			a++;
			s2++;
		}
	}
	*a = '\0';
	return (a);
}

static size_t	ft_joinlen(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 == 0 && len2 == 0)
		return (1);
	return (len1 + len2);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	len;
	char	*n;

	if (!s1 || !s2)
		return (NULL);
	len = ft_joinlen(s1, s2);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	n = a;
	a = ft_join(s1, s2, a);
	return (n);
}
