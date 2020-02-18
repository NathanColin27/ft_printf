/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:21 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 17:01:02 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_d(va_list *arg_list, t_flags *flags)
{
	int num = va_arg(*arg_list, int);
	int lenght = ft_intlen(num);
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