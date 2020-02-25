/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:42:22 by ncolin            #+#    #+#             */
/*   Updated: 2020/02/25 16:38:35 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_intlen(int value){
	int l;

	l = 1;
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}

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
		else if (str[i] == '*')
			*flags = ft_star_flag(*flags, arg_list);
		else if (str[i] == '0' && flags->width == 0)
			flags->zero = 1;
		else if (str[i] == '-')
		{
			flags->zero = 0;
			flags->minus = 1;
		}
		else if (ft_isdigit(str[i]))
			*flags = ft_width_flag(*flags, str[i]);
		else if (str[i] == '.')
		{
			*flags = ft_dot_flag(*flags, arg_list, &str[i + 1]);
			if (flags->dot != 0)
				i += ft_intlen(flags->dot);
		}
		else if (index_finder(str[i], CONVERTERS) != -1)
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}


int check_str(char *str, va_list *arg_list, t_flags flags)
{
	int tmpIndex = 0;
	int i = 0;
	char *copy;
	int (*functions_tab[9])(va_list*, t_flags *flags);
	fill_tab(functions_tab);

	copy = ft_strdup(str);

	while (str[i] != '\0')
	{
		flags = ft_initialize();
		if (str[i - 1] == '%' && str[i])
		{
			i = parse_flags(copy, i, &flags, *arg_list);
			tmpIndex = index_finder(flags.type, CONVERTERS);
			if (tmpIndex != -1)
			{
				(*functions_tab[tmpIndex])(arg_list, &flags);
				if (flags.type == '%' && str[i + 1] == '%')
					i++;
			}
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
	t_flags flags;

	total = 0;
	str_copy = ft_strdup(str);
	va_start(arg_list, str);
	check_str(str_copy, &arg_list, flags);
	va_end(arg_list);
	return (total);
}

int main()
{
	printf("Real Printf1 : %04.5d\n",-10);
	///////////////////////////////////////////////////////////////////
	ft_printf("My   Printf1 : %04.5d\n",-10);
}


