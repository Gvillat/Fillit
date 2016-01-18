/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstenew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:39:12 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 16:39:44 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_strsetnew(char c, int size)
{
	char	*str;
	int		i;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (size--)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
