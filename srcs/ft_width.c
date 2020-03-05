/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:37:51 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/05 14:07:53 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_put_width(int width, int zero, int printed)
{
	int total;
	total = 0;
	if (printed == -1)
		printed = 0;
	while (width > printed)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		total++;
	}
	return (total);
}
