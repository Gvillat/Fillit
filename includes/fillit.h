/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:06:16 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/18 17:21:57 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF 21

typedef struct s_tetris
{
		int		p1[2];
		int		p2[2];
		int		p3[2];
		char	letter;
}				t_tetris;

void		ft_clean_map(t_tetris *tetris, char **map, int sqr_sze);
int			ft_around_tetris(t_tetris *tetris, char **map, int sqr_sze, int pos);
void		ft_put_letter(t_tetris *tetris, char **map, int sqr_sze, int pos);
int			ft_fill_map(t_tetris *tetris, char **map, int sqr_sze, int pos);
void		ft_init(t_tetris *tetris, int pcs);
t_tetris	*ft_line_check(char *buf, t_tetris *tetris);
t_tetris	*ft_char_check(char *buf, t_tetris *tetris);
t_tetris	*ft_coordinate_check(char *buf, t_tetris *tetris);
int			ft_bsq(int nb);
char		**ft_createmap(int bsq);
void		ft_display(char **map, int sqr_sze);
t_tetris	*ft_read_buf(char *file, int *pcs);
int			ft_check_last(char *file_name, int pcs);
int			ft_contiguity(int x, int y, int x_p0, int y_p0);
int			ft_p1(char *buf, t_tetris *tetris, int x_p0, int y _p0);
int			ft_p2(char *buf, t_tetris *tetris, int x_p0, int y _p0);
int			ft_p3(char *buf, t_tetris *tetris, int x_p0, int y _p0);
void		ft_letter_assignation(t_tetris *tetris);
int			ft_abs(int nbr);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
int			ft_round(float nb);
float		ft_sqrt(int nb);
float		ft_sqrt(int nb);
size_t		ft_strlen(const char *s);
char		*ft_strsetnew(char c, int size);
