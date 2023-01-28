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

char	*ft_aeol(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			return (str);
		}
		str++;
	}
}

char	*ft_eol(char *str)
{
	int	index;
	char *result;

	index = 0;
	result = malloc(ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	while (str[index])
	{
		if (str[index] == '\n')
			return (result);
		result[index] = str[index];
		index++;
	}
	return (result);
}

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i++ < n)
		*str++ = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}
