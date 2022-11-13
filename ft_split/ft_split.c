/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:13:37 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/13 17:38:40 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	wordlen(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}

char	*wordcpy(char *dst, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_free(char **ret, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ret;

	if (s == NULL)
		return (NULL);
	if (!(ret = malloc((wordcount(s, c) + 2) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(ret[j] = malloc(((wordlen(&s[i], c) + 2)) * sizeof(char))))
				return (ft_free(ret, j));
			wordcpy(ret[j], &s[i], c);
			j++;
			i += wordlen(&s[i], c);
		}
		else
			i++;
	}
	ret[j] = NULL;
	return (ret);
}
