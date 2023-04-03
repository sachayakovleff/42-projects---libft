/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:02:46 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/17 02:18:41 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hasspace(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (true);
		str++;
	}
	return (false);
}

int	ft_isvalid(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((index == 0 && str[0] == '-') && ft_isdigit(str[1]))
			index++;
		else if (!ft_isdigit(str[index]) || ft_strlen(str) > 11)
			return (false);
		else
			index++;
	}
	return (true);
}

int	isinpile(t_pile piles, int result)
{
	t_liste	*temp;

	temp = piles.pile_a;
	while (temp != NULL)
	{
		if (temp->value == result)
			return (true);
		temp = temp->next;
	}
	return (false);
}

char	**ft_freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
