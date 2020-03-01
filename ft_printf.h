/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/01 18:05:26 by marvin           ###   ########.fr       */
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

int print_c(va_list *arg_list, t_flags *flags);

int print_s(va_list *arg_list, t_flags *flags);

int print_d(va_list *arg_list, t_flags *flags);

int print_x(va_list *arg_list, t_flags *flags);

int print_up_x(va_list *arg_list, t_flags *flags);

int print_p(va_list *arg_list, t_flags *flags);

int print_u(va_list *arg_list, t_flags *flags);

int print_percent(va_list *arg_list, t_flags *flags);

void ft_u_putnbr(unsigned int n);

void decToHex(long nbr);

void decToHex_upper(int nbr);

int index_finder(char elem, char *tab);

int check_str(char *str, va_list *arg_list, t_flags my_flags);

int ft_printf(const char *str, ...);

int	ft_put_width(int width, int zero, int printed);

int ft_intlen(int value);

void put_num(char *str, t_flags *flags);

void put_dot(char *str, int dot);

t_flags ft_star_flag(t_flags flags, va_list arg_list);

t_flags ft_width_flag(t_flags flags, char digit);

t_flags	ft_dot_flag(t_flags	flags, va_list arg_list, char *str);

t_flags		ft_minus_flag(t_flags flags);

int	ft_parse_int(int num, t_flags *flags);

int put_precision(int num, t_flags *flags, int lenght);
#endif
