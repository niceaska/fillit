/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:11:23 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/15 18:19:48 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int		find_sharps(char *line, int i, int opt)
{
	static int	k;

	if (opt == 1)
	{
		k = 0;
	}
	while (line[i] && (line[i] != '#'))
		i++;
	if (line[i] == '#')
	{
		k++;
		line[i] = 'F';
		if (i < 19 && line[i + 1] == '#')
			find_sharps(line, i + 1, 0);
		if (i > 0 && line[i - 1] == '#')
			find_sharps(line, i - 1, 0);
		if (i < 15 && line[i + 5] == '#')
			find_sharps(line, i + 4, 0);
		if (i > 4 && line[i - 5] == '#')
			find_sharps(line, i - 4, 0);
	}
	return (k);
}

int				ch_b(char *buf, int line, int i, int nl)
{
	if (!*buf || !buf)
		return (0);
	if (ft_countchars(buf, '#') != 4)
		return (0);
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '.' || buf[i] == '#')
			line++;
		else if (buf[i] == '\n')
		{
			nl++;
			if (line != 4 && i != 20)
				return (0);
			line = 0;
		}
		i++;
	}
	if (find_sharps(buf, 0, 1) != 4)
		return (0);
	ft_strchr_swap(&buf, 'F', '#');
	return ((nl != 5) ? 0 : 1);
}
