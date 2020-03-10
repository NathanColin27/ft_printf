/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:03:13 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/10 09:03:57 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_u(va_list *arg_list, t_flags *flags)
{
	unsigned int	num;
	int				total;

	total = 0;
	num = va_arg(*arg_list, unsigned int);
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags->dot == 0 && num == 0)
	{
		total += ft_put_width(flags->width, 0, 0);
		return (total);
	}
	total += ft_parse_uint(num, flags);
	return (total);
}

int		put_uprecision(unsigned int num, t_flags *flags, int lenght)
{
	int				total;

	total = 0;
	if (flags->dot >= 0)
		while (flags->dot > lenght)
		{
			ft_putchar('0');
			lenght++;
			total++;
		}
	return (total);
}

int		ft_parse_uint(unsigned int num, t_flags *flags)
{
	int				total;

	total = 0;
	if (flags->minus == 1)
	{
		flags->zero = 0;
		total += put_uprecision(num, flags, ft_lenbase(num, 10));
		ft_u_putnbr(num);
	}
	if (flags->dot >= 0 && ft_lenbase(num, 10) > flags->dot)
		flags->dot = ft_lenbase(num, 10);
	if (flags->dot < 0)
		total += ft_put_width(flags->width, flags->zero, ft_lenbase(num, 10));
	else
	{
		flags->width -= flags->dot;
		total += ft_put_width(flags->width, 0, 0);
	}
	if (flags->minus == 0)
	{
		total += put_uprecision(num, flags, ft_lenbase(num, 10));
		ft_u_putnbr(num);
	}
	total += ft_lenbase(num, 10);
	return (total);
}
