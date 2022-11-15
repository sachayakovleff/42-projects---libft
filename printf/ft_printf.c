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
#include "libft.h"

char	*ft_getstr(char *str, va_list args)
{
	
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	char	*s;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_putstr_fd(ft_getstr(str + i, args), 1);
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
