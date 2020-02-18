/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:39:30 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 10:55:45 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_c(va_list *arg_list, t_flags *flags)
{
	char c = va_arg(*arg_list, int);
	ft_put_width(flags->width, flags->zero, 1);
	write(1, &c, 1);
}