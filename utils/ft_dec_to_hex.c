/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:00:18 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/10 08:59:50 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_dec_to_hex(long long nbr, char *base)
{
	int base_len;

	base_len = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_dec_to_hex(-nbr, base);
	}
	else if (nbr >= 16)
	{
		ft_dec_to_hex(nbr / base_len, base);
		ft_dec_to_hex(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

void		ft_dec_to_hex_p(unsigned long long nbr, char *base)
{
	int base_len;

	base_len = 16;
	if (nbr >= base_len)
	{
		ft_dec_to_hex_p(nbr / base_len, base);
		ft_dec_to_hex_p(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}
