/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:24:48 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/13 22:24:49 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchr_replace(char **s, int old, int new)
{
	size_t	i;

	if (!s || !*s || !**s)
		return ;
	i = -1;
	while ((*s)[++i])
		if ((*s)[i] == old)
			(*s)[i] = new;
}
