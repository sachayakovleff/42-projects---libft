/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:38:26 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/15 19:12:30 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_liste	*ra(t_liste *pile_a)
{
	t_liste	*newlist;

	if (pile_a->next == NULL)
		return (pile_a);
	newlist = pile_a->next;
	pile_a->next = NULL;
	newlist = addendlist(newlist, pile_a);
	return (newlist);
}

t_liste	*rb(t_liste *pile_b)
{
	t_liste	*newlist;

	if (pile_b->next == NULL)
		return (pile_b);
	newlist = pile_b->next;
	pile_b->next = NULL;
	newlist = addendlist(newlist, pile_b);
	return (newlist);
}

t_pile	rr(t_pile piles)
{
	piles.pile_a = ra(piles.pile_a);
	piles.pile_b = rb(piles.pile_b);
	return (piles);
}
