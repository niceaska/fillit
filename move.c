/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:12:15 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 15:12:28 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

t_tetri	*move_to_start_x(t_tetri *t)
{
	int i;

	while (MIN(MIN(t->x[0], t->x[1]),\
		MIN(t->x[2], t->x[3])) > 0)
	{
		i = 0;
		while (i < 4)
			t->x[i++]--;
	}
	return (t);
}

t_tetri	*move_to_start_y(t_tetri *t)
{
	int i;

	while (MIN(MIN(t->y[0], t->y[1]),\
		MIN(t->y[2], t->y[3])) > 0)
	{
		i = 0;
		while (i < 4)
			t->y[i++]--;
	}
	return (t);
}

void	x_to_right(int x[4])
{
	int i;

	i = 0;
	while (i < 4)
		x[i++]++;
}

void	y_down(int y[4])
{
	int i;

	i = 0;
	while (i < 4)
		y[i++]++;
}
