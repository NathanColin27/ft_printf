/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:56:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/28 09:59:29 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_p(va_list *arg_list)
{
	long nbr = va_arg(*arg_list, long);
	ft_putchar('0');
	ft_putchar('x');
	decToHex(nbr);
}