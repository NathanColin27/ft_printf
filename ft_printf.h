/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/25 14:06:46 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void print_c(va_list *arg_list);

void print_s(va_list *arg_list);

void print_d(va_list *arg_list);

void print_x(va_list *arg_list);

void print_up_x(va_list *arg_list);

void print_p(va_list *arg_list);

void print_u(va_list *arg_list);

void print_percent(va_list *arg_list);

void decToHex(long nbr);

void decToHex_upper(int nbr);

int indexFinder(char *tab, char elem);

int ft_printf(const char *str, ...);
#endif
