/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:39:30 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/03 11:56:51 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_c(va_list *arg_list, t_flags *flags)
{
	int total;
	
	total = 0;
	char c = va_arg(*arg_list, int);
	if (flags->minus == 1)
		write(1, &c, 1);
	total += ft_put_width(flags->width, flags->zero, 1);
	if (flags->minus == 0)
		write(1, &c, 1);
	return(total + 1);
}