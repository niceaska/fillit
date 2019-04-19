/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:08:04 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 17:32:15 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void		get_coords(t_tetri **t, char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			(*t)->x[j] = i % 5;
			(*t)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetri		*read_file(char *fname, int fd)
{
	int			r_size;
	int			size;
	char		b[BUF + 1];
	t_tetri		*list;

	list = NULL;
	size = 0;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (NULL);
	if (!(list = init_list(fd, b, &size)))
		return (NULL);
	r_size = (list_size(list) * 20 + list_size(list) - 1);
	if (r_size != size)
	{
		free_list(&list);
		return (NULL);
	}
	close(fd);
	return (list);
}

t_tetri		*init_list(int fd, char *b, int *size)
{
	t_tetri		*list;
	char		l;
	int			rd;

	rd = 0;
	list = NULL;
	l = 'A';
	while ((rd = read(fd, b, 21)) > 0)
	{
		*size += rd;
		if (rd == 20)
			b[rd++] = '\n';
		b[rd] = '\0';
		if (!ch_b(b, 0, 0, 0) || !push_b(&list, l, b))
		{
			free_list(&list);
			break ;
		}
		l++;
	}
	return ((list) ? list : NULL);
}

int			get_start_size(t_tetri *t)
{
	int		size;
	int		sq;

	if (list_size(t) > 26)
		return (0);
	size = list_size(t) * 4;
	sq = 0;
	while (sq * sq < size)
		sq++;
	return (sq);
}

char		**init_table(int size)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(tab[i++] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			free_tab(tab);
			return (NULL);
		}
	}
	tab[i] = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
	}
	return (tab);
}
