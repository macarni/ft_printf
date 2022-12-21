/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:43:08 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/21 16:56:13 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	number_length(int number)
{
	int length;

	length = 1;
	if (number == -2147483648)
		return (11);
	if (number < 0)
	{	
		length++;
		number *=1; 
	}
	while(number > 9)
	{
		length++;
		number/=10;
	}
	return (length);
}

int	ft_print_number(int number)
{
	int length;
	
	length = number_length(number);
	if (number == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		number = 147483648;
	}
	if (number < 0)
	{
		ft_print_char('-');
		number *= -1;
	}
	if (number > 9)
	{
		ft_print_number(number/10);
		ft_print_number(number%10);
	}
	else 
		ft_print_char(number + 48);
	return(length);
}


int	ft_print_unsigned(unsigned int number)
{
	if (number == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		number = 147483648;
	}
	if (number < 0)
		number *= -1;
	return (ft_print_number(number));	
}
