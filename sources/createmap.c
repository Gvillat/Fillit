/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:27:33 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 17:41:24 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_bsq(int nb)
{
	int	bsq;

	bsq = ft_round(ft_sqrt(nb * 4));
	return (bsq);
}

char	**ft_createmap(int bsq)
{
	char	**map_y;
	char	*map_x;
	int		i;

	map_y = (char**)malloc((bsq + 1) * sizeof(char*));
	if (!map_y)
		return (NULL);
	i = bsq;
	map_y[i] = NULL;
	while (--i >= 0)
	{
		map_x = ft_strsetnew('.', bsq);
		map_y[i] = map_x;
	}
	return (map_y);
}

void	ft_display(char **map, int sqr_sze)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sqr_sze)
	{
		while (j < sqr_sze)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}
