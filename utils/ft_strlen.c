/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:25:36 by ncolin            #+#    #+#             */
/*   Updated: 2020/03/07 19:50:47 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The strlen() function computes the length of the string s.
*/

size_t		ft_strlen(const char *str)
{
	size_t total;

	total = 0;
	while (*str)
	{
		total++;
		str++;
	}
	return (total);
}
