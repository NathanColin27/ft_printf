/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:56:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/09 12:19:16 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_p(va_list *arg_list, t_flags *flags)
{
	int total;
	int length;
	char *base;
	unsigned long long nbr;
	
	total = 0;
	base = "0123456789abcdef";
	nbr = va_arg(*arg_list, unsigned long long);
	length = ft_lenbase_p(nbr,16) + 2 ;
	if(nbr == 0 && flags->dot == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		return(2);
	}
	if(flags->minus == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_dec_to_hex_p(nbr, base);
		total += ft_put_width(flags->width, flags->zero, length);
		flags->zero = 0;
	}
	if(flags->minus == 0)
		{
		total += ft_put_width(flags->width, flags->zero, length);
		ft_putchar('0');
		ft_putchar('x');
		ft_dec_to_hex_p(nbr, base);
		}
	total += length;
	return(total);
}