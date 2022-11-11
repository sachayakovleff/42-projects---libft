#include <stdio.h>
#include <string.h>

char **ft_split(char const *s, char c);

int main(void)
{
    char    **array;
    int i;

    i = 0;
    array = ft_split("", '\0');
    return 0;
}