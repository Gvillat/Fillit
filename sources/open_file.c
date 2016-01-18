/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:05:08 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/18 16:26:04 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris	*ft_read_buf(char *file, int *pcs)
{
	t_tetris	 *tetris_map
	int			fd;
	char		*buf;

	if ((tetris_map = malloc(sizeof(t_tetris) * 26)) == NULL)
		return (NULL);
	if ((buf = malloc(sizeof(char) * BUFF)) == NULL)
		return (NULL);
	if ((fd = open (file, O_RDONLY, 0555)) == -1)
		return (NULL);
	while ((read(fd, buf, BUFF)) > 0)
	{
		if (ft_char_check(buf, tetris) == NULL)
			return (NULL);
		*pcs++;
		ft_memset(buf, '\0', BUFF + 1);
	}
	free(buf);
	if ((close(fd)) == -1)
		return (NULL)
	tetris_map[*pcs].letter = '|';
	return (tetris_map);
}

int		ft_check_last(char *file_name, int pcs)
{
	char	*buf;
	int		fd;

	if ((buf = (char*)malloc(sizeof(char) * (BUFF *pcs + 1))) == NULL)
		return (0);
	if ((fd = open(file_name, O_RDONLY, 0555)) == -1)
		return (0);
	buf[BUFF * pcs + 1] = '\0';
	while ((read(fd, buf, BUFF * pcs)) >= 0)
	{
		if (buf[BUFF * pcs - 1] == '\0' && buf[BUFF * pcs - 2] == '\n' &&
				(buf[BUFF * pcs - 3] == '.' | buf[BUFF * pcs - 3] == '#'))
			return (1);
	}
	free(buf);
	return (0);
}
