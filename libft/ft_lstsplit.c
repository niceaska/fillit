/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:31:52 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/13 06:45:18 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		countwords(char const *s, char c)
{
	long	k;
	size_t	i;

	k = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			k++;
		}
		if (s[i] == c)
			while (s[i] == c && s[i])
				i++;
	}
	return (k);
}

static int		writeword(char const *s, t_list **a, size_t len)
{
	size_t	k;
	char	*tmp;
	size_t	i;
	t_list	*b;

	k = 0;
	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[k] && k < len)
		tmp[i++] = s[k++];
	tmp[i] = '\0';
	if (!(b = ft_lstnew(tmp, len)))
		return (0);
	ft_lstadd(a, b);
	return (1);
}

t_list			*ft_lstsplit(char const *s, char c)
{
	long	i;
	long	count;
	long	nb;
	t_list	*a;
	size_t	end;

	nb = 0;
	count = countwords(s, c);
	if (count == -1 || !(a = ft_lstnew(NULL, 0)))
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i > 0 && nb++ < count)
	{
		while (i > 0 && s[i] == c)
			i--;
		end = i;
		while (i > -1 && s[i] != c)
			i--;
		if (!writeword(s + i + 1, &a, end - i))
		{
			ft_lstdel(&a, &ft_bzero);
			return (NULL);
		}
	}
	return (a);
}
