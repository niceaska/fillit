/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:56:43 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/10 21:11:26 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*recording(char const *s, long n, long k, char *a)
{
	size_t i;

	i = 0;
	while (n <= k)
	{
		a[i] = s[n];
		n++;
		i++;
	}
	a[i] = '\0';
	return (a);
}

char		*ft_strtrim(char const *s)
{
	long	k;
	char	*a;
	long	n;

	if (!s)
		return (NULL);
	n = 0;
	k = ft_strlen(s) - 1;
	while (n <= k && (s[n] == 32 || s[n] == '\n' || s[n] == '\t'))
		n++;
	while (k >= 0 && (s[k] == 32 || s[k] == '\n' || s[k] == '\t'))
		k--;
	if (k >= n)
		a = (char*)malloc(sizeof(char) * (k - n + 2));
	else
		a = (char*)malloc(sizeof(char));
	if (!a)
		return (NULL);
	a = recording(s, n, k, a);
	return (a);
}
