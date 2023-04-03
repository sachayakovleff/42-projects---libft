/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:25:21 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/16 18:58:52 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	ft_rbrrb(t_pile piles, int nbrb, int nbrrb);

t_pile	ft_fix(t_pile piles)
{
	if (piles.pile_a == NULL || piles.pile_b == NULL)
		return (piles);
	while (piles.pile_a->rank != 1)
	{
		piles = pb(piles);
		piles.res = ft_strjoin(piles.res, "pb\n");
	}
	while (piles.pile_a->rank < piles.pile_b->rank)
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

int	findnextpilerb(t_liste *pile_b, int rank)
{
	t_liste		*temp;
	int			count;

	temp = pile_b;
	count = 0;
	while (temp != NULL && temp->rank != rank)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_mustparb(t_pile piles)
{
	int	rank;

	rank = piles.pile_b->rank;
	while (piles.pile_b->rank != piles.pile_a->rank - 1)
	{
		if (rank == piles.pile_a->rank - 1)
			return (true);
		piles.pile_b = piles.pile_b->next;
		if (piles.pile_b->rank == rank + 1)
			rank = piles.pile_b->rank;
	}
	if (rank == piles.pile_a->rank - 2)
		return (true);
	else
		return (false);
}

t_pile	getbestpile(t_pile piles)
{
	int		nbrb;
	int		nbrrb;

	nbrb = 0;
	nbrrb = 0;
	if (piles.pile_b->rank == 1 && piles.pile_b->next != NULL
		&& piles.pile_b->next->next == NULL)
	{
		piles.pile_b = rb(piles.pile_b);
		piles.res = ft_strjoin(piles.res, "rb\n");
		return (piles);
	}
	if (piles.pile_a == NULL)
		return (piles);
	nbrb = findnextpilerb(piles.pile_b, piles.pile_a->rank - 1);
	nbrrb = ft_getlistlength(piles.pile_b) - nbrb;
	piles = ft_rbrrb(piles, nbrb, nbrrb);
	return (piles);
}
