/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:03:13 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 10:19:05 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_u(va_list *arg_list, t_flags *flags)
{
	unsigned int num = va_arg(*arg_list, unsigned int);
	num = (unsigned int)(4294967295 + 1 + num);
	ft_u_putnbr(num);
}