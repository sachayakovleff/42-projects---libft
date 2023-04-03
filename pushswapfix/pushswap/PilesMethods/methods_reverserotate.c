/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_reverserotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:38:24 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/15 19:11:50 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_liste	*rra(t_liste *pile_a)
{
	t_liste	*newlist;

	newlist = getendlist(pile_a);
	pile_a = clearlastlist(pile_a);
	newlist->next = pile_a;
	return (newlist);
}

t_liste	*rrb(t_liste *pile_b)
{
	t_liste	*newlist;

	newlist = getendlist(pile_b);
	pile_b = clearlastlist(pile_b);
	newlist->next = pile_b;
	return (newlist);
}

t_pile	rrr(t_pile piles)
{
	piles.pile_a = rra(piles.pile_a);
	piles.pile_b = rrb(piles.pile_b);
	return (piles);
}
