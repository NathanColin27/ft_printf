/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:16:48 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/27 11:19:30 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_putnbr(unsigned int n)
{
	long unsigned int nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
}
