#include <string.h>
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    int i;

    if (!s)
        return (NULL);
    if (ft_strlen(s) - start >= len)
    {
        str = malloc (sizeof(char) * (len + 1));
        if (str == NULL)
            return (NULL);
    }
    else
    {
        str = malloc (sizeof(char) * (ft_strlen(s) - start + 1));
        if (str == NULL)
            return (NULL);
    }
    i = 0;
    while (s[i+start] && i < len)
    {
        str[i] = s[i + start];
        i++;
    }
    str[i] = '\0';
    return (str);
}