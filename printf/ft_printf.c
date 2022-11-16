/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:34:21 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/16 15:07:39 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int	ft_getlength(size_t s)
{
	int	count;

	count = 0;
	while (s > 0)
	{
		count++;
		s /= 10;
	}
	return (count);
}

char	*ft_tohexamin(size_t s)
{
	char		*str;
	int			i;
	const int	length = ft_getlength(s);

	i = 0;
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = ft_getchar(s, i);
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_getstring(char *str, va_list args)
{
	if (str[0] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (str[0] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (str[0] == 'p')
		ft_putstr_fd((char *)va_arg(args, void *), 1);
	if (str[0] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[0] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	if (str[0] == 'x')
		ft_putstr_fd(ft_tohexamin(va_arg(args, unsigned int)), 1);
	if (str[0] == 'X')
		ft_putstr_fd(ft_tohexamaj(va_arg(args, unsigned int)), 1);
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
