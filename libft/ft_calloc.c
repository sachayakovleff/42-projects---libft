/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:40:59 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/18 12:37:08 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	taille;

	taille = nmemb * size;
	if (taille != 0 && nmemb * size / size != nmemb)
		return (NULL);
	result = malloc(taille);
	if (result)
		ft_bzero(result, taille);
	return (result);
}
