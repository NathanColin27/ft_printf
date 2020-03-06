/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/06 18:58:18 by ncolin           ###   ########.fr       */
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

void fill_tab(int (*functions_tab[9]) (va_list*, t_flags *flags))
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

int		ft_is_flag(char c)
{
	if (ft_strchr(FLAGS, c))
	{
		return (1);
	}
	return (0);
}

static t_flags			ft_initialize(void)
{
	t_flags	flags;

	flags.star = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int		ft_is_conv(char c){
	if (index_finder(c, CONVERTERS) == -1)
		return (0);
	return (1);
}

int		parse_flags(char *str, int i, t_flags *flags, va_list arg_list)
{
	while (str[i])
	{
		if (!ft_is_flag(str[i]) && !ft_is_conv(str[i]) && !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_star_flag(*flags, arg_list);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
		{
			i += ft_width_flag(flags, arg_list, &str[i]);
		}
		if (str[i] == '.')
		{
			i++;
			i += ft_dot_flag(flags, arg_list, &str[i]);
		}
		if (index_finder(str[i], CONVERTERS) != -1)
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}


int		check_str(char *str, va_list *arg_list, t_flags flags)
{
	int tmp_index;
	int total;
	int i;
	int (*functions_tab[9])(va_list*, t_flags *flags);

	tmp_index = 0;
	total = 0;
	i = 0;
	fill_tab(functions_tab);
	while (str[i] != '\0')
	{
		flags = ft_initialize();
		if (str[i] == '%' && str[i + 1])
		{
			i = parse_flags(str, ++i, &flags, *arg_list);
			tmp_index = index_finder(flags.type, CONVERTERS);
			if (tmp_index != -1)
				total += (*functions_tab[tmp_index])(arg_list, &flags);
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			total++;
		}
		i++;
	}

	return (total);
}

int		ft_printf(const char *str, ...)
{
	int		total;
	char	*str_copy;
	va_list	arg_list;
	t_flags flags;

	str_copy = ft_strdup(str);
	va_start(arg_list, str);
	total = check_str(str_copy, &arg_list, flags);
	va_end(arg_list);
	free(str_copy);
	return (total);
}

// int main()
// {	
// 	int a;
// 	ft_printf("1|ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10, -55, 1, -60);
// 	/////////////////	////////////////////////////////////////////////
// 	printf("2|ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10, -55, 1, -60);
// }
