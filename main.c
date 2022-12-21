/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:58:32 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/21 16:45:30 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	char c_original = 'h';
	char c_mio = 'h';
	char* s_original = "hola";
	char* s_mio = "hola";
	int i_original = -2147483648;
	int i_mio = -2147483648;
	
	printf("Original: \n");
	printf("%d", printf("%d\n", i_original));
	
	printf("\n-----\n");
	
	printf("Mío: \n");
	printf("%d", ft_printf("%d\n", i_mio));
	
}