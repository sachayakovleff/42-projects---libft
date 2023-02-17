#define BUF_SIZE 100
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoins(char *s1, char *s2);
int		ft_strlen(char *theString);

int		ft_eol(char *buffer)
{
	while(*buffer)
	{
		if (*buffer == '\n')
		{	
			return (1);
		}	
		buffer++;
	}
	return (0);
}


char    *ft_read(int fd)
{
    char    *buffer;
	char	*result;
	int		i;

	result = "";
	while (true)
	{	
		buffer = malloc(sizeof(char) * (BUF_SIZE + 1));
		if (buffer == NULL)
			return (NULL);
		i = read(fd, buffer, BUF_SIZE);	
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUF_SIZE - (BUF_SIZE - i)] = 0;
		result = ft_strjoin(result, buffer);
		if (result == NULL)
			return (NULL);
		if (i == 0 || ft_eol(buffer))
		{
			free(buffer);	
			break ;
		}	
		free(buffer);
	}
	return (result);
}

char	*ft_getresult(char *saved_chars, char *read_line)
{
	int		index;
	char	*result;

	if (read_line == NULL)
		return (NULL);
	index = 0;
	while (read_line[index])
		index++;
	result = malloc(sizeof(char) * (index + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (read_line[index])
	{
		result[index] = read_line[index];
		if (read_line[index] == '\n')
			break ;
		index++;
	}
	result[index + 1] = 0;
	result = ft_strjoins(saved_chars, result);
	return (result);
}

char	*ft_getsavedchar(char *read_line)
{
	int		index;
	char	*saved_chars;
	int		index2;

	index = 1;
	index2 = 0;
	while (read_line[index] && read_line[index - 1] != '\n')
		index++;
	saved_chars = malloc(sizeof(char) * (ft_strlen(read_line) - index + 1));
	while (read_line[index])
	{
		saved_chars[index2] = read_line[index];
		index++;
		index2++;
	}
	saved_chars[index2] = 0;
	free(read_line);
	return (saved_chars);
}

char    *get_next_line(int fd)
{
    static char *saved_chars = "";
    char        *read_line;
    char        *returned_line;

    if (fd < 0 || BUF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if(ft_eol(saved_chars))
	{
		returned_line = ft_getresult("", saved_chars);
		saved_chars = ft_getsavedchar(saved_chars);
		return(returned_line);
	}
	read_line = ft_read(fd);
    if (saved_chars[0] == 0 && (read_line == NULL || (read_line[0] == 0)))
	{
		free(saved_chars);
		free(read_line);
        return (NULL);
	}
	if (!ft_eol(read_line) && read_line != NULL)
	{
		returned_line = ft_strjoins(saved_chars, read_line);
		saved_chars = malloc(1);
		saved_chars[0] = 0;
		return(returned_line);
	}
	returned_line = ft_getresult(saved_chars ,read_line);
	if (*saved_chars)
		free(saved_chars);
    saved_chars = ft_getsavedchar(read_line);
    return (returned_line);
}