/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/05 17:33:34 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		index_finder(char elem, char *tab)
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

void fill_tab(void (*functions_tab[9]) (va_list*, t_flags *flags))
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

int		is_flag(char c)
{
	if(ft_strchr(FLAGS, c))
	{
		return (1);
	}
	return (0);
}

int parse_flags(char *str, int i, t_flags *flags)
{

	while(str[i])
	{
		if (!is_flag(str[i]) || index_finder(str[i], CONVERTERS) != -1)
			break;
		else if (str[i] == '.')
			flags->dot = 1;
		else if (str[i] == '*')
			flags->star = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		else if (str[i] == '-')
			flags->minus = 1;
		i++;
	}
	return (i);
	
}


int check_str(char *str, va_list *arg_list, t_flags my_flags)
{
	int tmpIndex = 0;
	int i = 0;
	char *copy;
	void (*functions_tab[9])(va_list*, t_flags *my_flags);
	fill_tab(functions_tab);

	copy = ft_strdup(str);
	while (str[i] != '\0')
	{
		if (str[i - 1] == '%' && str[i])
		{
			i = parse_flags(copy, i, &my_flags);
			tmpIndex = index_finder(str[i], CONVERTERS);
			if (tmpIndex != -1)
				(*functions_tab[tmpIndex])(arg_list, &my_flags);
			else
				write(1, &str[i], 1);
		}
		else if (str[i] != '%')
			write(1, &str[i], 1);
		i++;
	}
	free(copy);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	int		total;
	char	*str_copy;
	va_list	arg_list;
	t_flags my_flags;

	total = 0;
	str_copy = ft_strdup(str);
	va_start(arg_list, str);
	check_str(str_copy, &arg_list, my_flags);
	va_end(arg_list);
	return (total);
}

int main()
{
	char *str;

	printf("%%, %c, %s , %x, %X, %d, %i, %p, %u\n", 'a', " test", 33, 40, -153, 10000, str, 666);

	/////////////////////////////////////////////////////////////////////////////////////////////////

	ft_printf("%%, %c, %s , %x, %X, %d, %i, %p, %u\n", 'a', " test", 33, 40, -153, 10000, str, 666);
}


