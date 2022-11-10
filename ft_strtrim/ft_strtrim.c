#include <string.h>
#include <stdlib.h>

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int ft_getsize2(const char *s1, const char *set, int length)
{
    int i;
    int j;

    j = 0;
    i = ft_strlen(s1) - 1;
    while (i >= 0)
    {
        if (set[j] == '\0')
            break;
        if (set[j] == s1[i])
        {
            length--;
            i--;
            j = -1;
        }
        j++;
    }
    return (length);
}

int ft_getsize(const char *s1, const char *set)
{
    int size;
    int i;
    int j;

    j = 0;
    i = 0;
    size = ft_strlen(s1);
    while (s1[i])
    {
        if (set[j] == '\0')
            break;
        if (set[j] == s1[i])
        {
            size--;
            i++;
            j = -1;
        }
        j++;
    }
    return (size);
}

char    *ft_setchar(const char *s1, const char *set, int length, char *str)
{
    int j;

    j = 0;
    while (*s1)
    {
        if (set[j] == '\0')
            break;
        if (set[j] == *s1)
        {
            s1++;
            j = -1;
        }
        j++;
    }
    j = 0;
    while (length--)
    {
        str[j] = *s1;
        s1++;
        j++;
    }
    str[j] = '\0';
    return (str);
}

char    *ft_strtrim(const char *s1,const char *set)
{
    int length;
    char    *str;

    length = ft_getsize(s1, set);
    length = ft_getsize2(s1, set, length);
    if (length <= 0)
        return (NULL);
    str = malloc (sizeof(char) * length + 1);
    if (str == NULL)
        return (NULL);
    str = ft_setchar(s1, set, length, str);
    return (str);
}