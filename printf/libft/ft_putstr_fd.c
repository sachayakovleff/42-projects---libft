/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:20:46 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/24 17:20:50 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd, int *j)
{
	int	i;

	i = 0;
	if (!s || s == NULL)
	{
		write (fd, "(null)", 6);
		*j = *j + 6;
		return ;
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		*j = *j + 1;
		i++;
	}
}
