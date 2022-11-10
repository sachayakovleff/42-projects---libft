#include <stdio.h>

char *ft_strtrim(const char *s1, const char *set);

int main(void)
{
    char *str;

    str = "";

    printf("valeur de la ft: %s", ft_strtrim((const char *)str, (const char *)"dqsdqd"));
}