/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:47:37 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/18 18:19:08 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"


int			ft_sharp_check(char *buf, int line, int *cnts)
{
	int		cur;
	int		sharps;
	int		dots;

	cur = 0;
	sharps = 0;
	dots = 0;
	while (buf[cur] != '\n')
	{
		sharps = buf[line * 5 + cur] == '#' ? sharps + 1 : sharps;
		dots = buf[line * 5 + cur] == '.' ? dots + 1 : dots;
		cur++;
	}
	if (sharps + dots != 4)
		return (0);
	if (line < 3 && cnts[1] > 0 && cnts[1] < 4 && !(buf[cnts[4]] == '#'
				|| buf[cnts[4] + 1] == '#' || buf[cnts[4] + 2] == '#'
				|| buf[cnts[4] + 3] == '#'))
		return (0);
	return (1);
}


t_tetris		*ft_line_check(char *buf, t_tetris *tetris, int line)
{
	int			cnts[5];

	cnts[0] = 0;
	cnts[1] = 0;
	cnts[2] = 0;
	cnts[3] = 5;
	cnts[4] = 0;
	while (++line != 4)
	{
		while (buf[cnts[4]] && buf[cnts[4]] != '\n')
		{
			cnts[0] = buf[cnts[4]] == '.' ? cnts[0] + 1 : cnts[0];
			cnts[1] = buf[cnts[4]] == '#' ? cnts[1] + 1 : cnts[1];
			cnts[4]++;
		}
		cnts[4]++;
		if (ft_sharp_check(buf, line, cnts) == 0)
			return (NULL);
		cnts[0] = 0;
		cnts[2] = 0;
		cnts[3] = 5;
	}
	return (tetris);
}

t_tetris	*ft_char_check(char *buf, t_tetris *tetris)
{
	int	cur;
	int	dots;
	int	sharps;
	int lines;

	cur = -1;
	dots = 0;
	sharps = 0;
	lines = 0;
	while (buf[++cur] && (buf[cur] == '.' || buf[cur] == '#' ||
				buf[cur] == '\n'))
	{
		if (buf[cur] == '.')
			dots++;
		else if (buf[cur] == '#')
			sharps++;
		else if (buf[cur] == '\n')
			lines++;
	}
	if (!(dots == 12 && sharps == 4 && buf[19] == '\n') && (!(lines == 5) ||
				!(lines == 4 && buf[20] == '\0')))
		return (NULL);
	if (ft_line_check(buf, tetris, -1) == NULL)
		return (NULL);
	return (ft_coordinate_check(buf, tetris));
}

t_tetris	*ft_coordinate_check(char *buf, t_tetris *tetris)
{
	int		cur;
	int		x_p0;
	int		y_p0;

	cur = 0;
	while (buf[cur] != '#')
		cur++;
	x_p0 = cur % 5;
	y_p0 = cur / 5;
	if (ft_p1(buf, tetris, x_p0, y_p0))
		if(ft_p2(buf, tetris, x_p0, y_p0))
			if(ft_p3(buf, tetris, x_p0, y_p0))
				return (tetris);
	return (NULL);
}
