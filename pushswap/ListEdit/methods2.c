#include "../push_swap.h"
#include <stdbool.h>

t_liste	*clearlastlist(t_liste *list)
{
	t_liste	*newlist;

	newlist = list;
	while (list->next->next != NULL)
		list = list->next;
	list->next = NULL;
	return (newlist);
}

t_liste	*free_all(t_liste *pile)
{
	t_liste	*nextlist;

	while (pile != NULL)
	{
		nextlist = pile->next;
		free(pile);
		pile = nextlist;
	}
	return (NULL);
}

void freepile(t_pile piles)
{
	if (piles.pile_a != NULL)
	{
		piles.pile_a = free_all(piles.pile_a);
	}
	if (piles.pile_b != NULL)
	{
		piles.pile_b = free_all(piles.pile_b);
	}
	free(piles.res);
}

void affichage(t_pile piles)
{
	t_liste	*temp;

	temp = piles.pile_a;
	ft_printf("================================\npilea:\n");
	while (temp != NULL)
	{
		ft_printf("value: %d ", temp->value);
		ft_printf("rank: %d\n", temp->rank);
		temp = temp->next;
	}
	ft_printf("================================\n");
	temp = piles.pile_b;
	ft_printf("================================\npileb:\n");
	while (temp != NULL)
	{
		ft_printf("value: %d ", temp->value);
		ft_printf("rank: %d\n ", temp->rank);
		temp = temp->next;
	}
	ft_printf("================================\n");
}

int	ft_issorted(t_liste *list)
{
	t_liste	*temp;

	temp = list;
	if (temp == NULL)
		return (0);
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}