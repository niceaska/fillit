/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:25:08 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 17:33:14 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int			main(int argc, char **argv)
{
	t_tetri		*t;
	int			size;
	char		**tab;

	if (argc != 2)
		pr_usage();
	t = read_file(argv[1], 0);
	size = get_start_size(t);
	tab = init_table(size);
	if (!t || !tab || !size)
	{
		free_tab(tab);
		free_list(&t);
		print_error();
	}
	while (!solve(tab, size, &t))
	{
		free_tab(tab);
		tab = init_table(++size);
		back_to_start(&t);
	}
	print_tab(tab);
	free_list(&t);
	free_tab(tab);
	return (0);
}
