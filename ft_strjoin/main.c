#include <stdio.h>
#include <string.h>

char *ft_strjoin(char const *s1, char const *s2);

int main(void)
{ 
	printf("returned: %s", ft_strjoin((const char *)"coucou", (const char *)""));
    return 0;
}