/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:56:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/03 13:20:01 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_p(va_list *arg_list, t_flags *flags)
{
	int total;
	char *base;
	
	
	total = 0;
	base = "0123456789abcdef";
	long nbr = va_arg(*arg_list, long);
	ft_putchar('0');
	ft_putchar('x');
	if(flags->minus == 1)
	{
		decToHex(nbr, base);
		flags->zero = 0;
	}
	total += ft_put_width(flags->width, flags->zero, 14);
	if(flags->minus == 0)
		decToHex(nbr, base);
	if(nbr == 0)
		total += 3;
	else
		total += 14;
	return(total);
}