/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/07 16:04:19 by ncolin           ###   ########.fr       */
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

void decToHex_p(unsigned long long nbr, char *base);

long	ft_lenbase_p(unsigned long long value, int base);

int print_c(va_list *arg_list, t_flags *flags);

int print_s(va_list *arg_list, t_flags *flags);

int print_d(va_list *arg_list, t_flags *flags);

int print_x(va_list *arg_list, t_flags *flags);

int print_up_x(va_list *arg_list, t_flags *flags);

int print_p(va_list *arg_list, t_flags *flags);

int print_u(va_list *arg_list, t_flags *flags);

int print_percent(va_list *arg_list, t_flags *flags);

void ft_u_putnbr(unsigned int n);

void decToHex(long long nbr, char* base);

int index_finder(char elem, char *tab);

int check_str(char *str, va_list *arg_list, t_flags my_flags);

int ft_printf(const char *str, ...);

int	ft_put_width(int width, int zero, int printed);

long ft_lenbase(long long value, int base);

void put_num(char *str, t_flags *flags);

void put_dot(char *str, int dot);

t_flags ft_star_flag(t_flags flags, va_list arg_list);

int ft_width_flag(t_flags *flags, va_list arg_list, char *str);

int	ft_dot_flag(t_flags	*flags, va_list arg_list, char *str);

t_flags		ft_minus_flag(t_flags flags);

int	ft_parse_int(int num, t_flags *flags, int sign);

int put_precision(int num, t_flags *flags, int lenght, int sign);

int put_uprecision(unsigned int num, t_flags *flags, int lenght);

int	ft_parse_uint(unsigned int num, t_flags *flags);

int	ft_parse_hex(long long num, char *base, t_flags *flags);

int put_hex_precision(int num, t_flags *flags, int lenght);
#endif
