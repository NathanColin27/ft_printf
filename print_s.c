/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/22 16:21:11 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_string(va_list *arg_list)
{
	char *str = va_arg(*arg_list, char *);
	write(1, str, ft_strlen(str));
}