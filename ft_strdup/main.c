#include <stdio.h>
#include <string.h>

char *ft_strdup(const char *s);

void	test(char *str)
{
	printf("%s",(ft_strdup(str)));
}

int main(void)
{ 
	test((char *)"salut");
    return 0;
}