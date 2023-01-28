/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:42:36 by syakovle          #+#    #+#             */
/*   Updated: 2023/01/28 16:09:37 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 4

void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_setstr(char *new_str, char *buffer, char *second_buffer);
char	*ft_aeol(char *str);
char	*ft_eol(char *str);

int	ft_haseol(char *buffer)
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

	new_buffer = ft_strjoin(res, buffer);
	if (res != "")
		free(res);
	return (new_buffer);
}

char	*ft_setbytes(int fd, int count)
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
	//printf("valeur de i:%d\n", i);
	return (byte_read);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	char	*res;
	int		count;

	count = 1;
	res = "";
	while (true)
	{
		buffer = ft_setbytes(fd, count);
		if (!buffer)
			return (NULL);
		res = ft_addchar(res, buffer, count);
		if (ft_haseol(buffer))
		{
			free(buffer);
			break ;
		}
		free(buffer);
		count++;
	}
	if (str)
		free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*result;

	if (fd < 0 || BUF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	result = ft_eol(str);
	return (result);
}
