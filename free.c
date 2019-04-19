/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:57:47 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/15 12:58:20 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tetris.h"

void	free_list(t_tetri **list)
{
	t_tetri *t;

	if (*list != NULL && list != NULL)
	{
		while (*list)
		{
			t = *list;
			*list = (*list)->next;
			free(t);
		}
		*list = NULL;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			if (tab[i] != NULL)
				free(tab[i++]);
		free(tab);
		tab = NULL;
	}
}
