/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:36:43 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/09 11:45:29 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_is_conv(char c)
{
	if (index_finder(c, CONVERTERS) == -1)
		return (0);
	return (1);
}

int		ft_is_flag(char c)
{
	if (ft_strchr(FLAGS, c))
		return (1);
	return (0);
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
