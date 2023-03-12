#include "../push_swap.h"

t_pile  ft_order(t_pile piles, int listlength, int num, int denum, int count)
{
    while (count < listlength * (num + 1) / denum)
    {
        if(piles.pile_a->rank <= listlength * num / denum)
        {
            piles = pb(piles);
            piles.res = ft_strjoin(piles.res, "pb\n");
            count++;
        }
        else if(piles.pile_a->rank <= listlength * (num + 1) / denum)
        {
            piles = pb(piles);
            piles.pile_b = rb(piles.pile_b);
            count++;
            piles.res = ft_strjoin(piles.res, "pb\nrb\n");
        }
        else
        {
            piles.pile_a = ra(piles.pile_a);
            piles.res = ft_strjoin(piles.res, "ra\n");
        }
    }
    return (piles);
}

t_pile  ft_order2(t_pile piles, int listlength, int num, int denum)
{
    while (piles.pile_a != NULL && piles.pile_a->next != NULL)
    {
        if (piles.pile_a->rank <= listlength*num/denum)
        {
            piles = pb(piles);
            piles.res = ft_strjoin(piles.res, "pb\n");
        }
        else if(piles.pile_a->rank != listlength)
        {
            piles = pb(piles);
            piles.pile_b = rb(piles.pile_b);
            piles.res = ft_strjoin(piles.res, "pb\nrb\n");
        }
        else
        {
            piles.pile_a = ra(piles.pile_a);
            piles.res = ft_strjoin(piles.res, "ra\n");
        }
    }
    return (piles);
}