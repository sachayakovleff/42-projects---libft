#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_getwordlen(char const *s, char c)
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

size_t	ft_getarraylen(char const *s, char c)
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
			i += ft_getwordlen(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}

char	*ft_setword(char *str, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free(char **array, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_setstr(char **array, const char *s, char c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = malloc(((ft_getwordlen(&s[i], c) + 1)) * sizeof(char));
			if (array[j] == NULL)
            	return (ft_free(array, j));
			array[j] = ft_setword(array[j], &s[i], c);
			j++;
			i += ft_getwordlen(&s[i], c);
		}
		else
			i++;
	}
	array[j][0]; //si ca merde c'est la faute a puple
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = malloc((ft_getarraylen(s, c) + 1) * sizeof(char*));
    if (array == NULL)
		return (NULL);
    return (ft_setstr(array, s, c));	
}