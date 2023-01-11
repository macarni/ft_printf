/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:59:37 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/11 12:00:51 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It takes a va_list and a char, and returns the number
 * of characters printed
 * 
 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %d Prints a decimal (base 10) number.
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %p The void * pointer argument has to be printed in hexadecimal format.
 * %% Prints a percent sign.
 * 
 * La macro va_arg simplemente devuelve un valor del tipo especificado en el segundo parámetro y mueve el puntero de lectura tantos bytes como el tamaño de este tipo
 * 
 * No se puede poner char en va_arg porque cualquier tipo más pequeño que un int 
 * (char, bool or short) a una función variadica, lo convierte a int
 * 
 * @param args This is the variable argument list.
 * @param type the type of argument to be printed
 * 
 * @return The number of characters printed.
 */
static int	ft_convert(va_list	args, char type)
{
	if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (type == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (type == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (type == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	if (type == 'x')
		return (ft_print_hexa(va_arg(args, unsigned int), 0));
	if (type == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), 1));
	if (type == '%')
		return (ft_print_char('%'));
	return (0);
}

/**
 * The function ft_printf() takes a string and a variable 
 * number of arguments, and prints the string
 * with the arguments inserted into it
 * 
 * @param string The string to be printed.
 * 
 * @return The length of the string.
 */
int	ft_printf(char const *string, ...)
{
	//Se definen los parámetros anónimos (...) de la función variadica
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	// va_start asigna el puntero de lectura al primer parámetro anónimo
	// Permite el acceso a los argumentos de las variables que siguen al 
	// último parámetro con nombre (string) --> sin él no se puede 
	// inicializar la referencia de parámetros anónimos.
	va_start(args, string);
	while (string[i])
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
	// Limpia cualquier recurso reservado por va_start y va_arg
	va_end(args);
	return (length);
}
