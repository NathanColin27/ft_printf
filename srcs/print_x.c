/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/10 09:02:37 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_hex(long long num, char *base, t_flags *flags)
{
	int total;

	total = 0;
	if (flags->dot == 0 && num == 0)
	{
		total += ft_put_width(flags->width, 0, 0);
		return (total);
	}
	total += ft_parse_hex(num, base, flags);
	return (total);
}

int		put_hex_precision(int num, t_flags *flags, int lenght)
{
	int total;

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

int		ft_parse_hex(long long num, char *base, t_flags *flags)
{
	int total;

	total = 0;
	if (flags->minus == 1)
	{
		flags->zero = 0;
		total += put_hex_precision(num, flags, ft_lenbase(num, 16));
		ft_dec_to_hex(num, base);
	}
	if (flags->dot >= 0 && ft_lenbase(num, 16) > flags->dot)
		flags->dot = ft_lenbase(num, 16);
	if (flags->dot < 0)
		total += ft_put_width(flags->width, flags->zero, ft_lenbase(num, 16));
	else
	{
		flags->width -= flags->dot;
		total += ft_put_width(flags->width, 0, 0);
	}
	if (flags->minus == 0)
	{
		total += put_hex_precision(num, flags, ft_lenbase(num, 16));
		ft_dec_to_hex(num, base);
	}
	total += ft_lenbase(num, 16);
	return (total);
}

int		print_x(va_list *arg_list, t_flags *flags)
{
	long long nbr;

	nbr = va_arg(*arg_list, unsigned int);
	if (nbr < 0)
		nbr += 4294967295;
	return (print_hex(nbr, "0123456789abcdef", flags));
}

int		print_up_x(va_list *arg_list, t_flags *flags)
{
	long long nbr;

	nbr = va_arg(*arg_list, unsigned int);
	if (nbr < 0)
		nbr += 4294967295;
	return (print_hex(nbr, "0123456789ABCDEF", flags));
}
