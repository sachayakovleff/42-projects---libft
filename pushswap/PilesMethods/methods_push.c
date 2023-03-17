/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:38:31 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/17 14:05:42 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	pa(t_pile piles)
{
	t_liste	*tempb;

	if (piles.pile_b != NULL)
	{
		tempb = piles.pile_b;
		piles.pile_b = piles.pile_b->next;
		tempb->next = piles.pile_a;
		piles.pile_a = tempb;
	}
	return (piles);
}

t_pile	pb(t_pile piles)
{
	t_liste	*tempa;

	tempa = piles.pile_a;
	piles.pile_a = piles.pile_a->next;
	tempa->next = piles.pile_b;
	piles.pile_b = tempa;
	return (piles);
}
