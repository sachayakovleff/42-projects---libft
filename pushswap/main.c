/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:49:13 by syakovle          #+#    #+#             */
/*   Updated: 2023/04/07 15:03:53 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include <stdbool.h>
#include <limits.h>

int		ft_hasspace(char *str);
int		ft_isvalid(char *str);
int		isinpile(t_pile piles, int result);
char	**ft_freearray(char **array);

t_pile	replacevalues(t_pile piles, int i, int min)
{
	t_liste		*temp;
	long int	lastmin;

	lastmin = (long int)(INT_MIN) - 1;
	temp = piles.pile_a;
	while (true)
	{
		temp = piles.pile_a;
		while (temp != NULL)
		{
			if (min > temp->value && temp->value > lastmin)
				min = temp->value;
			temp = temp->next;
		}
		i++;
		piles.pile_a = ft_setrank(piles.pile_a, min, i);
		if (lastmin != min)
			lastmin = min;
		else
			return (piles);
		min = INT_MAX;
	}
}

t_pile	ft_setpile(t_pile piles, int index, char **av)
{
	long long int	result;

	result = 0;
	while (av[index])
	{
		result = ft_atoi(av[index]);
		if (!ft_isvalid(av[index]) || result > INT_MAX || result < INT_MIN
			|| isinpile(piles, (int)result))
		{
			ft_printf("Error\n");
			freepile(piles);
			ft_freearray(av);
			exit(0);
		}
		piles.pile_a = addend(piles.pile_a, (int)result);
		index++;
	}
	return (piles);
}

t_pile	ft_createpiles(t_pile piles, char **av)
{
	int				i;
	char			**values;

	if (av[1][0] && !av[1][1] && !av[2])
		exit(0);
	i = 1;
	piles.pile_a = NULL;
	piles.pile_b = NULL;
	piles.res = malloc(sizeof(char));
	piles.res[0] = 0;
	while (av[i])
	{
		values = ft_split(av[i], ' ');
		piles = ft_setpile(piles, 0, values);
		ft_freearray(values);
		i++;
	}
	piles = replacevalues(piles, 0, INT_MAX);
	return (piles);
}

int	ft_countchar(char *str)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			count++;
		index++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_pile	piles;

	if (ac < 2 || av[1][0] == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	piles = ft_createpiles(piles, av);
	if (piles.pile_a == NULL)
	{
		ft_printf("Error\n");
		freepile(piles);
		exit(0);
	}
	if (ft_getlistlength(piles.pile_a) <= 3)
		piles = ft_pushswap3(piles);
	else if (ft_getlistlength(piles.pile_a) == 5)
		piles = ft_pushswap5(piles);
	else if (!ft_issorted(piles.pile_a) && ft_getlistlength(piles.pile_a) < 200)
		piles = ft_pushswap6(piles);
	else
		piles = ft_pushswap16(piles);
	ft_printf(piles.res);
	freepile(piles);
	return (0);
}
