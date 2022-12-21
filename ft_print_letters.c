/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:45 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/21 15:36:39 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_print_string(char* string)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	while(string[i])
	{	
		ft_print_char(string[i]);
		i++;
		length++;
	}
	return (length);
}