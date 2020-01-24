/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/24 14:19:09 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void ft_printf_char(va_list *arg_list);

void ft_printf_string(va_list *arg_list);

void ft_printf_number(va_list *arg_list);

void ft_printf_hex(va_list *arg_list);

void ft_printf_hex_upper(va_list *arg_list);

void decToHex(int nbr);

void decToHex_upper(int nbr);

int indexFinder(char *tab, char elem);

int ft_printf(const char *str,...);
#endif
