/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/28 13:18:44 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		index_finder(char elem)
{
	int index;
	char *tab;

	tab = "csdxXipu%";
	index = 0;
	while (tab[index] != '\0')
	{
		if (tab[index] == elem)
			return (index);
		index++;
	}
	return (-1);
}

void fill_tab(void (*functions_tab[9]) (va_list*))
{
	functions_tab[0] = print_c;
	functions_tab[1] = print_s;
	functions_tab[2] = print_d;
	functions_tab[3] = print_x;
	functions_tab[4] = print_up_x;
	functions_tab[5] = print_d;
	functions_tab[6] = print_p;
	functions_tab[7] = print_u;
	functions_tab[8] = print_percent;
}


int check_str(char *str, va_list *arg_list)
{
	void (*functions_tab[9])(va_list*);
	fill_tab(functions_tab);

	int tmpIndex = 0;
	int i = 0;
	
	while (str[i] != '\0')
	{
		if (str[i - 1] == '%' && str[i])
		{
			tmpIndex = index_finder(str[i]);
			if (tmpIndex != -1)
				(*functions_tab[tmpIndex])(arg_list);
			else
				write(1, &str[i], 1);
		}
		else if (str[i] != '%')
			write(1, &str[i], 1);
		i++;
	}
	return 0;
}

int		ft_printf(const char *str, ...)
{
	int		total;
	char	*str_copy;
	va_list	arg_list;

	total = 0;
	str_copy = ft_strdup(str);
	va_start(arg_list, str);
	check_str(str_copy, &arg_list);
	va_end(arg_list);
	return (total);
}

int main()
{
	char *str;

	printf("%%, %c, %s , %x, %X, %d, %i, %p, %u\n", 'a', " test", 25, 25, -153, 10000, str, 666);
	ft_printf("%%, %c, %s , %x, %X, %d, %i, %p, %u\n", 'a', " test", 25, 25, -153, 10000, str, 666);
}


