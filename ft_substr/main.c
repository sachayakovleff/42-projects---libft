#include <stdio.h>
#include <string.h>

char *ft_substr(char const *s, unsigned int start, size_t len);

int main(void)
{ 
	printf("returned: %s", ft_substr((const char *)"yoplaboule", 8, 4));
    return 0;
}