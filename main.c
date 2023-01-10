/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:58:32 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/10 12:59:07 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"


int	main(void)
{
	int i = -2147483648;
	unsigned int u = -2147483648;
	int x = -214748;
	char p = '1';
	
	printf("\nOriginal: \n");
	printf("%i", printf("%u\n", u));
	printf("\nMío: \n");
	printf("%i", ft_printf("%u\n", u));
	
	printf("\n-----");

	printf("\nOriginal: \n");
	printf("%i", printf("%i\n", i));
	printf("\nMío: \n");
	printf("%i", ft_printf("%i\n", i));

	printf("\n-----");

	printf("\nOriginal: \n");
	printf("%i", printf("%x\n", x));
	printf("\nMío: \n");
	printf("%i", ft_printf("%x\n", x));

	printf("\n-----");

	printf("\nOriginal: \n");
	printf("%i", printf("%%\n"));
	printf("\nMío: \n");
	printf("%i", ft_printf("%%\n"));

	printf("\n-----");

	printf("\nOriginal: \n");
	printf("%i", printf("%p\n", &p));
	printf("\nMío: \n");
	printf("%i", ft_printf("%p\n", &p));
	
	printf("\n-----");

	printf("\nOriginal: \n");
	printf("%i", printf("NULL %s NULL\n", NULL));
	printf("\nMío: \n");
	printf("%i", ft_printf("NULL %s NULL\n", NULL));
	
}