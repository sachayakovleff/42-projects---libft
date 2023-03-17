/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:32:15 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/16 18:59:07 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	ft_order(t_pile piles, int num, int denum, int count)
{
	int	ll;

	ll = ft_getlistlength(piles.pile_a) + ft_getlistlength(piles.pile_b);
	while (count < ll * (num + 1) / denum)
	{
		if (piles.pile_a->rank <= ll * num / denum)
		{
			piles = pb(piles);
			piles.res = ft_strjoin(piles.res, "pb\n");
			count++;
		}
		else if (piles.pile_a->rank <= ll * (num + 1) / denum)
		{
			piles = pb(piles);
			piles.pile_b = rb(piles.pile_b);
			count++;
			piles.res = ft_strjoin(piles.res, "pb\nrb\n");
		}
		else
		{
			piles.pile_a = ra(piles.pile_a);
			piles.res = ft_strjoin(piles.res, "ra\n");
		}
	}
	return (piles);
}

t_pile	ft_order2(t_pile piles, int listlength, int num, int denum)
{
	while (piles.pile_a != NULL && piles.pile_a->next != NULL)
	{
		if (piles.pile_a->rank <= listlength * num / denum)
		{
			piles = pb(piles);
			piles.res = ft_strjoin(piles.res, "pb\n");
		}
		else if (piles.pile_a->rank != listlength)
		{
			piles = pb(piles);
			piles.pile_b = rb(piles.pile_b);
			piles.res = ft_strjoin(piles.res, "pb\nrb\n");
		}
		else
		{
			piles.pile_a = ra(piles.pile_a);
			piles.res = ft_strjoin(piles.res, "ra\n");
		}
	}
	return (piles);
}

t_pile	ft_swap5(t_pile piles)
{
	if (piles.pile_a->rank == 5)
	{
		piles.pile_a = ra(piles.pile_a);
		piles.res = ft_strjoin(piles.res, "ra\n");
	}
	while (piles.pile_b != NULL)
	{
		piles = getbestpile(piles);
		piles = pa(piles);
		piles.res = ft_strjoin(piles.res, "pa\n");
	}
	return (piles);
}

t_pile	ft_push3(t_pile piles)
{
	if (piles.pile_a->rank == 1)
	{
		piles = pb(piles);
		piles.pile_a = ra(piles.pile_a);
		piles = pa(piles);
		piles.res = ft_strjoin(piles.res, "pb\nra\npa\n");
	}
	else
	{
		piles.pile_a = ra(piles.pile_a);
		piles.res = ft_strjoin(piles.res, "ra\n");
	}
	return (piles);
}

t_pile	ft_rbrrb(t_pile piles, int nbrb, int nbrrb)
{
	if (nbrb >= nbrrb)
	{
		while (nbrrb > 0)
		{
			piles.pile_b = rrb(piles.pile_b);
			piles.res = ft_strjoin(piles.res, "rrb\n");
			nbrrb--;
		}
	}
	else
	{
		while (nbrb > 0)
		{
			piles.pile_b = rb(piles.pile_b);
			piles.res = ft_strjoin(piles.res, "rb\n");
			nbrb--;
		}
	}
	return (piles);
}
