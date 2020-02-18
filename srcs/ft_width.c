/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:37:51 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/18 11:14:56 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_put_width(int width, int zero, int printed)
{
	while(width > printed)
	{
		if(zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
	return 1;
}