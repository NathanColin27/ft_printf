/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/03 11:34:39 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int put_precision(int num, t_flags *flags, int lenght)
{
	int total = 0;
	if (flags->dot >= 0 && num < 0)
	{
		ft_putchar('-');
		total++;
	}
	if (flags->dot >= 0)
		while (flags->dot > lenght)
	{
			ft_putchar('0');
			lenght++;
			total++;
	}
	return (total);
}

int	ft_parse_int(int num, t_flags *flags)
{
	int length;
	int total;

	length = ft_lenbase(num, 10);
	total = 0;
	if(flags->minus == 1)
	{
		flags->zero = 0;
		total += put_precision(num, flags, length);
		ft_putnbr(num);
	}
	if(flags->dot >= 0 && length > flags->dot)
		flags->dot = length;
	if(flags->dot < 0)
		total += ft_put_width(flags->width, flags->zero, length);
	else
	{
		flags->width -= flags->dot;
		total += ft_put_width(flags->width,0,0);
	}
	if (flags->minus == 0)
	{
		total += put_precision(num, flags, length);
		ft_putnbr(num);
	}
	total += length;
	return (total);
}

int print_d(va_list *arg_list, t_flags *flags)
{
	int total;
	int num;
	
	total = 0;
	num = va_arg(*arg_list, int);
	if (flags->dot == 0 && num == 0)
	{
		total += ft_put_width(flags->width, 0, 0);
		return (total);
	}
	if (num < 0)
	{
		ft_putchar('-');
		total++;
		num *= -1;
		flags->width--;
	}
	total += ft_parse_int(num, flags);
	return (total);
}
