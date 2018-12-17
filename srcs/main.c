/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:55:30 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/25 21:59:04 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_createmap(int map_size)
{
	char	**map_y;
	char	*map_x;
	int		i;

	if (!(map_y = (char **)malloc((map_size + 1) * sizeof(char *))))
		return (NULL);
	i = map_size;
	map_y[i] = NULL;
	while (--i >= 0)
	{
		map_x = ft_memset(ft_strnew(map_size), '.', map_size);
		map_y[i] = map_x;
	}
	return (map_y);
}

static void	ft_free(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size + 1)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

static void	ft_display(char **map, int map_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		while (j < map_size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
	ft_free(map, map_size);
}

static void	ft_start(t_list *curr, int nbr_pcs)
{
	int			map_size;
	char		**map;
	float		nbr;

	nbr = nbr_pcs < 2 ? ft_sqrt(2 * 4) : ft_sqrt(nbr_pcs * 4);
	map_size = (nbr >= 0) ? (int)(nbr + 0.5) : (int)(nbr - 0.5);
	map = ft_createmap(map_size);
	while (ft_backtrack(curr, map, map_size, 0) == 0)
	{
		ft_free(map, map_size);
		map_size++;
		map = ft_createmap(map_size);
	}
	ft_display(map, map_size);
}

int			main(int argc, char const *av[])
{
	t_list		*curr;
	int			nbr_pcs;
	int			fd;

	if (argc != 2)
		return (ft_putstr("error\n"));
	if (!(fd = open(av[1], O_RDONLY)))
		return (ft_putstr("error\n"));
	nbr_pcs = 0;
	curr = parser(fd, &nbr_pcs);
	if (curr == NULL || !nbr_pcs || nbr_pcs > 26)
		return (ft_putstr("error\n"));
	ft_start(curr, nbr_pcs);
	ft_lstdel(&curr);
	return (0);
}
