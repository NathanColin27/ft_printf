/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:46:31 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/20 15:04:33 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printf_decToHex(long nbr)
{
	int base_len;
	char *base;
	base = "0123456789abcdef";
	base_len = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_printf_decToHex(-nbr);
	}
	else if (nbr >= base_len)
	{
		ft_printf_decToHex(nbr / base_len);
		ft_printf_decToHex(nbr % base_len);
	}
	ft_putchar(base[nbr]);
}
