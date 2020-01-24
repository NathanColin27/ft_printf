/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/24 14:14:51 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"





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

	printf ("%x\n",25);
	ft_printf("%x\n", 25);
}


