#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

int main(void)
{
	char	*str;

	str = "a";
	str = ft_strmapi(str, mapi_test);
	printf(str);
}