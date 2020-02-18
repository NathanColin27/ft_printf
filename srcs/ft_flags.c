/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:03 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 11:47:27 by ncolin           ###   ########.fr       */
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
