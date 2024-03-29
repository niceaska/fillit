/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 04:05:01 by gwyman-m          #+#    #+#             */
/*   Updated: 2018/12/12 05:26:50 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numlen(size_t num)
{
	int k;

	k = 1;
	while (num > 9)
	{
		k++;
		num /= 10;
	}
	return (k);
}
