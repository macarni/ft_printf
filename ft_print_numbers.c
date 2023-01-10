/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:43:08 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/10 13:15:46 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int number)
{
	int	length;

	length = 0;
	if (number == -2147483648)
	{
		length += ft_print_char('-');
		length += ft_print_char('2');
		number = 147483648;
	}
	if (number < 0)
	{
		ft_print_char('-');
		number *= -1;
		length++;
	}
	if (number > 9)
	{
		length += ft_print_number(number / 10);
		length += ft_print_number(number % 10);
	}
	else
		length += ft_print_char(number + 48);
	return (length);
}

int	ft_print_unsigned(unsigned int number)
{
	int	length;

	length = 0;
	if (number > 9)
	{
		length += ft_print_number(number / 10);
		length += ft_print_number(number % 10);
	}
	else
		length += ft_print_char(number + 48);
	return (length);
}

int	ft_print_hexa(unsigned int number, int base)
{
	int		length;
	char	*position;

	length = 0;
	if (base == 0)
		position = "0123456789abcdef";
	else
		position = "0123456789ABCDEF";
	if (number > 15)
	{
		length += ft_print_hexa(number / 16, base);
		length += ft_print_hexa(number % 16, base);
	}
	else
		length += ft_print_char(position[number]);
	return (length);
}

int	ft_print_pointer(unsigned long number)
{
	int		length;
	char	*position;

	length = 0;
	position = "0123456789abcdef";
	if (number <= 15)
	{
		length += ft_print_string("0x");
		length += ft_print_char(position[number]);
		return (length);
	}
	length += ft_print_pointer(number / 16);
	length += ft_print_char(position[number % 16]);
	return (length);
}
