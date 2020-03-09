/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:53:45 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/09 11:55:51 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	ft_lenbase_p(unsigned long long value, int base)
{
	long l;

	l = 1;
	while (value >= base)
	{
		l++;
		value /= base;
	}
	return (l);
}

long	ft_lenbase(long long value, int base)
{
	long long l;

	l = 1;
	if (value < 0)
		value *= -1;
	while (value >= base)
	{
		l++;
		value /= base;
	}
	return (l);
}
