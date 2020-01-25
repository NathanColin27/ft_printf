/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/25 14:10:23 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void decToHex(long nbr){
	long base_len;
	char *base;

	base = "0123456789abcdef";
	base_len = 16;
	if (nbr < 0)
	{
		decToHex(-nbr);
	}
	else if (nbr > 15)
	{
		decToHex(nbr / base_len);
		decToHex(nbr % base_len);
	}
	else
		ft_putchar(base[nbr]);
}

void	print_x(va_list *arg_list)
{
	int nbr;
	
	nbr = va_arg(*arg_list, int);
	decToHex(nbr);
}


void decToHex_upper(int nbr){
	int base_len;
	char *base;
	base = "0123456789ABCDEF";
	base_len = 16;

	if (nbr < 0)
	{
		ft_putchar('-');
		decToHex_upper(-nbr);
	}
	else if (nbr >= 16)
	{
		decToHex_upper(nbr / base_len);
		decToHex_upper(nbr % base_len);
	}
	else
		ft_putchar(base[nbr]);
}



void	print_up_x(va_list *arg_list)
{
	
	int nbr;
	nbr = va_arg(*arg_list, int);
	decToHex_upper(nbr);
}
