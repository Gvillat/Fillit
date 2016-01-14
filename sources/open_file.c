/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:05:08 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/14 17:09:25 by gvillat          ###   ########.fr       */
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
