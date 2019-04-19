/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:24:58 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/13 22:24:59 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchr_swap(char **s, int a, int b)
{
	size_t	i;
	char	*tmp;

	if (!s || !*s || !**s)
		return ;
	i = -1;
	tmp = ft_strdup(*s);
	while ((*s)[++i])
		if ((*s)[i] == a)
			(*s)[i] = b;
	i = -1;
	while (tmp[++i])
		if (tmp[i] == b)
			(*s)[i] = a;
	free(tmp);
}
