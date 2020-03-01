/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:03 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/01 18:03:28 by marvin           ###   ########.fr       */
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

t_flags		ft_width_flag(t_flags flags, char digit)
{
	flags.width = flags.width * 10 + (digit - 48);
	return (flags);
}

t_flags		ft_minus_flag(t_flags flags)
 {
 	flags.zero = 0;
	flags.minus = 1;
 	return (flags);
 }

t_flags	ft_dot_flag(t_flags	flags, va_list arg_list, char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
		flags.dot = va_arg(arg_list, int);
	else
	{
		flags.dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags.dot = flags.dot * 10 + (str[i] - 48);
			i++;
		}
	}
	return (flags);
}
