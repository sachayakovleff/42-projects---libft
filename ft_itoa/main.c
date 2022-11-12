#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

char *ft_itoa(int n);

int main(void)
{
    char    *str;
    int     i;

    i = 0;
    str = ft_itoa(-501);
    printf("res: %s\n",str);
    return 0;
}