/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:34:21 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/17 18:55:25 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
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

int	ft_putnbrbase(size_t nb)
{
	int		i;
	char	*str;
	const char	*hex = "0123456789abcdef";
	const int	length = ft_count(nb);

	i = length - 1;
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--; 
	}
	str[length] = '\0';
	return(ft_putstr_fd(str, 1));
}

int	ft_putnbrbaseup(size_t nb)
{
	int		i;
	char	*str;
	const char	*hex = "0123456789ABCDEF";
	const int	length = ft_count(nb);

	i = length - 1;
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	while (i >= 0)
	{
		str[i] = hex[nb % 16];
		nb /= 16;
		i--; 
	}
	str[length] = '\0';
	return(ft_putstr_fd(str, 1));
}


int	ft_getstring(char *str, va_list args)
{
	if (str[0] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (str[0] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (str[0] == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbrbase(va_arg(args, size_t)) + 2);
	}
	else if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (str[0] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (str[0] == 'x')
		return (ft_putnbrbase(va_arg(args, unsigned int)));
	else if (str[0] == 'X')
		return (ft_putnbrbaseup(va_arg(args, unsigned int)));
	else if (str[0] == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		ft_putchar_fd('%', 1) ;
		return (ft_putchar_fd(str[0], 1) + 1);
	}
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_getstring(str + i, args);
		}
		else
			ft_putchar_fd(str[i], 1);
			count++;
		i++;
	}
	return (count);
}

int	main(void)
{
	int	i;

	i = ft_printf("yo je test si la %s fonctionne bie%%n avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "", 2147483647, 37502, INT_MIN, (void *)37502);
	printf("valeur de i ma ft: %d\n", i);
	i = printf("yo je test si la %s fonctionne bie%%n avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "", 2147483647, 37502, INT_MIN, (void *)37502);
	printf("valeur de i vraie ft: %d\n", i);
	return (0);
}
