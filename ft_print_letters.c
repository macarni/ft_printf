/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:45 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/11 10:23:42 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_print_string(char *string)
{
	int	length;

	length = 0;
	if (!string)
		return (ft_print_string("(null)"));
	while (string[length])
	{
		ft_print_char(string[length]);
		length++;
	}
	return (length);
}
