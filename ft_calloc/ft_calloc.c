#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    char    *ptr;

    if (nmemb <= 0 || size <= 0)
        return (NULL);
    ptr = malloc(nmemb * size + 1);
    if (ptr == NULL)
        return (NULL);
    ft_bzero(ptr, size*nmemb);
    return (ptr);
}