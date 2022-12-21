/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:59:37 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/21 16:51:04 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list	args, char type)
{
	if (type == 'c')
		return(ft_print_char(va_arg(args, int)));
	if (type == 's')
		return(ft_print_string(va_arg(args, char*)));
	if (type == 'd' || type == 'i')
		return(ft_print_number(va_arg(args, int)));
	if (type == 'u')
		return(ft_print_unsigned(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);

	while(string[i])
	{
		if (string[i] == '%')
		{
			i++;
			length += ft_convert(args, string[i]);
		}
		else
		{	
			length++;
			write(1, &string[i], 1);
		}
		i++;
	}
	
	va_end(args);
	return (length);
}