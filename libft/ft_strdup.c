/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:57:55 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/13 06:16:55 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		while (i < len)
		{
			a[i] = s1[i];
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
