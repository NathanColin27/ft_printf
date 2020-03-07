/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:56:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/07 16:04:21 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void decToHex_p(unsigned long long nbr, char *base){
	int base_len;
	base_len = 16;

	if (nbr >= 16)
	{
		decToHex(nbr / base_len, base);
		decToHex(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

long	ft_lenbase_p(unsigned long long value, int base)
{
	long l;
	l = 1;
	while (value >= base)
	{
		l++;
		value /= base;
	}
	return (l);
}

int print_p(va_list *arg_list, t_flags *flags)
{
	int total;
	int length;
	char *base;
	
	total = 0;
	base = "0123456789abcdef";
	unsigned long long nbr = va_arg(*arg_list, unsigned long long);
	
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
		decToHex_p(nbr, base);
		total += ft_put_width(flags->width, flags->zero, length);
		flags->zero = 0;
	}
	if(flags->minus == 0)
		{
		total += ft_put_width(flags->width, flags->zero, length);
		ft_putchar('0');
		ft_putchar('x');
		decToHex_p(nbr, base);
		}
	total += length;
	return(total);
}