/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upper_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:13:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/24 14:15:24 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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



void	ft_printf_decToHex_upper(va_list *arg_list)
{
	
	int nbr;
	nbr = va_arg(*arg_list, int);
	decToHex_upper(nbr);
}
