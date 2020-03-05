/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:03 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/05 16:19:25 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_star_flag(t_flags flags, va_list arg_list)
{
	flags.star = 1;
	flags.width = va_arg(arg_list, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_width_flag(t_flags flags, va_list arg_list, char *str)
{
	int i;
	i = 0;
	if (str[i] == '*')
	{
		flags.width = va_arg(arg_list, int);
		return (flags);
	}
	else
	{
		flags.width = 0;
		while (ft_isdigit(str[i]))
		{
			flags.width = flags.width * 10 + (str[i] - 48);
			i++;
		}
	}
	return (flags);
}

t_flags		ft_minus_flag(t_flags flags)
{
	flags.zero = 0;
	flags.minus = 1;
	return (flags);
}

int		ft_dot_flag(t_flags	*flags, va_list arg_list, char *str)
{
	int i;

	i = 0;
	if (*str == '*')
	{
		flags->dot = va_arg(arg_list, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(*str))
		{
			flags->dot = flags->dot * 10 + (*str - 48);
			str++;
			i++;
		}
	}
	return (i);
}
