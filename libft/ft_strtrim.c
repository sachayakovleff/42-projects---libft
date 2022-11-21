/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:42:54 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/18 15:58:53 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	ft_check(char s1, const char *set)
{
	int	i;

	i = 0;
	if (s1 == '\0')
		return (0);
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_only(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_check(s1[i], set))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_getstart(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (!ft_check(s1[i], set))
		i++;
	return (i);
}

int	ft_getlast(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (!ft_check(s1[i], set))
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const int	start = ft_getstart(s1, set);
	const int	end = ft_getlast(s1, set);
	char		*str;
	int			i;
	int			j;

	if (ft_only(s1, set))
		return (NULL);
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
