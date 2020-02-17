/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:37:51 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/17 14:48:27 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_width(int width, int zero)
{
	while(width > 0)
	{
		if(zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
	return 1;
}