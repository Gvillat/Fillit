/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:46:58 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/23 18:47:01 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_put_letter(t_piece *piece, char **map, int map_size, int pos)
{
	int	x;
	int	y;

	x = pos % map_size;
	y = pos / map_size;
	map[y][x] = piece->letter;
	map[y + piece->piece[1][0]][x + piece->piece[1][1]] = piece->letter;
	map[y + piece->piece[2][0]][x + piece->piece[2][1]] = piece->letter;
	map[y + piece->piece[3][0]][x + piece->piece[3][1]] = piece->letter;
}

static void	ft_put_point(t_piece *piece, char **map, int map_size, int pos)
{
	int	x;
	int	y;

	x = pos % map_size;
	y = pos / map_size;
	map[y][x] = '.';
	map[y + piece->piece[1][0]][x + piece->piece[1][1]] = '.';
	map[y + piece->piece[2][0]][x + piece->piece[2][1]] = '.';
	map[y + piece->piece[3][0]][x + piece->piece[3][1]] = '.';
}

static int	ft_around_piece(t_piece *piece, char **map, int map_size, int pos)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = pos % map_size;
	y = pos / map_size;
	if (x >= map_size || y >= map_size || x < 0 || y < 0 || map[y][x] != '.')
		return (0);
	px = x + piece->piece[1][1];
	py = y + piece->piece[1][0];
	if (px >= map_size || py >= map_size || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + piece->piece[2][1];
	py = y + piece->piece[2][0];
	if (px >= map_size || py >= map_size || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + piece->piece[3][1];
	py = y + piece->piece[3][0];
	if (px >= map_size || py >= map_size || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	return (1);
}

int			ft_backtrack(t_list *curr, char **map, int map_size, int pos)
{
	if (!curr)
		return (1);
	while (pos < map_size * map_size)
	{
		if (ft_around_piece(curr->data, map, map_size, pos))
		{
			ft_put_letter(curr->data, map, map_size, pos);
			if (ft_backtrack(curr->next, map, map_size, 0))
				return (1);
			else
				ft_put_point(curr->data, map, map_size, pos);
		}
		pos++;
	}
	return (0);
}
