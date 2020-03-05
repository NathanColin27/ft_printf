/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/05 14:44:11 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_s(va_list *arg_list, t_flags *flags)
{
	int total;

	total = 0;
	char *str = va_arg(*arg_list, char *);
	if (!str)
	{
		str = "(null)";
	}
	// This goes in a function PrInT_s_WhItHOuT_mInUs
	if (flags->minus == 0)
	{
		if (flags->dot >= 0)
		{
			if(ft_strlen(str) >= flags->dot)
			{
				total += ft_put_width(flags->width, flags->zero, flags->dot);
				write(1, str, flags->dot);
				total += flags->dot;
			}
			else
			{
				//printf("\nFLAG width %d\n", flags->width);
				total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
				write(1, str, ft_strlen(str));
				total += ft_strlen(str);
			}
		}
		else
		{
			total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
			write(1, str, ft_strlen(str));
			total += ft_strlen(str);
		}
	}
	// This goes in a function PrInT_s_WItH_mInUs
	else if (flags->minus == 1)
	{
		if (flags->dot >= 0)
		{
			if(ft_strlen(str) >= flags->dot)
			{
				write(1, str, flags->dot);
				total += flags->dot;
				total += ft_put_width(flags->width, flags->zero, flags->dot);
			}
			else
			{
				write(1, str, ft_strlen(str));
				total += ft_strlen(str);
				total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
			}
		}
		else 
		{
			write(1, str, ft_strlen(str));
			total += ft_strlen(str);
			total += ft_put_width(flags->width, flags->zero, ft_strlen(str));	
		}
	}
	return(total);
}