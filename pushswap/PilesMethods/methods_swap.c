#include "../push_swap.h"


t_liste	*sa(t_liste *pa)
{
	t_liste	*temp;

	if (pa->next == NULL)
		return (pa);
	temp = pa->next;
	pa->next = temp->next;
	temp->next = pa;
	return (temp);
}

t_liste	*sb(t_liste *pa)
{
	t_liste	*temp;

	if (pa->next == NULL)
		return (pa);
	temp = pa->next;
	pa->next = temp->next;
	temp->next = pa;
	return (temp);
}

t_pile	ss(t_pile piles)
{
	piles.pile_a = sa(piles.pile_a);
	piles.pile_b = sb(piles.pile_b);
	return (piles);
}