/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:45:49 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 17:12:18 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/fillit.h"

void	ft_clean_map(t_tetris *tetris, char **map, int sqr_sze)
{
	int	cur;
	int cnt;

	cnt = 0;
	cur = 0;
	while (cur < sqr_sze * sqr_sze && cnt  < 4)
	{
		if (map[cur / sqr_sze][cur % sqr_sze] == tetris->letter)
		{
			map[cur / sqr_sze][cur % sqr_sze] == '.';
			cnt++;
		}
	}
}

int		ft_around_tetris(t_tetris *tetris, char **map, int sqr_sze, int pos)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = pos % sqr_sze;
	y = pos / sqr_sze;
	if (x >= sqr_sze || y >= sqr_sze || x < 0 || y < 0 || map[y][x] != '.')
		return (0);
	px = x + tetris->p1[0];
	py = y + tetris->p1[1];
	if (px >= sqr_sze || py >= sqr_sze || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + tetris->p2[0];
	py = y + tetris->p2[1];
	if (px >= sqr_sze || py >= sqr_sze || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + tetris->p3[0];
	py = y + tetris->p3[1];
	if (px >= sqr_sze || py >= sqr_sze || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	return (1);
}

void	ft_put_letter(t_tetris *tetris, char **map, int sqr_sze, int pos)
{
	int	x;
	int	y;

	x = pos % sqr_sze;
	y = pos / sqr_sze;
	map[y][x] = tetris->letter;
	map[y + tetris->p1[1]][x + tetris->p1[0]] = tetris->letter;
	map[y + tetris->p2[1]][x + tetris->p2[0]] = tetris->letter;
	map[y + tetris->p3[1]][x + tetris->p3[0]] = tetris->letter;
}

int	ft_fill_map(t_tetris *tetris, char **map, int sqr_sze, int pos)
{
	if (tetris->letter == '|')
		return (1);
	while (pos < sqr_sze * sqr_sze)
	{
		if (ft_around_tetris(tetris, map, sqr_sze, pos))
		{
			ft_put_letter(tetris, map, sqr_sze, pos);
			if (ft_fill_map(tetris + 1, map, sqr_sze, 0))
				return (1);
		}
		pos++;
	}
	ft_clean_map((tetris - 1), map, sqr_sze);
	return (0);
}

void	ft_init(t_tetris *tetris, int pcs)
{
	int		sqr_sze;
	char	**map;

	sqr_sze = ft_bsq(pcs);
	if ((map = ft_createmap(sqr_sze)) == NULL)
		return ;
	while (ft_fill_map(tetris, map, sqr_sze, 0)  == 0)
	{
		sqr_sze++;
		free(map);
		if ((map = ft_createmap(sqr_sze)) == NULL)
			return ;
	}
	ft_display(map, sqr_sze);
}
