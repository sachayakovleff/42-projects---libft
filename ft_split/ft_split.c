#include <stdlib.h>
#include <stdio.h>

int ft_count(const char *s, char c, int *j)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while(s[i])
    {
        if (s[i] == c)
            count++;
        i++;
    }
    count++;
    *j = count;
    return (count+1);
}

int ft_count2(const char *s, char c, int arraynb)
{
    int j;
    int count;
    int res;

    j = 0;
    count = 0;
    res = 0;
    while(s[j] && count != arraynb)
    {
        if (s[j] == c)
            count++;
        j++;
    }
    while(s[j] && s[j] != c)
    {
        res++;
        j++;
    }
    printf("res: %d\n", res);
    return (res);
}

void    ft_setchar(char *str, const char *s, char c, int i)
{
    int j;
    int count;
    int k;

    j = 0;
    count = 0;
    k = 0;
    while (s[j] && count != i)
    {
        if (s[j] == c)
            count++;
        j++;
    }
    while (s[j] && s[j] != c && str[k])
    {
        str[k] = s[j];
        j++;
        k++;
    }
    str[k] = '\0';
}

char **ft_split(char const *s, char c)
{
    char    **array;
    int i;
    int j;

    i = 0;
    j = 0;
    array = malloc(sizeof(char *) * (ft_count(s, c, &i) + 1));
    if (array == NULL)
        return (NULL);
    while (j < i)
    {
        printf("coucouavant\n");
        if (j != 2)
        {
            array[j] == malloc(sizeof(char) * (ft_count2(s, c, j) + 1));
            printf("coucouapres\n");
            if (array[j] == NULL)
                return(NULL);
            ft_setchar(array[j], s, c, j);
            printf("str: %s\n", array[j]);
            j++;
        }
    }
    array[j] == NULL;
    return (array);
}