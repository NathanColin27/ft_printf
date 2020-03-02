/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/02 14:11:37 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int		ft_lenbase(long value, int base)
{
	int l;

	l = 1;
	while (value > base)
	{
		l++;
		value /= base;
	}
	return (l);
}

void decToHex(long nbr, char *base){
	int base_len;
	base_len = 16;

	if (nbr < 0)
	{
		ft_putchar('-');
		decToHex(-nbr, base);
	}
	else if (nbr >= 16)
	{
		decToHex(nbr / base_len, base);
		decToHex(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

int print_hex(long num, char* base, t_flags *flags)
{

	if (flags->dot == 0 && num == 0)
	{
		ft_put_width(flags->width, 0, 0);
		return (0);
	}
	ft_parse_hex(num, base, flags);
	return 0;
}

int put_hex_precision(int num, t_flags *flags, int lenght)
{
	if (flags->dot >= 0)
		while (flags->dot > lenght)
	{
			ft_putchar('0');
			lenght++;
	}
	return (1);
}

int	ft_parse_hex(long num,char *base, t_flags *flags)
{
	int length;

	length = 8;
	if(flags->minus == 1)
	{
		flags->zero = 0;
		put_hex_precision(num, flags, length);
		decToHex(num, base);
	}
	if(flags->dot >= 0 && length > flags->dot)
		flags->dot = length;
	if(flags->dot < 0)
		ft_put_width(flags->width, flags->zero, length);
	else
	{
		flags->width -= flags->dot;
		ft_put_width(flags->width,0,0);
	}
	if (flags->minus == 0)
	{
		put_hex_precision(num, flags, length);
		decToHex(num, base);
	}
	return (0);
}

int	print_x(va_list *arg_list, t_flags *flags)
{
	long nbr;
	nbr = va_arg(*arg_list, long);
	if(nbr < 0)
		nbr += 4294967295;
	print_hex(nbr, "0123456789abcdef", flags);
	return(0);
}

int	print_up_x(va_list *arg_list, t_flags *flags)
{
	long nbr;
	nbr = va_arg(*arg_list, long);
	if(nbr < 0)
		nbr += 4294967295;
	print_hex(nbr, "0123456789ABCDEF", flags);
	return(0);
}
