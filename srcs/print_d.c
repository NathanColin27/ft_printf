/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/09 12:56:38 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		put_precision(int num, t_flags *flags, int lenght, int sign)
{
	int total;

	total = 0;
	if (num > 0)
		num *= sign;
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

int		ft_parse_int(int num, t_flags *flags, int sign)
{
	int length;
	int total;

	length = ft_lenbase(num, 10);
	total = 0;
	if (num < 0)
		length++;
	if (flags->minus == 1)
	{
		total += put_precision(num, flags, length, sign);
		ft_putnbr(num);
	}
	if (flags->dot >= 0 && length > flags->dot)
		flags->dot = length;
	if (flags->dot < 0)
		total += ft_put_width(flags->width, flags->zero, length);
	else
	{
		flags->width -= flags->dot;
		total += ft_put_width(flags->width, 0, 0);
	}
	if (flags->minus == 0)
	{
		total += put_precision(num, flags, length, sign);
		ft_putnbr(num);
	}
	total += length;
	return (total);
}

int		print_d(va_list *arg_list, t_flags *flags)
{
	int total;
	int num;
	int sign;

	sign = 1;
	total = 0;
	num = va_arg(*arg_list, int);
	if (flags->dot == 0 && num == 0)
		return (total += ft_put_width(flags->width, 0, 0));
	if (num < 0)
		sign *= -1;
	if (num < 0 && (flags->dot >= 0 || flags->zero == 1))
	{
		if (flags->dot <= -1 && flags->zero == 1)
		{
			ft_putchar('-');
			total++;
		}
		num *= -1;
		flags->width--;
	}
	total += ft_parse_int(num, flags, sign);
	return (total);
}
