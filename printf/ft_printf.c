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
#include "libft/libft.h"
#include <limits.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_count(size_t nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbrbase(size_t nb)
{
	int		i;
	char	*str;
	const char	*hex = "0123456789abcdef";
	const int	length = ft_count(nb);

	i = length - 1;
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return ;
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--; 
	}
	str[length] = '\0';
	ft_putstr_fd(str, 1);
}

void	ft_putnbrbaseup(size_t nb)
{
	int		i;
	char	*str;
	const char	*hex = "0123456789ABCDEF";
	const int	length = ft_count(nb);

	i = length - 1;
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return ;
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--; 
	}
	str[length] = '\0';
	ft_putstr_fd(str, 1);
}


void	ft_getstring(char *str, va_list args)
{
	if (str[0] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[0] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (str[0] == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbrbase(va_arg(args, size_t));
	}
	else if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (str[0] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (str[0] == 'x')
		ft_putnbrbase(va_arg(args, unsigned int));
	else if (str[0] == 'X')
		ft_putnbrbaseup(va_arg(args, unsigned int));
	else if (str[0] == '%')
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
		if (str[i] == '%' && str[i + 1])
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
	ft_printf("yo je test si la %s fonctionne bien avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "fonction", 37502, 37502, 37502, (size_t)37502);
	printf("yo je test si la %s fonctionne bien avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "fonction", 37502, 37502, 37502, 37502);
	return (0);
}


int	main(void)
{
	ft_printf("yo je test si la %s fonctionne bien avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "fonction", 37502, 37502, 37502, (size_t)37502);
	printf("yo je test si la %s fonctionne bien avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "fonction", 37502, 37502, 37502, 37502);
	return (0);
}
