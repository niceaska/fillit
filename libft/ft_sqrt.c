/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:14:15 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/25 17:14:47 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb, int opt)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (i * i < nb && (i + 1) * (i + 1) > nb)
		{
			if (opt == -1)
				return (i);
			else
				return (i + 1);
		}
		else if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
