#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int     ft_count(int n)
{
    int     res;

    res = 0;
    if (n < 0 && n != INT_MIN)
    {
        n *= -1;
        res++;
    }
    if (n == INT_MIN)
    {
        n = INT_MAX;
        res++;
    }
    while(n >= 10)
    {
        res++;
        n /= 10;
    }
    return (res + 1);
}

int     ft_unsign(int n)
{
    if (n == INT_MIN)
        n = INT_MAX;
    else
        n *= -1;
    return (n);
}

char    *ft_itoa(int n)
{
    char        *str;
    const unsigned int   length = ft_count(n);
    int         i;

    i = 0;
    str = malloc(sizeof(char) * (length + 1));
    if (str == NULL)
        return (str);
    if (n < 0)
    {
        n = ft_unsign(n);
        str[0] = '-';
    }
    if (n == 0)
        str[0] = '0';
    while (n > 0)
    {
        str[length - i-1] = n % 10 + '0';
        i++;
        n /= 10;
    }
    str[length] = '\0';
    return (str);
}