/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/23 17:51:57 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_d(va_list *arg_list, t_flags *flags)
{
	int num = va_arg(*arg_list, int);
	int lenght = ft_intlen(num);
	if(flags->dot >= 0)
		flags->zero = 0;
	if(flags->width + lenght < flags->dot )
		flags->width = 0;
	if(flags->minus == 0)
	{
		ft_put_width(flags->width, flags->zero, lenght);
		if(flags->dot >= 0)
		{
			while(flags->dot > lenght)
			{
				ft_putchar('0');
				flags->dot--;
			}
		}
		ft_putnbr(num);
	}

	else if(flags->minus == 1)
	{
		if(flags->dot >= 0)
		{
			while(flags->dot > lenght)
			{
				ft_putchar('0');
				flags->dot--;
			}
		}
		ft_putnbr(num);
		ft_put_width(flags->width, flags->zero, lenght);
	}
}