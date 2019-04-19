/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:49:13 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/02/19 15:49:31 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	if (!(a = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero((void*)a, size + 1);
	return (a);
}
