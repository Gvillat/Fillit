/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:10 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/22 17:37:22 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcspn(const char *s, const char *charset)
{
	int			i;
	const char	*c;

	i = 0;
	while (*s)
	{
		c = charset;
		while (*c)
		{
			if (*s == *c)
				return (i);
			c++;
		}
		s++;
		i++;
	}
	return (i);
}
