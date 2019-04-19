/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:56:01 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/15 18:33:59 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		push_b(t_tetri **begin, char letter, char *buf)
{
	t_tetri	*temp;
	t_tetri	*swp;

	if (!begin || !(temp = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	temp->letter = letter;
	temp->next = NULL;
	get_coords(&temp, buf);
	temp = move_to_start_x(temp);
	temp = move_to_start_y(temp);
	if (!*begin)
	{
		*begin = temp;
		return (1);
	}
	swp = *begin;
	while (swp->next)
		swp = swp->next;
	swp->next = temp;
	return (1);
}

int		list_size(t_tetri *begin)
{
	int		i;
	t_tetri	*node;

	i = 0;
	if (!begin)
		return (0);
	node = begin;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	back_to_start(t_tetri **begin)
{
	t_tetri *node;

	if (!*begin || !begin)
		return ;
	node = *begin;
	while (node)
	{
		node = move_to_start_x(node);
		node = move_to_start_y(node);
		node = node->next;
	}
}
