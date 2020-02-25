/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:39:30 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/25 16:24:05 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_c(va_list *arg_list, t_flags *flags)
{
	char c = va_arg(*arg_list, int);
	if (flags->minus == 1)
		write(1, &c, 1);
	ft_put_width(flags->width, flags->zero, 1);
	if (flags->minus == 0)
		write(1, &c, 1);

	return(0);
}