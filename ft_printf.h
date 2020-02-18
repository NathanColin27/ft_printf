/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 16:59:17 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# define CONVERTERS "csdxXipu%"
# define FLAGS "0.-*"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

void print_c(va_list *arg_list, t_flags *flags);

void print_s(va_list *arg_list, t_flags *flags);

void print_d(va_list *arg_list, t_flags *flags);

void print_x(va_list *arg_list, t_flags *flags);

void print_up_x(va_list *arg_list, t_flags *flags);

void print_p(va_list *arg_list, t_flags *flags);

void print_u(va_list *arg_list, t_flags *flags);

void print_percent(va_list *arg_list, t_flags *flags);

void ft_u_putnbr(unsigned int n);

void decToHex(long nbr);

void decToHex_upper(int nbr);

int index_finder(char elem, char *tab);

int check_str(char *str, va_list *arg_list, t_flags my_flags);

int ft_printf(const char *str, ...);

int	ft_put_width(int width, int zero, int printed);

int ft_intlen(int value);

t_flags ft_star_flag(t_flags flags, va_list arg_list);

t_flags ft_width_flag(t_flags flags, char digit);

t_flags	ft_dot_flag(t_flags	flags, va_list arg_list, char *str);

#endif
