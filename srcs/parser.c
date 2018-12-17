/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:43:00 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/25 22:49:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid(t_check *check, char c)
{
	if (c == '#')
		check->hash += 1;
	else if (c == '.')
		check->p += 1;
	else if (c == '\n' && ((check->p + check->hash) % 4) == 0)
		check->nl += 1;
	else
		return (-1);
	return (1);
}

static int	reader(const int fd, char buffer[COL][ROW], ssize_t *n_read)
{
	char			sign;
	t_check			ch;
	int				pos[2];
	int				y;

	y = 0;
	while (y < COL)
		bzero(buffer[y++], ROW);
	pos[0] = 0;
	ch.hash = 0;
	ch.p = 0;
	ch.nl = 0;
	while (pos[0] < COL && !(pos[1] = 0))
	{
		while (pos[1] < ROW - 1)
		{
			if ((*n_read = read(fd, &sign, 1)) != 1 || valid(&ch, sign) == -1)
				break ;
			buffer[pos[0]][pos[1]++] = sign;
		}
		pos[0]++;
	}
	return (*n_read != 1 || ch.hash != 4 || ch.p != 12 || ch.nl != 4 ? -1 : 1);
}

static int	contigous(char buff[COL][ROW], int col, int row)
{
	int				hit;

	hit = 0;
	while (col <= COL - 1)
	{
		while (buff[col][row] != '\n')
		{
			if (buff[col][row] == '#')
			{
				hit += buff[col][row + 1] == '#' ? 2 : 0;
				if (col <= 2)
					hit += buff[col + 1][row] == '#' ? 2 : 0;
			}
			row++;
		}
		row = 0;
		col++;
	}
	return (hit == 6 || hit == 8 ? 1 : -1);
}

static int	extract(t_list **lst, char buffer[COL][ROW], int col, int row)
{
	t_piece			p;
	int				pos[3];
	static char		letter = 'A';

	pos[0] = 0;
	pos[1] = row;
	pos[2] = 0;
	p.letter = letter++;
	while (col + pos[0] <= COL - 1)
	{
		while (buffer[col + pos[0]][pos[1]] != '\n')
		{
			if (buffer[col + pos[0]][pos[1]] == '#')
			{
				p.piece[pos[2]][0] = pos[0];
				p.piece[pos[2]++][1] = pos[1] - row;
			}
			pos[1]++;
		}
		pos[1] = 0;
		pos[0]++;
	}
	return (ft_lstaddback(lst, ft_lstnew(&p, sizeof(t_piece))) == 1 ? 1 : -1);
}

t_list		*parser(const int fd, int *nbr_pcs)
{
	t_list			*lst;
	char			buffer[COL][ROW];
	int				pos[2];
	ssize_t			n_read;

	lst = NULL;
	n_read = 1;
	while (n_read == 1)
	{
		pos[0] = 0;
		if (reader(fd, buffer, &n_read) == -1)
			return (ft_lstdel(&lst));
		while ((pos[1] = ft_strcspn(buffer[pos[0]], "#")) == ROW - 1)
			pos[0]++;
		if (contigous(buffer, pos[0], pos[1]) == -1)
			return (ft_lstdel(&lst));
		if (extract(&lst, buffer, pos[0], pos[1]) == -1)
			return (ft_lstdel(&lst));
		*nbr_pcs += 1;
		if ((n_read = read(fd, buffer[0], 1)) == 1)
			if (buffer[0][0] != '\n')
				return (ft_lstdel(&lst));
	}
	return (lst);
}
