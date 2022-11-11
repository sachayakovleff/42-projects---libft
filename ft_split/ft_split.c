#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     ft_count(const char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        if (s[i] == c)
        {
            count++;
            while(s[i] == c)
                i++;
        }
        i++;
    }
    if (s[strlen(s) - 1] == c)
        count--;
    if (s[0] == c)
        count--;
    return (count + 1);
}

int     ft_count2(const char *s, char c, int nb)
{
    int i;
    int count;
    int res;

    i = 0;
    res = 0;
    count = 0;
    if (s[0] == c)
        nb++;
    while (s[i])
    {
        if (s[i] == c)
        {
            count++;
            while(s[i] == c)
                i++;
        }
        if (s[i] != c && count == nb)
            res++;
        i++;
    }
    return (res);
}

void    ft_setchar(char *str, const char *s, char c, int nb, int k)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (s[0] == c)
        nb++;
    while (s[i])
    {
        if (s[i] == c)
        {
            count++;
            while(s[i] == c)
                i++;
        }
        if (s[i] != c && count == nb)
        {
            str[k] = s[i];
            k++;
        }
        i++;
    }
    str[k] = '\0';
}

char    **ft_cleararr(char **array, int length)
{
    int     i;

    i = 0;
    while(i < length)
    {
        free(array[i]);
        i++;
    }
    free(array);
    return (NULL);
}

char    **ft_split(const char *s, char c)
{
    char    **array;
    const int   length = ft_count(s, c);
    int     i;

    i = 0;
    array = malloc(sizeof(char *) * (length + 1));
    if (array == NULL)
        return (NULL);
    while (i < length)
    {
        array[i] = malloc(sizeof(char) * (ft_count2(s, c, i) + 1));
        if (array[i] == NULL)
            return (ft_cleararr(array, i));
        ft_setchar(array[i], s, c, i, 0);
        i++;
    }
    array[i] = malloc(sizeof(char));
    if (array[i] == NULL)
        return (NULL);
    array[i][0] = '\0';
    array[i] = NULL;
    return (array);
}