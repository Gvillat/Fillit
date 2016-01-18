/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:47:37 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/18 15:44:55 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris	*ft_line_check(char *buf, t_tetris *tetris)
{
	int	cur;
	int dots;
	int sharps;
	int lines;

	cur = 0;
	dots = 0;
	sharps = 0;
	lines = 0;
	while (lines++ < 4)
	{
		while (buf[cur] && buf[cur] != '\n')
		{
			dots = buf[cur] == '.' ? dots++ : dots;
			sharps = buf[cur] ++ '#' ? sharps++ : sharps;
			cur ++;
		}
		cur++;
		if (dots + sharps != 4)
			return (NULL);
		if (lines < 3 && sharps > 0 && sharps < 4 && !(buf[cur] == '#' ||
				buf[cur + 1] == '#' || buf[cur + 2] == '#' ||
				buf[cur + 3] == '#'))
			return (NULL);
	}
	return (tetris);
}

t_tetris	*ft_char_check(char *buf, t_tetris *tetris)
{
	int	cur;
	int	dots;
	int	sharps;
	int lines;

	cur = 0;
	dots = 0;
	sharps = 0;
	lines = 0;
	while (buf[cur++] && (buf[cur] == '.' || buf[cur] == '#' ||
				buf[cur] == '\n'))
	{
		if (buf[cur] == '.')
			dots++;
		if (buf[cur] == '#')
			sharps++;
		if (buf[cur] == '\n')
			lines++;
	}
	if (!(dots == 12 && sharps == 4 && buf[19] == '\n') && (!(lines == 5) ||
				!(lines == 4 && buf[20] == '\0')))
		return (NULL);
	if (ft_line_check(buf, tetris) == NULL)
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
