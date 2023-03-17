/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:26:49 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/17 01:59:08 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	ft_order(t_pile piles, int num, int denum, int count);
int		ft_countchar(char *str);
t_pile	ft_fix(t_pile piles);
t_pile	ft_order2(t_pile piles, int listlength, int num, int denum);
t_pile	ft_swap5(t_pile piles);
t_pile	ft_push3(t_pile piles);

t_pile	ft_pushswap(t_pile piles)
{
	while (piles.pile_b != NULL && piles.pile_b->next != NULL)
	{
		if (piles.pile_b->next != NULL)
			piles = getbestpile(piles);
		piles = pa(piles);
		piles.res = ft_strjoin(piles.res, "pa\n");
	}
	while (piles.pile_b != NULL)
	{
		piles = pa(piles);
		piles.res = ft_strjoin(piles.res, "pa\n");
	}
	if (!ft_issorted(piles.pile_a))
		piles = ft_fix(piles);
	return (piles);
}

t_pile	ft_pushswap3(t_pile piles)
{
	if (piles.pile_a->rank == 1 && piles.pile_a->next->rank == 2)
		return (piles);
	if (getendlist(piles.pile_a)->rank == 3)
	{
		piles.pile_a = sa(piles.pile_a);
		piles.res = ft_strjoin(piles.res, "sa\n");
	}
	else if (getendlist(piles.pile_a)->rank == 2)
		piles = ft_push3(piles);
	else
	{
		if (piles.pile_a->rank == 2)
		{
			piles.pile_a = rra(piles.pile_a);
			piles.res = ft_strjoin(piles.res, "rra\n");
		}
		else
		{
			piles.pile_a = sa(piles.pile_a);
			piles.pile_a = rra(piles.pile_a);
			piles.res = ft_strjoin(piles.res, "sa\nrra\n");
		}
	}
	return (piles);
}

t_pile	ft_pushswap5(t_pile piles)
{
	if (ft_issorted(piles.pile_a) && piles.pile_b == NULL)
		return (piles);
	while (piles.pile_a->next->next != NULL)
	{
		if (piles.pile_a->rank >= 4)
		{
			piles.pile_a = ra(piles.pile_a);
			piles.res = ft_strjoin(piles.res, "ra\n");
		}
		else
		{
			piles = pb(piles);
			piles.res = ft_strjoin(piles.res, "pb\n");
		}
	}
	piles = ft_swap5(piles);
	return (piles);
}

t_pile	ft_pushswap6(t_pile piles)
{
	int	listlength;
	int	count;

	count = 0;
	listlength = ft_getlistlength(piles.pile_a);
	piles = ft_order(piles, 1, 6, count);
	count = listlength / 3;
	piles = ft_order(piles, 3, 6, count);
	count = listlength * 2 / 3;
	piles = ft_order2(piles, listlength, 5, 6);
	return (piles = ft_pushswap(piles), piles);
}

t_pile	ft_pushswap16(t_pile piles)
{
	int	listlength;
	int	count;

	count = 0;
	listlength = ft_getlistlength(piles.pile_a);
	piles = ft_order(piles, 1, 16, count);
	count = listlength / 8;
	piles = ft_order(piles, 3, 16, count);
	count = listlength * 2 / 8;
	piles = ft_order(piles, 5, 16, count);
	count = listlength * 3 / 8;
	piles = ft_order(piles, 7, 16, count);
	count = listlength * 4 / 8;
	piles = ft_order(piles, 9, 16, count);
	count = listlength * 5 / 8;
	piles = ft_order(piles, 11, 16, count);
	count = listlength * 6 / 8;
	piles = ft_order(piles, 13, 16, count);
	piles = ft_order2(piles, listlength, 15, 16);
	return (piles = ft_pushswap(piles), piles);
}
