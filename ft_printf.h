/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:36:16 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/10 10:21:41 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
** 		CONSTANTS
*/

# define CONVERTERS "csdxXipu%"
# define FLAGS "0.-*"

/*
** 		STRUCTS
*/

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

/*
** 		MAIN
*/

int				ft_printf(const char *str, ...);

/*
** 		UTILS
*/

int				ft_is_conv(char c);

int				ft_is_flag(char c);

char			*ft_strchr(char const *str, int c);

int				ft_isdigit(int c);

void			ft_putchar(char c);

void			ft_putnbr(int n);

char			*ft_strdup(const char *s1);

size_t			ft_strlen(const char *str);

long			ft_lenbase_p(unsigned long long value, int base);

void			ft_dec_to_hex(long long nbr, char *base);

void			ft_dec_to_hex_p(unsigned long long nbr, char *base);

int				index_finder(char elem, char *tab);

int				check_str(char *str, va_list *arg_list, t_flags my_flags);

void			ft_u_putnbr(unsigned int n);

int				ft_put_width(int width, int zero, int printed);

long			ft_lenbase(long long value, int base);

void			put_num(char *str, t_flags *flags);

void			put_dot(char *str, int dot);

int				print_ox();

int				putchar_ret(char c);

/*
** 		SRCS
*/

int				print_c(va_list *arg_list, t_flags *flags);

int				print_s(va_list *arg_list, t_flags *flags);

int				print_d(va_list *arg_list, t_flags *flags);

int				print_x(va_list *arg_list, t_flags *flags);

int				print_up_x(va_list *arg_list, t_flags *flags);

int				print_p(va_list *arg_list, t_flags *flags);

int				print_u(va_list *arg_list, t_flags *flags);

int				print_percent(va_list *arg_list, t_flags *flags);

int				ft_star_flag(t_flags *flags, va_list arg_list);

int				ft_width_flag(t_flags *flags, va_list arg_list, char *str);

int				ft_dot_flag(t_flags	*flags, va_list arg_list, char *str);

int				ft_minus_flag(t_flags *flags);

int				ft_parse_int(int num, t_flags *flags, int sign);

int				put_precision(int num, t_flags *flags, int lenght, int sign);

int				put_uprecision(unsigned int num, t_flags *flags, int lenght);

int				ft_parse_uint(unsigned int num, t_flags *flags);

int				ft_parse_hex(long long num, char *base, t_flags *flags);

int				put_hex_precision(int num, t_flags *flags, int lenght);

int				put_str_minus(char *str, t_flags *flags);

int				put_str(char *str, t_flags *flags);

#endif
