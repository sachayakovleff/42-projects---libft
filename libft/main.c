/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:50 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/16 17:07:58 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(const char *s1, const char *set);

void    main(void)
{
    printf(ft_strtrim((const char *)"salutastions", "s"));
}