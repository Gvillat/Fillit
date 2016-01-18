/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:12:36 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 15:26:27 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_contiguity(int x, int y, int x_p0, int y_p0)
{
	int	p;
	int	p0;
	int	p0_diff;

	p0 = x_p0 + y_p0;
	p = x + y;
	p0_diff = p - p0;
	p = ft_abs(x) + ft_abs(y);
	if (p0_diff > 1 || p0_diff < -1 || p > 3)
		return (0);
	return (1);
}

int		ft_p1(char *buf, t_tetris *tetris, int x_p0, int y _p0)
{
	int cur;
	int sharps;

	if (tetris == NULL)
		return (0);
	cur = 0;
	sharps = 0;
	while (sharps != 2)
		if (buf[cur++] == '#')
			sharps++;
	tetris->p1[0] = cur % 5 - x_p0;
	tetris->p1[1] = cur / 5 - y_p0;
	return (ft_contiguity(tetris->p1[0], tetris->p1[1], 0, 0));
}

int		ft_p2(char *buf, t_tetris *tetris, int x_p0, int y _p0)
{
	int cur;
	int sharps;

	if (tetris == NULL)
		return (0);
	cur = 0;
	sharps = 0;
	while (sharps != 3)
		if (buf[cur++] == '#')
			sharps++;
	tetris->p2[0] = cur % 5 - x_p0;
	tetris->p2[1] = cur / 5 - y_p0;
	return (ft_contiguity(tetris->p2[0], tetris->p2[1], tetris->p1[0],
			   tetris->p1[1]));
}

int		ft_p3(char *buf, t_tetris *tetris, int x_p0, int y _p0)
{
	int cur;
	int sharps;

	if (tetris == NULL)
		return (0);
	cur = 0;
	sharps = 0;
	while (sharps != 4)
		if (buf[cur++] == '#')
			sharps++;
	tetris->p3[0] = cur % 5 - x_p0;
	tetris->p3[1] = cur / 5 - y_p0;
	return (ft_contiguity(tetris->p3[0], tetris->p3[1], tetris->p2[0],
				tetris->p2[1]));
}

void	ft_letter_assignation(t_tetris *tetris)
{
	int	cnt;

	cnt = 0;
	while (tetris[cnt].letter != '|')
	{
		tetris[cnt].letter = (char)(65 + cnt);
		cnt++;
	}
}
