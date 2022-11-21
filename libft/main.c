/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:32:28 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/18 15:56:22 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set);

int main(void)
{
    char    *str;

    str = ft_strtrim("   xxxtripouille   xxx", " x");
    if (str)
	printf("%s\n", str);
    if (str == NULL)
        return (0);
    if (str)
        free(str);
    return (0);
}
