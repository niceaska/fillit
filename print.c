/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:46:22 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 15:46:39 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			write(1, &tab[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	pr_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	ft_putstr("	Source file must contain between 1 and 26 Tetriminos.\n");
	ft_putstr("	Example of Tetriminos:\n\n");
	ft_putstr("		..#.	.##.	.##.	.#..	....	....	....\n");
	ft_putstr("		..#.	..#.	.#..	.##.	.##.	..##	##..\n");
	ft_putstr("		..#.	..#.	.#..	.#..	.##.	.##.	.##.\n");
	ft_putstr("		..#.	....	....	....	....	....	....\n\n");
	ft_putstr("	Fillit does not rotate figure to place it in better way.\n");
	ft_putstr("	All rotations of figure counts like a new figure.\n");
	exit(0);
}
