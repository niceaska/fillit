/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:38:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/18 20:51:56 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_coord		*ft_create_coords(int x, int y)
{
	t_coord *a;

	if (!(a = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	a->x = x;
	a->y = y;
	return (a);
}
