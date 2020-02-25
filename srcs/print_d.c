/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/25 16:37:03 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int print_d(va_list *arg_list, t_flags *flags)
{
	int num = va_arg(*arg_list, int);

	int lenght = ft_intlen(num);

	if (flags->dot == 0 && num == 0)
	{
		ft_put_width(flags->width, 0, 0);
		//return (0);
	}
	
	else if(flags->minus == 1)
	{
		
		if(flags->dot >= 0)
		{
			int i = flags->dot;
			while(i > lenght)
			{
				ft_putchar('0');
				i--;
			}
		}
		if (flags->dot >= 0 && flags->dot < lenght)
			flags->dot = lenght;
		ft_putnbr(num);
		
		if(flags->dot >= 0)
		{
			flags->width -= flags->dot;
			ft_put_width(flags->width, 0, 0);
		}
	
		if (num < 0)
			ft_put_width(flags->width - 1, flags->zero, lenght);
		else 
			ft_put_width(flags->width, flags->zero, lenght);
	}
	
	
	
	
	if(flags->dot >= 0)
		flags->zero = 0;
	
	if(flags->minus == 0)
	{
		if (flags->dot >= 0 && flags->dot < lenght)
			flags->dot = lenght;
		if (flags->width > flags->dot)
		{
			if (num < 0)
				ft_put_width(flags->width - 1, flags->zero, lenght);
			else 
				ft_put_width(flags->width, flags->zero,lenght);
		}
		else 
		{
		if (num < 0)
			ft_put_width(flags->width - 1, flags->zero, flags->dot);
		else 
			ft_put_width(flags->width, flags->zero,flags->dot);
		}
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


	return(0);
}
