#include "../push_swap.h"


t_liste	*ra(t_liste *pile_a)
{
	t_liste	*newlist;

	if (pile_a->next == NULL)
		return(pile_a);
	newlist = pile_a->next;
	pile_a->next = NULL;
	newlist = addendlist(newlist, pile_a);
	return (newlist);
}

t_liste	*rb(t_liste *pile_b)
{
	t_liste	*newlist;

	if(pile_b->next == NULL)
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