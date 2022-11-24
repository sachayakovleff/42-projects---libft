/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:03:38 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/19 16:29:29 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_printf(char *str, ...);

int	main(void)
{
	int	i;

	i = ft_printf("yo je test si la %s fonctionne bie%%n avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "", 2147483647, 37502, INT_MIN, (void *)37502);
	printf("valeur de i ma ft: %d\n", i);
	i = printf("yo je test si la %s fonctionne bie%%n avec les int comme %d, ecrit en hexa avec %x ou %X ou %p \n", "", 2147483647, 37502, INT_MIN, (void *)37502);
	printf("valeur de i vraie ft: %d\n", i);
	return (0);
}