/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:45 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/10 13:11:49 by adrperez         ###   ########.fr       */
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
	int	i;

	i = 0;
	length = 0;
	if (!string)
		return (ft_print_string("(null)"));
	while (string[i])
	{
		ft_print_char(string[i]);
		i++;
		length++;
	}
	return (length);
}
