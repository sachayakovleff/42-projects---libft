#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

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


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	taille;

	taille = nmemb * size;
	if (taille != 0 && nmemb * size / size != nmemb)
		return (NULL);
	result = malloc(taille);
	if (result)
		ft_bzero(result, taille);
	return (result);
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