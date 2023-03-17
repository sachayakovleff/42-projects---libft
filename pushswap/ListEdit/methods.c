/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:38:19 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:14 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
