/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/20 15:37:00 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_printf_number(va_list *arg_list)
{
	int num = va_arg(*arg_list, int);
	ft_putnbr_fd(num, 1);
}

void ft_printf_string(va_list *arg_list)
{
	char *str = va_arg(*arg_list, char *);

	write(1, str, ft_strlen(str));
}

void ft_printf_char(va_list *arg_list)
{
	char c = va_arg(*arg_list, int);

	write(1, &c, 1);
}

void decToHex(nbr){
	int base_len;
	char *base;
	
	base = "0123456789abcdef";
	base_len = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		printf("hello");
		decToHex(-nbr);
	}
	else if (nbr >= base_len)
	{	
		decToHex(nbr / base_len);
		decToHex(nbr % base_len);
	}
	ft_putchar(base[nbr]);
}

void decToHex_upper(nbr){
	int base_len;
	char *base;
	base = "0123456789ABCDEF";
	base_len = 16;
	
	if (nbr < 0)
	{
		ft_putchar('-');
		decToHex_upper(-nbr);
	}
	else if (nbr >= base_len)
	{
		decToHex_upper(nbr / base_len);
		decToHex_upper(nbr % base_len);
	}
	ft_putchar(base[nbr]);
}

void	ft_printf_decToHex(va_list *arg_list)
{
	int nbr;
	nbr = va_arg(*arg_list, int);
	decToHex(nbr);
}

void	ft_printf_decToHex_upper(va_list *arg_list)
{
	
	int nbr;
	nbr = va_arg(*arg_list, int);
	decToHex_upper(nbr);
}


int indexFinder(char *tab, char elem)
{
	int index;
	index = 0;

	while(tab[index] != '\0')
	{
		if (tab[index] == elem)
			return (index);
		index++;
	}
	return (-1);
}

int ft_printf(const char *str,...)
{
	void (*tabFunction[5]) (va_list *) = {ft_printf_char, ft_printf_string, ft_printf_number, ft_printf_decToHex, ft_printf_decToHex_upper};
	char tabIndex[10] = {'c', 's', 'd', 'x', 'X', 'p', 'i', 'u', '%', 0};
	int i = 0;
	int tmpIndex = 0;

	va_list arg_list;
	va_start(arg_list, str);
	while (str[i] != '\0')
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmpIndex = indexFinder(tabIndex, str[i]);
			if (tmpIndex != -1)
				(*tabFunction[tmpIndex]) (&arg_list);
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(arg_list);
	return 0;
}


int main()
{
	ft_printf("%x", -5);
}


