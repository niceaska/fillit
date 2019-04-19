/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:20:45 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/02/27 17:26:37 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_fd(const int fd, t_list **cell, int check)
{
	t_list			*tmp;

	tmp = *cell;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	if (check == 1)
		return (NULL);
	tmp = ft_lstnew(NULL, 0);
	if (!(tmp->content = ft_strnew(0)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(cell, tmp);
	return (tmp);
}

int		move_line(char **s, size_t i)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*s) - (i + 1);
	if (len == 0)
	{
		free(*s);
		if (!(*s = ft_strnew(0)))
			return (-1);
		return (1);
	}
	if (!(tmp = ft_strsub(*s, i + 1, len)))
		return (-1);
	free(*s);
	if (!(*s = ft_strnew(ft_strlen(tmp))))
		return (-1);
	*s = ft_strcpy(*s, tmp);
	free(tmp);
	return (1);
}

int		read_line(char **content, const int fd, int full)
{
	int			r;
	char		buffer[BUFF_SIZE + 1];

	if (full == 0)
	{
		if (read(fd, buffer, 0) < 0)
			return (-1);
		else
			return (1);
	}
	while ((r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if (!(*content = ft_strrejoin(*content, buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	return (1);
}

int		cleaning(t_list **cell, const int fd)
{
	t_list	*tmp;
	t_list	*prev;
	size_t	len;

	tmp = *cell;
	prev = NULL;
	if (!(tmp = find_fd(fd, cell, 1)))
		return (-1);
	len = ft_strlen((char*)(tmp->content));
	if (tmp->content)
		free(tmp->content);
	if (tmp->next && prev)
		prev->next = tmp->next;
	else if (tmp->next && !prev)
		*cell = tmp->next;
	else
		*cell = NULL;
	free(tmp);
	if (len == 0)
		return (0);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*cell;
	long			i;
	t_list			*current;

	if (!line || (fd < 0) || (read_line(NULL, fd, 0) < 0))
		return (-1);
	if (!(current = find_fd(fd, &cell, 0)))
		return (cleaning(&cell, fd));
	if (!(*line = ft_strnew(0)))
		return (cleaning(&cell, fd));
	if (!ft_strchr(current->content, '\n'))
		if ((read_line((char**)&(current->content), fd, 1)) == -1)
			return (cleaning(&cell, fd));
	if (!ft_strlen(current->content))
		return (cleaning(&cell, fd));
	if ((i = ft_strcpy_whilech(line, current->content, '\n')) == -1)
		return (cleaning(&cell, fd));
	if ((size_t)i < ft_strlen(current->content))
	{
		if ((move_line((char**)&(current->content), i)) == -1)
			return (cleaning(&cell, fd));
	}
	else
		ft_strclr(current->content);
	return (1);
}
