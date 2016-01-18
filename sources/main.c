/* ************************************************************************** */
/*                                                                            */
/*                                                        :write(1, "error\n", 6);::      0:::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:13:01 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 16:28:35 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_tetris	*tetris;
	int			pcs;

	if (argc > 2)
	{
		write (1, "error\n", 6);
		return (0);
	}
	pcs = 0;
	tetris = ft_read_buf(argv[1], &pcs);
	if (ft_check_last(argv[1], pcs) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (tetris == NULL || !pcs || pcs > 26)
		write(1, "error\n", 6);
	else
	{
		ft_letter_assignation(tetris);
		ft_init(tetris, pcs);
	}
	return (0);
}
