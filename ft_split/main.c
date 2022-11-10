#include <stdio.h>
#include <string.h>

char **ft_split(char const *s, char c);

int main(void)
{
    char    **array;
    int i;

    i = 0;
    array = ft_split((const char *)"Salutation", 'a');
	while (array[i])
    {
        printf("returned: %s", array[i]);
        i++;
    }
    return 0;
}