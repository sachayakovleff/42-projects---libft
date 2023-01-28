#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 4

void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_setstr(char *new_str, char *buffer, char *second_buffer);
void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_aeol(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			return (str);
		}
		str++;
	}
}

char	*ft_eol(char *str)
{
	int	index;

	index = 0;
	while(str[index])
	{
		if (str[index] == '\n')
			while(str[index + 1])
			{
				str[index + 1] = 0; 
				index++;
			}
		index++;
	}
	printf("str:", str);
	return(str);
}

int		ft_hasEOL(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (true);
		index++;
	}
	return (false);
}

char	*ft_addchar(char *res, char *buffer, int count)
{
	char	*new_buffer;

	new_buffer = malloc(sizeof(char) * ((BUF_SIZE * count) + 1 ));
	if (new_buffer == NULL)
		return (NULL);
	ft_bzero(new_buffer, (BUF_SIZE * count) + 1);
	new_buffer = ft_strjoin(res, buffer);
	
	return(new_buffer);
}

char *ft_setbytes(int fd, int count)
{
	char	*byte_read;
	int		i;

	byte_read = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (byte_read == NULL)
		return (NULL);
	i = read(fd, byte_read, BUF_SIZE);
	if (i < 0)
		return (NULL);
	byte_read[BUF_SIZE] = 0;
	printf("valeur de byteread:%s\n", byte_read);
	return (byte_read);
}

char	*ft_read(int fd)
{
	char	*buffer;
	char	*res;
	int		count;

	count = 1;
	res = "";
	while(true)
	{
		buffer = ft_setbytes(fd, count);
		if (buffer == NULL)
			return (NULL);
		res = ft_addchar(res, buffer, count);
		if (ft_hasEOL(buffer))
			break;
		free(buffer);
		count++;
	}
	return (res);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*result;
	
	if(fd < 0 || BUF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd);
	printf("valeur de str: %s\n", str);
	result = ft_eol(str);
	return(result);
}