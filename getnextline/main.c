#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *get_next_line(int fd);

int main(void)
{
	//all tests
	int	fd;
	char	*str;

	fd = open("42.txt", O_RDONLY);
	while (true)
	{
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s\n", str);
		if (str != NULL)
			free(str);
		else
			return(0);
	}
	return (0);

	//test line by line
	/*
	int	fd;
	char	*str;

	fd = open("42.txt", O_RDONLY);
	str = get_next_line(fd);
	if (str != NULL)
		printf("%s\n", str);
	if (str != NULL && *str)
		free(str);
	return (0);
	*/
}
