/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:14:05 by syakovle          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:41 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_liste
{
	int				value;
	int				rank;
	struct s_liste	*next;
}				t_liste;

typedef struct s_pile
{
	t_liste	*pile_a;
	t_liste	*pile_b;
	char	*res;
}				t_pile;

t_liste	*createlist(int x);
t_liste	*addhead(t_liste *list, int x);
t_liste	*addend(t_liste *list, int x);
t_liste	*createlistlist(t_liste *x);
t_liste	*addendlist(t_liste *list, t_liste *pile);
t_liste	*getendlist(t_liste *list);
t_liste	*clearlastlist(t_liste *list);
t_liste	*sa(t_liste *pa);
t_liste	*sb(t_liste *pa);
t_pile	ss(t_pile piles);
t_pile	pa(t_pile piles);
t_pile	pb(t_pile piles);
t_liste	*ra(t_liste *pile_a);
t_liste	*rb(t_liste *pile_b);
t_pile	rr(t_pile piles);
t_liste	*rra(t_liste *pile_a);
t_liste	*rrb(t_liste *pile_b);
t_pile	rrr(t_pile piles);
void	freepile(t_pile piles);
void	affichage(t_pile piles);
int		ft_issorted(t_liste *list);
t_liste	*ft_setrank(t_liste *list, int min, int i);
int		ft_getlistlength(t_liste *list);
t_pile	ft_pushswap3(t_pile piles);
t_pile	ft_pushswap5(t_pile piles);
t_pile	ft_pushswap16(t_pile piles);
t_pile	ft_pushswap6(t_pile piles);
t_pile	ft_pushswap8(t_pile piles);
t_pile	getbestpile(t_pile piles);

#endif