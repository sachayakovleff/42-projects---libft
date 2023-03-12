#include "../push_swap.h"

t_liste	*createlist(int x)
{
	t_liste	*list;

	list = malloc(sizeof(t_liste));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	list->value = x;
	return (list);
}

t_liste	*addhead(t_liste *list, int x)
{
	t_liste	*temp;

	temp = createlist(x);
	if (temp == NULL)
		return (NULL);
	temp->next = list;
	return (temp);
}

t_liste	*addend(t_liste *list, int x)
{
	t_liste	*addedlist;
	t_liste	*newlist;

	if (list == NULL)
		return (addhead(list, x));
	addedlist = createlist(x);
	newlist = list;
	if (addedlist == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	list->next = addedlist;
	return (newlist);
}

t_liste	*createlistlist(t_liste *x)
{
	t_liste	*list;

	list = malloc(sizeof(t_liste));
	if (list == NULL)
		return (NULL);
	list = x;
	return (list);
}

t_liste	*addendlist(t_liste *list, t_liste *pile)
{
	t_liste	*newlist;

	newlist = list;
	while (list != NULL && list->next != NULL)
		list = list->next;
	if (list != NULL)
		list->next = pile;
	return (newlist);
}

t_liste	*getendlist(t_liste *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_liste *ft_setrank(t_liste *list, int min, int i)
{
	t_liste	*temp;

	temp = list;
	while (temp != NULL && temp->value != min)
		temp = temp->next;
	if (temp != NULL)
		temp->rank = i;
	return (list);
}
int	ft_getlistlength(t_liste *list)
{
	int count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return(count);
}