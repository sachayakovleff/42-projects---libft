/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:34:21 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/15 15:15:44 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void	ft_getstring(char *str, va_list args)
{
	if (str[0] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (str[0] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	// if (str[0] == 'p') // à faire
		// return (va_arg(args, void *));
	if (str[0] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[0] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	// if (str[0] == 'x')
	// 	ft_tohexamin(va_arg(args, unsigned int));
	// if (str[0] == 'X')
	// 	ft_tohexamaj(va_arg(args, unsigned int));
	if (str[0] == '%')
		ft_putchar_fd('%', 1); 
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_getstring(str + i, args);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("Sa%station", "lut");
	return (0);
}
