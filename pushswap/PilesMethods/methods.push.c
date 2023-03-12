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
