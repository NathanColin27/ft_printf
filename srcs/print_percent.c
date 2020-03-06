/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:03:55 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/06 18:08:30 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_percent(va_list *arg_list, t_flags *flags)
{
	int total;
	total = 0;
	
	if (flags->minus == 1)
	{
		flags->zero = 0;
		write(1, "%", 1);
		total++;
	}
	total += ft_put_width(flags->width, flags->zero, 1);
	if (flags->minus == 0)
	{
		write(1, "%", 1);
		total++;
	}
	return(total);
}