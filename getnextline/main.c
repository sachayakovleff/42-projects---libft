#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(int *ac, char **argv)
{
	int	fd;
	char	*str;

	(void) ac;
	fd = open("42.txt", O_RDONLY);
	str = get_next_line(fd);
	printf(str);
	if (*str)
		free(str);
	str = get_next_line(fd);
	printf(str);
	if (*str)
		free(str);
	str = get_next_line(fd);
	printf(str);
	if (*str)
		free(str);
	
	close(fd);
	return (0);
}
