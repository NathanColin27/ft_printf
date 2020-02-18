/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 14:32:46 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_s(va_list *arg_list, t_flags *flags)
{
	char *str = va_arg(*arg_list, char *);
	ft_put_width(flags->width, flags->zero, ft_strlen(str));
	write(1, str, ft_strlen(str));
}