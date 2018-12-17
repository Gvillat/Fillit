/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:22:36 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/26 00:22:39 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ROW 6
# define COL 4
# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# define PC(x) ((t_piece *)(curr->data))->x

typedef struct			s_check
{
	int					hash;
	int					p;
	int					nl;
}						t_check;

typedef struct			s_piece
{
	int					piece[4][2];
	char				letter;
}						t_piece;

int						ft_backtrack(t_list *curr, char **map, int map_size,
						int pos);
t_list					*parser(const int fd, int *nbr_pcs);
#endif
