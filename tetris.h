/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:25:18 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/15 18:37:04 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H
# define BUF 21
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define MAX(x, y) (((x) > (y)) ? (x) : (y))

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_tetri
{
	int				x[4];
	int				y[4];
	char			letter;
	struct s_tetri	*next;

}					t_tetri;

int					list_size(t_tetri *begin);
int					push_b(t_tetri **begin, char letter, char *buf);
void				get_coords(t_tetri **t, char *buf);
t_tetri				*read_file(char *fname, int fd);
t_tetri				*move_to_start_xy(t_tetri *t);
void				x_to_right(int x[4]);
void				y_down(int y[4]);
void				print_tab(char **tab);
int					solve(char **map, int size, t_tetri **t);
int					check_valid(char **map, t_tetri *t);
char				**init_table(int size);
int					get_start_size(t_tetri *t);
t_tetri				*move_to_start_y(t_tetri *t);
t_tetri				*move_to_start_x(t_tetri *t);
void				back_to_start(t_tetri **begin);
int					ch_b(char *buf, int line, int i, int nl);
void				print_error(void);
void				pr_usage(void);
void				free_list(t_tetri **list);
void				free_tab(char **tab);
t_tetri				*init_list(int fd, char *b, int *size);

#endif
