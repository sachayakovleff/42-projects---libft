/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:20:42 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/24 16:07:44 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd, int *d)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putchar_fd('-', fd, d);
			ft_putchar_fd('2', fd, d);
			n = 147483648;
		}
		else
		{
			ft_putchar_fd('-', fd, d);
			n *= -1;
		}
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, d);
		ft_putnbr_fd(n % 10, fd, d);
	}
	else
		ft_putchar_fd(n + '0', fd, d);
}
