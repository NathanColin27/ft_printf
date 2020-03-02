/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/02 13:34:54 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int put_precision(int num, t_flags *flags, int lenght)
{
	if (flags->dot >= 0 && num < 0)
		ft_putchar('-');
	if (flags->dot >= 0)
		while (flags->dot > lenght)
	{
			ft_putchar('0');
			lenght++;
	}
	return (1);
}

int	ft_parse_int(int num, t_flags *flags)
{
	int length;

	length = ft_lenbase(num, 10);
	if(flags->minus == 1)
	{
		flags->zero = 0;
		put_precision(num, flags, length);
		ft_putnbr(num);
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
		put_precision(num, flags, length);
		ft_putnbr(num);
	}
	return (0);
}

int print_d(va_list *arg_list, t_flags *flags)
{
	int num = va_arg(*arg_list, int);
	
	if (flags->dot == 0 && num == 0)
	{
		ft_put_width(flags->width, 0, 0);
		return (0);
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		flags->width--;
	}
	ft_parse_int(num, flags);
	return (0);
}
