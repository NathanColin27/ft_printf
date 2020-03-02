/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:03:13 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/02 13:43:22 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_u(va_list *arg_list, t_flags *flags)
{
	unsigned int num = va_arg(*arg_list, unsigned int);
	num = (unsigned int)(4294967295 + 1 + num);
	
	if (flags->dot == 0 && num == 0)
	{
		ft_put_width(flags->width, 0, 0);
		return (0);
	}
	ft_parse_uint(num, flags);
	
	return(0);
}

int put_uprecision(int num, t_flags *flags, int lenght)
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

int	ft_parse_uint(int num, t_flags *flags)
{
	int length;

	length = ft_lenbase(num, 10);
	if(flags->minus == 1)
	{
		flags->zero = 0;
		put_uprecision(num, flags, length);
		ft_u_putnbr(num);
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
		put_uprecision(num, flags, length);
		ft_u_putnbr(num);
	}
	return (0);
}
