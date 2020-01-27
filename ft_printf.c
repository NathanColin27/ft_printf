/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/01/27 15:56:18 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		index_finder(char *tab, char elem)
{
	int index;

	index = 0;
	while (tab[index] != '\0')
	{
		if (tab[index] == elem)
			return (index);
		index++;
	}
	return (-1);
}

int check_str(char *str, va_list *arg_list)
{
	void (*tabFunction[9])(va_list *) = {print_c, print_s, print_d, print_x, print_up_x,print_d, print_p, print_u, print_percent};
	char *tabIndex;
	tabIndex = "csdxXipu%";
	
	int tmpIndex = 0;
	int i = 0;
	
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1])
		{
			tmpIndex = index_finder(tabIndex, str[i + 1]);
			if (tmpIndex != -1)
				(*tabFunction[tmpIndex])(arg_list);
		}
		i++;
	}
	return 0;
}

int ft_printf(const char *str,...)
{
	int total = 0;
	char *str_copy;
	va_list arg_list;
	str_copy = ft_strdup(str);

	va_start(arg_list, str);
	check_str(str_copy, &arg_list);
	va_end(arg_list);
	free(str_copy);
	return (total);
}




int main()
{
	printf("hello %% je suis le vrai printf\n");
	ft_printf("hello %% je suis moins bien \n");
}


