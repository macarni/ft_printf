/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:00:08 by adrperez          #+#    #+#             */
/*   Updated: 2023/01/10 15:14:39 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *string, ...);
int	ft_print_char(int character);
int	ft_print_string(char *string);
int	ft_print_number(int number);
int	ft_print_unsigned(unsigned int number);
int	ft_print_hexa(unsigned int number, int base);
int	ft_print_pointer(unsigned long number);

#endif