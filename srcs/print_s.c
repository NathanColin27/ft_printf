/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/10 08:57:40 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_s(va_list *arg_list, t_flags *flags)
{
	int		total;
	char	*str;

	total = 0;
	str = va_arg(*arg_list, char *);
	if (!str)
		str = "(null)";
	if (flags->minus == 0)
	{
		total += put_str(str, flags);
	}
	else if (flags->minus == 1)
	{
		total += put_str_minus(str, flags);
	}
	return (total);
}

int		put_str_minus(char *str, t_flags *flags)
{
	int total;

	total = 0;
	if (flags->dot >= 0)
	{
		if (ft_strlen(str) >= flags->dot)
		{
			write(1, str, flags->dot);
			total += flags->dot;
			total += ft_put_width(flags->width, flags->zero, flags->dot);
		}
		else
		{
			write(1, str, ft_strlen(str));
			total += ft_strlen(str);
			total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
		}
	}
	else
	{
		write(1, str, ft_strlen(str));
		total += ft_strlen(str);
		total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
	}
	return (total);
}

int		put_str(char *str, t_flags *flags)
{
	int total;

	total = 0;
	if (flags->dot >= 0)
	{
		if (ft_strlen(str) >= flags->dot)
		{
			total += ft_put_width(flags->width, flags->zero, flags->dot);
			write(1, str, flags->dot);
			total += flags->dot;
		}
		else
		{
			total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
			write(1, str, ft_strlen(str));
			total += ft_strlen(str);
		}
	}
	else
	{
		total += ft_put_width(flags->width, flags->zero, ft_strlen(str));
		write(1, str, ft_strlen(str));
		total += ft_strlen(str);
	}
	return (total);
}
