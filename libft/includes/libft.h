/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:34:49 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/24 21:45:55 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

float				ft_sqrt(int nb);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
int					ft_putstr(char const *str);
t_list				*ft_lstnew(void const *data, size_t data_size);
void				ft_lstdelone(t_list **alst);
void				*ft_lstdel(t_list **alst);
size_t				ft_strcspn(const char *s, const char *charset);
int					ft_lstaddback(t_list **alst, t_list *new);
#endif
