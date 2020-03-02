/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:56:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/02 11:58:05 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_p(va_list *arg_list, t_flags *flags)
{
	char *base;
	base = "0123456789abcdef";
	long nbr = va_arg(*arg_list, long);
	ft_putchar('0');
	ft_putchar('x');
	if(flags->minus == 1)
	{
		decToHex(nbr, base);
		flags->zero = 0;
	}
	ft_put_width(flags->width, flags->zero, 14);
	if(flags->minus == 0)
		decToHex(nbr, base);
	return(0);
}