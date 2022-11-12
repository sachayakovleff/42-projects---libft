#include <stdlib.h>
#include <string.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    int     i;

    i = 0;
    str = malloc(sizeof(char) * (strlen(s) + 1));
    while(s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}