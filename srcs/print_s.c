/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/02 14:42:09 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_s(va_list *arg_list, t_flags *flags)
{
	char *str = va_arg(*arg_list, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return 0;
	}
	if (flags->minus == 0)
	{
		if (flags->dot >= 0)
		{
			if(ft_strlen(str) >= flags->dot)
			{
				ft_put_width(flags->width, flags->zero, flags->dot);
				write(1, str, flags->dot);
			}
			else
			{
				ft_put_width(flags->width, flags->zero, ft_strlen(str));
				write(1, str, ft_strlen(str));
			}
		}
		else {

		ft_put_width(flags->width, flags->zero, ft_strlen(str));
		write(1, str, ft_strlen(str));
		}
	}
	else if (flags->minus == 1)
	{
		if (flags->dot >= 0)
		{
			if(ft_strlen(str) >= flags->dot)
			{
				write(1, str, flags->dot);
				ft_put_width(flags->width, flags->zero, flags->dot);
				
			}
			else
			{
				write(1, str, ft_strlen(str));
				ft_put_width(flags->width, flags->zero, ft_strlen(str));
				
			}
		}
		else {
			write(1, str, ft_strlen(str));
			ft_put_width(flags->width, flags->zero, ft_strlen(str));	
		}
	}


	return(0);
}