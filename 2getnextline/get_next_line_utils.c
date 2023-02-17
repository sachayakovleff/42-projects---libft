/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:42:43 by syakovle          #+#    #+#             */
/*   Updated: 2023/01/28 16:45:35 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	if (theString == NULL)
		return (i);
	while (theString[i])
		i++;
	return (i);
}

char	*ft_strjoins(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;
	const int	k = ft_strlen(s1);
	const int	l = ft_strlen(s2);

	str = malloc(sizeof(char) * (k + l + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < l)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s2);
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	const int	k = ft_strlen(s1);
	const int	l = ft_strlen(s2);

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < l)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (*s1)
		free(s1);
	return (str);
}
