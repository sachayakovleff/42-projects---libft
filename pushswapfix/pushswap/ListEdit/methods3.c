/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:38:55 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:39 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_liste	*getendlist(t_liste *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_liste	*ft_setrank(t_liste *list, int min, int i)
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
	int	count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}
