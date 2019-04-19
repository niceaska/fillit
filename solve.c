/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:10:42 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 17:29:25 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int			check_valid(char **map, t_tetri *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[t->y[i]][t->x[i]] != '.' ||
				!map[t->y[i]][t->x[i]])
			return (0);
		i++;
	}
	return (1);
}

static void	place(char **map, t_tetri *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[t->y[i]][t->x[i]] = t->letter;
		i++;
	}
}

static void	unplace(char **map, t_tetri *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[t->y[i]][t->x[i]] = '.';
		i++;
	}
}

int			solve(char **map, int size, t_tetri **t)
{
	if (!*t)
		return (1);
	*t = move_to_start_y(*t);
	while (MAX(MAX((*t)->y[0], (*t)->y[1]),\
		MAX((*t)->y[2], (*t)->y[3])) < size)
	{
		*t = move_to_start_x(*t);
		while (MAX(MAX((*t)->x[0], (*t)->x[1]),\
			MAX((*t)->x[2], (*t)->x[3])) < size)
		{
			if (check_valid(map, *t))
			{
				place(map, *t);
				if (solve(map, size, &((*t)->next)))
					return (1);
				unplace(map, *t);
			}
			x_to_right((*t)->x);
		}
		y_down((*t)->y);
	}
	return (0);
}
