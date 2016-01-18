/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:37:53 by ppetit            #+#    #+#             */
/*   Updated: 2016/01/18 16:40:00 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if ((unsigned int)n > 9)
	{
		ft_putnbr((unsigned int)n / 10);
		ft_putnbr((unsigned int)n % 10);
	}
	else
		ft_putchar((unsigned int)n + '0');
}
