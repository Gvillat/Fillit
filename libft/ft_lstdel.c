/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:56:27 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/24 21:45:30 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*eraser(t_list *current)
{
	if (current)
	{
		eraser(current->next);
		ft_lstdelone(&current);
	}
	return (NULL);
}

void			*ft_lstdel(t_list **alst)
{
	if (!alst || !*alst)
		return (NULL);
	*alst = eraser(*alst);
	return (NULL);
}
